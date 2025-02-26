#pragma once
#include "Block.h"
#include "EventStep.h"
#include "Vector.h"
#include "DisplayManager.h"
#include "Color.h"
#include "Vector.h"
#include "LogManager.h"

using namespace df;

//Constructor
Block::Block() {
	//Set Object Type
	setType("Block");

	//Set solidness
	setSolidness(SPECTRAL);

	setSprite("saucer");

	//Set altitude
	setAltitude(0);

	//Set start position
	Vector p = Vector(7, 7);

	p.setX(7);

	LM.writeLog("p x is %f", p.getX());
	setPosition(p);

	LM.writeLog("X is: %f", getPosition().getX());
}

//Destructor
Block::~Block() {

}

int Block::eventHandler(const df::Event* p_e) {
	//Handle step
	if (p_e->getType() == "step") {
		return 1;
	}

	return 0;
}

//Override draw
int Block::draw() {
	LM.writeLog("Trying to draw at (%f, %f)", getPosition().getX(), getPosition().getY());
	return Object::draw();
}