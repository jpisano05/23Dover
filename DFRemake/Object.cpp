#pragma once
//includes
#include "Object.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Box.h"

using namespace df;

//Constructor
Object::Object() {
	m_id = id_counter;
	id_counter++;
	m_type = "default";
	m_position = Vector();
	m_altitude = MAX_ALTITUDE / 2;
	m_solidness = HARD;
	m_box = Box(Vector(), 0, 0);

	//LM.writeLog("ID: %d", m_id);
	WM.insertObject(this);
}

//Destructor
Object::~Object() {
	WM.removeObject(this);
}

//Setter/Getter for id
void Object::setId(int new_id) {
	m_id = new_id;
}
int Object::getId() const {
	return m_id;
}

//Setter/Getter for type
void Object::setType(std::string new_type) {
	m_type = new_type;
}
std::string Object::getType() const {
	return m_type;
}

//Setter/Getter for position
void Object::setPosition(Vector new_pos) {
	m_position = new_pos;
}
Vector Object::getPosition() const {
	return m_position;
}

//Event Handler
//0 if ignored, 1 if handled
int Object::eventHandler(const Event* p_e) {
	return 0;
}

//Setter/Getter for Altitude

int Object::setAltitude(int new_altitude) {
	if (new_altitude >= MAX_ALTITUDE || new_altitude < 0) {
		return -1;
	}
	m_altitude = new_altitude;

	return 0;
}

int Object::getAltitude() const {
	return m_altitude;
}

//Setter/getter for Speed
void Object::setSpeed(float speed) {
	m_speed = speed;
}
float Object::getSpeed() const {
	return m_speed;
}

//Setter/getter for Direction
void Object::setDirection(Vector new_direction) {
	m_direction = new_direction;
}
Vector Object::getDirection() const {
	return m_direction;
}

//Setter/getter for Velocity (Speed + direction)
void Object::setVelocity(Vector new_velocity) {
	m_speed = new_velocity.getMagnitude();
	new_velocity.normalize();
	m_direction = new_velocity;
}
Vector Object::getVelocity() const {
	Vector dummy = Vector(m_direction);
	dummy.scale(m_speed);
	return dummy;
}

//Predict the object's position next step
Vector Object::predictPosition() {
	//Add Velocity to position
	Vector new_pos = m_position + getVelocity();

	return new_pos;
}

//Setter/getter for solidness
int Object::setSolidness(Solidness new_solid) {
	m_solidness = new_solid;
	return 0;
}
Solidness Object::getSolidness() const {
	return m_solidness;
}

//If Hard or Soft true, if Spectral false
bool Object::isSolid() const {
	if (m_solidness == HARD || m_solidness == SOFT) {
		return true ;
	}
	else {
		return false;
	}
}

//Set sprite to be animated
int Object::setSprite(std::string sprite_label) {
	df::Sprite* p_sprite = RM.getSprite(sprite_label);

	if (p_sprite == NULL) {
		return -1;
	}

	m_animation.setSprite(p_sprite);

	setBox(m_animation.getBox());

	return 0;
}

//Setter/getter for animation
void Object::setAnimation(Animation new_animation) {
	m_animation = new_animation;
}
Animation Object::getAnimation() const {
	return m_animation;
}

//Draw object animation
int Object::draw() {
	LM.writeLog("Drawing object of name/type: %s", getType().c_str());
	return m_animation.draw(m_position);
}

void Object::setBox(Box new_box) {
	m_box = new_box;
}

Box Object::getBox() const {
	return m_box;
}

//Convert relative bounding Box for Object to absolute world Box
Box Object::getWorldBox() const {
	return getWorldBox(getPosition());
}
Box Object::getWorldBox(Vector where) const {
	Box box = getBox();
	Vector corner = box.getCorner();
	corner.setX(corner.getX() + where.getX());
	corner.setY(corner.getY() + where.getY());
	box.setCorner(corner);
	return box;
}