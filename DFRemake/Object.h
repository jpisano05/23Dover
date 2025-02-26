#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

//includes
#include <stdlib.h>
#include "Vector.h"
#include <string>
#include "Event.h"
#include "Animation.h"
#include "Box.h"

static int id_counter = 0;
const int MAX_ALTITUDE = 4;

enum Solidness {
	HARD, //Causes collisions and impedes
	SOFT, //Causes collisions but doesn't impede
	SPECTRAL, //Doesn't cause collisions
};

//Namespace def
namespace df {

	//Start of class definition
	class Object {
	private:
		//Stores the id of the object
		int m_id;
		//Stores the type of the object
		std::string m_type;
		//Stores the 2 dimensional position of the object
		Vector m_position;
		//0 to MAX supported
		int m_altitude;

		//Direction vector
		Vector m_direction;
		//Speed in direction
		float m_speed;

		//Solidness of the object
		Solidness m_solidness;

		//Animation
		Animation m_animation;

		//Box for sprite boundary & collisions
		Box m_box;

	public:
		//Draw method
		virtual int draw();

		//Constructor
		Object();

		//Destructor
		virtual ~Object();

		//Setter/Getter for id
		void setId(int new_id);
		int getId() const;

		//Setter/Getter for type
		void setType(std::string new_type);
		std::string getType() const;

		//Setter/Getter for position
		void setPosition(Vector new_pos);
		Vector getPosition() const;

		//Setter/Getter for Altitude
		int setAltitude(int new_altitude);
		int getAltitude() const;

		//Event Handler
		//0 if ignored, 1 if handled
		virtual int eventHandler(const Event* p_e);

		//Setter/getter for Speed
		void setSpeed(float speed);
		float getSpeed() const;

		//Setter/getter for Direction
		void setDirection(Vector new_direction);
		Vector getDirection() const;

		//Setter/getter for Velocity (Speed + direction)
		void setVelocity(Vector new_velocity);
		Vector getVelocity() const;

		//Predict the object's position next step
		Vector predictPosition();

		//Setter/getter for solidness
		int setSolidness(Solidness new_solid);
		Solidness getSolidness() const;

		//If Hard or Soft true, if Spectral false
		bool isSolid() const;

		//Set sprite to be animated
		int setSprite(std::string sprite_label);

		//Setter/getter for animation
		void setAnimation(Animation new_animation);
		Animation getAnimation() const;

		//Setter/getter for boundary box
		void setBox(Box new_box);
		Box getBox() const;

		//Convert relative bounding Box for Object to absolute world Box
		Box getWorldBox() const;
		Box getWorldBox(Vector where) const;
	};
}

#endif __OBJECT_H__