// Mouse Source

#include "Mouse.h"

Mouse::Mouse() {
	health = 1;

	// set the sprite and type
	setSprite("mouse");
	setType("Mouse");

	// set starting location
	
	// set starting velocity
}

Mouse::~Mouse() {
	
}

int Mouse::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "step") {
		step();
		return 0;
	}

	return -1;
}

void Mouse::step() {
	// check for traps

	// check for change of direction
}

//Setter/getter for health
void Mouse::setHealth(int newHealth) {
	health = newHealth;
}
int Mouse::getHealth() {
	return health;
}