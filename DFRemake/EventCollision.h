#pragma once

//Includes
#include "Event.h"
#include "Object.h"

const std::string COLLISION_EVENT = "df::collision";

using namespace df;

class EventCollision : public Event {
	private:
		//Location of the collision
		Vector m_pos;
		//Object causing the collsiion
		Object* m_p_obj1;
		//Object collided with
		Object* m_p_obj2;

	public:
		//Constructor
		EventCollision();

		//Constructor with inputs for objects and position
		EventCollision(Object* p_o1, Object* p_o2, Vector p);

		//Setter/getter for object that caused collision
		void setObject1(Object* p_new_o1);
		Object* getObject1() const;

		//Setter/getter for object that was collided with
		void setObject2(Object* p_new_o2);
		Object* getObject2() const;

		//Setter/getter for position
		void setPosition(Vector new_pos);
		Vector getPosition() const;
};