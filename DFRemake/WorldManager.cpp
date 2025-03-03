//Includes
#include "WorldManager.h"
#include "LogManager.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "DisplayManager.h"
#include "ViewObject.h"
#include "Box.h"

using namespace df;

//Constructor
WorldManager::WorldManager() {

}

//Start the WorldManager
int WorldManager::startUp() {
	m_updates = ObjectList();
	m_deletions = ObjectList();

	return 0;
}

//Shutdown the WorldManager
void WorldManager::shutDown() {
	for (int i = 0; i < m_updates.getCount(); i++) {
		markForDelete(m_updates[i]);
	}

	for (int i = 0; i < m_deletions.getCount(); i++) {
		removeObject(m_deletions[i]);
	}
}

//Insert Object into the world
//0 ok, -1 error
int WorldManager::insertObject(Object* p_o) {
	return m_updates.insert(p_o);
}

//Remove Object from world
//0 ok, -1 error
int WorldManager::removeObject(Object* p_o) {
	m_deletions.remove(p_o);
	int out = m_updates.remove(p_o);
	return out;
}

//Return list of all objects in world
ObjectList WorldManager::getAllObjects() const {
	return m_updates;
}

//Return list of all objects in world of type
ObjectList WorldManager::objectsOfType(std::string type) const {
	ObjectList sublist = ObjectList();

	for (int i = 0; i < m_updates.getCount(); i++) {
		if (m_updates[i]->getType() == type) {
			sublist.insert(m_updates[i]);
		}
	}

	return sublist;
}

//Update world and delete needed objects
void WorldManager::update() {
	int t = m_deletions.getCount();

	//Update Objects based on their velocities
	for (int i = 0; i < m_updates.getCount(); i++) {
		Vector new_pos = m_updates[i]->predictPosition();

		if (!(new_pos == m_updates[i]->getPosition())) {
			//LM.writeLog("Should run moveObject");
			moveObject(m_updates[i], new_pos);
		}
	}

	//Delete objects in delete queue
	for (int i = t - 1; i > -1; i--) {
		//LM.writeLog("Counter: %d", m_deletions.getCount());
		delete(m_deletions[i]);
	}

	m_deletions.clear();
}

//Mark an object to be deleted at end of the current loop
//0 ok, -1 error
int WorldManager::markForDelete(Object* p_o) {
	return m_deletions.insert(p_o);
}

//Draw all objects
void WorldManager::draw() {
	for (int alt = 0; alt <= MAX_ALTITUDE; alt++) {
		for (int i = 0; i < m_updates.getCount(); i++) {
			if (m_updates[i]->getAltitude() == alt) {
				Box temp_box = m_updates[i]->getWorldBox();

				if (temp_box.boxIntersectsBox(view) || dynamic_cast<ViewObject *> (m_updates[i])) {
					m_updates[i]->draw();
				}
				else {;
				//LM.writeLog("View Corner: (%f, %f)", view.getCorner().getX(), view.getCorner().getY());
				//LM.writeLog("View Horizontal/Vertical: (%f, %f)", view.getHorizontal(), view.getVertical());
				}
			}
		}
	}
}

//Return list of Objects collided with at position 'where'
//Only counts solid objects
ObjectList WorldManager::getCollisions(const Object* p_o, Vector where) {
	ObjectList collisions;

	for (int i = 0; i < m_updates.getCount(); i++) {
		Object* p_temp = m_updates[i];

		if (p_temp != p_o) {
			Box b = p_o->getWorldBox(where);
			Box b_temp = p_temp->getWorldBox();
			if (b.boxIntersectsBox(b_temp) && p_temp->isSolid()) {
				//LM.writeLog("COLLISION FOUND ");
				collisions.insert(p_temp);
			}
		}
	}

	return collisions;
}

//Move Object considering collision
int WorldManager::moveObject(Object* p_o, Vector where) {
	if (p_o->isSolid()) {
		ObjectList list = getCollisions(p_o, where);

		if (!list.isEmpty()) {
			bool do_move = true;

			for (int i = 0; i < list.getCount(); i++) {
				Object* p_temp = list[i];

				EventCollision c(p_o, p_temp, where);

				p_o->eventHandler(&c);
				p_temp->eventHandler(&c);

				if (p_o->getSolidness() == HARD && p_temp->getSolidness() == HARD) {
					do_move = false;
				}
			}

			if (!do_move) {
				return -1;
			}
		}
	}

	Box orig_box = p_o->getWorldBox();
	p_o->setPosition(where);
	Box new_box = p_o->getWorldBox();

	if (orig_box.boxIntersectsBox(boundary) && !new_box.boxIntersectsBox(boundary)) {
		EventOut ov;
		p_o->eventHandler(&ov);
	}

	/*
	if ((where.getX() < 0 || where.getX() > DM.getHorizontal()) || ((where.getY() < 0) || (where.getY() > DM.getVertical()))) {
		LM.writeLog("Out of bounds");
		EventOut ov;
		p_o->eventHandler(&ov);
	}
	else {
		LM.writeLog("Not out: %f, %f, %f, %f", where.getX(), DM.getHorizontal(), where.getY(), DM.getVertical());
	}
	*/

	if (p_view_following == p_o) {
		setViewPosition(p_o->getPosition());
	}

	//LM.writeLog("Ran moveObject");

	return 0;
}

//Getter/setter for boundary
void WorldManager::setBoundary(Box new_boundary) {
	boundary = new_boundary;
}
Box df::WorldManager::getBoundary() const
{
	return boundary;
}
//Getter/setter for View
void WorldManager::setView(Box new_view) {
	view = new_view;
}
Box df::WorldManager::getView() const
{
	return view;
}

//Convert world position to view position
Vector WorldManager::worldToView(Vector world_pos) {
	Vector view_origin = getView().getCorner();
	float view_x = view_origin.getX();
	float view_y = view_origin.getY();
	Vector view_pos(world_pos.getX() - view_x, world_pos.getY() - view_y);
	return view_pos;
}

//Convert world position to view position
Vector WorldManager::viewToWorld(Vector view_pos) {
	Vector world_origin = getBoundary().getCorner();
	float world_x = world_origin.getX();
	float world_y = world_origin.getY();
	Vector world_pos(view_pos.getX() - world_x, view_pos.getY() - world_y);
	return world_pos;
}

//Set view position
void WorldManager::setViewPosition(Vector view_pos) {
	float x = view_pos.getX() - view.getHorizontal() / 2;
	if (x + view.getHorizontal() > boundary.getHorizontal()) {
		x = boundary.getHorizontal() - view.getHorizontal();
	}
	if (x < 0) {
		x = 0;
	}

	float y = view_pos.getY() - view.getVertical() / 2;
	if (y + view.getVertical() > boundary.getVertical()) {
		y = boundary.getVertical() - view.getVertical();
	}
	if (y < 0) {
		y = 0;
	}

	Vector new_corner(x, y);
	view.setCorner(new_corner);
	//LM.writeLog("New corner set at: %f, %f", new_corner.getX(), new_corner.getY());
}
//Set view following
int WorldManager::setViewFollowing(Object* p_new_view_following) {
	if (p_new_view_following == NULL) {
		p_view_following = NULL;
		return 0;
	}

	bool found = false;

	for (int i = 0; i < m_updates.getCount(); i++) {
		if (m_updates[i] == p_new_view_following) {
			found = true;
		}
	}

	if (found) {
		p_view_following = p_new_view_following;
		//LM.writeLog("trying to set view");
		setViewPosition(p_view_following->getPosition());
		//LM.writeLog("Found object and set view");
		return 0;
	}

	return -1;
}