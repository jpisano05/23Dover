// Mice Source

#include "Mice.h"

Mice::Mice() {
	health = 1;

	// set the sprite and type
	setSprite("Mice-right");
	setType("Mice");

	// set starting location
	setPosition({-2, 2});
	
	// set starting velocity
	setVelocity({1, 0 });

	curr_path = 1;
}

Mice::~Mice() {
	
}

int Mice::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "step") {
		step();
		return 0;
	}

	return -1;
}

void Mice::step() {
	// NOTE: HORIZONTAL VELOCITY SHOULD BE 0.25 AND VERTICAL VELOCITY SHOULD BE .075 WHEN RELEASED

	// check for traps

	// check for change of direction

	if (curr_path == 1 && getPosition().getX() >= 75) {
		setSprite("Mice-down");
		setVelocity({ 0, 1});
		curr_path++;
	}

	else if (curr_path == 2 && getPosition().getY() >= 13) {
		setSprite("Mice-left");
		setVelocity({-1, 0 });
		curr_path++;
	}

	else if (curr_path == 3 && getPosition().getX() <= 45) {
		setSprite("Mice-up");
		setVelocity({0, -1});
		curr_path++;
	}

	else if (curr_path == 4 && getPosition().getY() <= 6) {
		setSprite("Mice-left");
		setVelocity({ -1, 0 });
		curr_path++;
	}

	else if (curr_path == 5 && getPosition().getX() <= 5) {
		setSprite("Mice-down");
		setVelocity({0, 1 });
		curr_path++;
	}

	else if (curr_path == 6 && getPosition().getY() >= 17) {
		setSprite("Mice-right");
		setVelocity({1, 0 });
		curr_path++;
	}

	else if (curr_path == 7 && getPosition().getX() >= 16) {
		setSprite("Mice-up");
		setVelocity({0, -1 });
		curr_path++;
	}

	else if (curr_path == 8 && getPosition().getY() <= 10) {
		setSprite("Mice-right");
		setVelocity({ 1, 0 });
		curr_path++;
	}

	else if (curr_path == 9 && getPosition().getX() >= 33) {
		setSprite("Mice-down");
		setVelocity({0, 1});
		curr_path++;
	}

	else if (curr_path == 10 && getPosition().getY() >= 16) {
		setSprite("Mice-right");
		setVelocity({1,0});
		curr_path++;
	}

}

//Setter/getter for health
void Mice::setHealth(int newHealth) {
	health = newHealth;
}
int Mice::getHealth() {
	return health;
}