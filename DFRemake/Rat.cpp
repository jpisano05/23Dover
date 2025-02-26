#include "Rat.h"
#include "EventStep.h"
#include "Vector.h"
#include "DisplayManager.h"
#include "Color.h"
#include "Vector.h"
#include "LogManager.h"
#include "ResourceManager.h"

using namespace df;

//Constructor
Rat::Rat() {
	//Set Object Type
	setType("Rat");

	//Set sprite
	setSprite("bullet");

	//Set solidness
	setSolidness(HARD);

	//Set start position
	Vector p = Vector(7,7);

	p.setX(7);

	LM.writeLog("p x is %f", p.getX());
	setPosition(p);

	setVelocity(df::Vector(1, 1));

	LM.writeLog("X is: %f", getPosition().getX());

	Object::Object();
}

//Destructor
Rat::~Rat() {

}

int Rat::eventHandler(const df::Event* p_e) {
	//Handle step
	if (p_e->getType() == "step") {
		LM.writeLog("Running rat step");
		return 1;
	}
	else if (p_e->getType() == "out") {
		LM.writeLog("Rat out");
		setPosition(df::Vector(0, 0));
		return 1;
	}
	else if (p_e->getType() == "df::collision") {
		LM.writeLog("Collision");
		RM.getSound("pipe")->play(false);
		return 1;
	}

	return 0;
}

//Override draw
int Rat::draw() {
	LM.writeLog("Trying to draw at (%f, %f)", getPosition().getX(), getPosition().getY());
	return Object::draw();
}