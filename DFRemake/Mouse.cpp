// Mouse Source

#include "Mouse.h"

Mouse::Mouse() {
	health = 1;

	// set the sprite and type
	setSprite("mouse-right");
	setType("Mouse");

	// set starting location
	setPosition({-2, 2});
	
	// set starting velocity
	setVelocity({1, 0 });

	curr_path = 1;
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
	// NOTE: HORIZONTAL VELOCITY SHOULD BE 0.25 AND VERTICAL VELOCITY SHOULD BE .075 WHEN RELEASED

	// check for traps

	// check for change of direction

	if (curr_path == 1 && getPosition().getX() >= 75) {
		setSprite("mouse-down");
		setVelocity({ 0, 1});
		curr_path++;
	}

	else if (curr_path == 2 && getPosition().getY() >= 11) {
		setSprite("mouse-left");
		setVelocity({-1, 0 });
		curr_path++;
	}

	else if (curr_path == 3 && getPosition().getX() <= 50) {
		setSprite("mouse-up");
		setVelocity({0, -1});
		curr_path++;
	}

	else if (curr_path == 4 && getPosition().getY() <= 5) {
		setSprite("mouse-left");
		setVelocity({ -1, 0 });
		curr_path++;
	}

	else if (curr_path == 5 && getPosition().getX() <= 5) {
		setSprite("mouse-down");
		setVelocity({0, 1 });
		curr_path++;
	}

	else if (curr_path == 6 && getPosition().getY() >= 16) {
		setSprite("mouse-right");
		setVelocity({1, 0 });
		curr_path++;
	}

	else if (curr_path == 7 && getPosition().getX() >= 12) {
		setSprite("mouse-up");
		setVelocity({0, -1 });
		curr_path++;
	}

	else if (curr_path == 8 && getPosition().getY() <= 8) {
		setSprite("mouse-right");
		setVelocity({ 1, 0 });
		curr_path++;
	}

	else if (curr_path == 9 && getPosition().getX() >= 35) {
		setSprite("mouse-down");
		setVelocity({0, 1});
		curr_path++;
	}

	else if (curr_path == 10 && getPosition().getY() >= 14) {
		setSprite("mouse-right");
		setVelocity({1,0});
		curr_path++;
	}

}

//Setter/getter for health
void Mouse::setHealth(int newHealth) {
	health = newHealth;
}
int Mouse::getHealth() {
	return health;
}