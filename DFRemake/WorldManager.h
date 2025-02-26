#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__
#define WM df::WorldManager::getInstance()

//includes
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "Manager.h"
#include "ObjectList.h"
#include "Box.h"

//Namespace def
namespace df {

	//Start of class definition
	class WorldManager : public Manager {
	private:
		//Constructor
		WorldManager();
		//Prevent copies
		WorldManager(WorldManager const&);
		//Prevent assignment
		void operator=(WorldManager const&);

		//Objects to update
		ObjectList m_updates;
		//Objects to delete
		ObjectList m_deletions;

		//World Boundary
		Box boundary;
		//Player view
		Box view;

		//Object view is following
		Object* p_view_following;
	public:
		//Get the only instance of the WorldManager
		static WorldManager& getInstance() {
			static WorldManager instance;
			return instance;
		};

		//Start the WorldManager
		int startUp();

		//Shutdown the WorldManager
		void shutDown();

		//Insert Object into the world
		//0 ok, -1 error
		int insertObject(Object* p_o);

		//Remove Object from world
		//0 ok, -1 error
		int removeObject(Object* p_o);

		//Return list of all objects in world
		ObjectList getAllObjects() const;

		//Return list of all objects in world of type
		ObjectList objectsOfType(std::string type) const;

		//Update world and delete needed objects
		void update();

		//Mark an obkect to be deleted at end of the current loop
		//0 ok, -1 error
		int markForDelete(Object* p_o);

		//Draw all objects
		void draw();

		//Return list of Objects collided with at position 'where'
		//Only counts solid objects
		ObjectList getCollisions(const Object* p_o, Vector where);

		//Move Object considering collision
		int moveObject(Object* p_o, Vector where);

		//Getter/setter for boundary
		void setBoundary(Box new_boundary);
		Box getBoundary() const;
		//Getter/setter for View
		void setView(Box new_view);
		Box getView() const;

		//Convert world position to view position
		Vector worldToView(Vector world_pos);
		Vector viewToWorld(Vector view_pos);

		//Set view position
		void setViewPosition(Vector view_pos);
		//Set view following
		int setViewFollowing(Object* p_new_view_following);
	};

}

#endif __WORLD_MANAGER_H__