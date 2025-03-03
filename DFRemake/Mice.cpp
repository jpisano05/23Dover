// Mice Source

#include "Mice.h"
#include "ScoreManager.h"
#include "WorldManager.h"

Mice::Mice() {
	health = 1;

	// set the sprite and type
	setSprite("mouse-right");
	setType("mouse");

	setSolidness(SPECTRAL);

	// set starting location
	setPosition({-2, 2});
	
	// set starting velocity
	setVelocity({0.25, 0 });

	curr_path = 1;
}

Mice::~Mice() {
	SM.setPoints(SM.getPoints() + 10);
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

	float hv = 0.25;
	float vv = 0.075;

	if (health <= 0) {
		WM.markForDelete(this);
		return;
	}

	// check for traps

	// check for change of direction

	if (curr_path == 1 && getPosition().getX() >= 75) {
		setSprite("mouse-down");
		setVelocity({ 0, vv});
		curr_path++;
	}

	else if (curr_path == 2 && getPosition().getY() >= 13) {
		setSprite("mouse-left");
		setVelocity({-hv, 0 });
		curr_path++;
	}

	else if (curr_path == 3 && getPosition().getX() <= 45) {
		setSprite("mouse-up");
		setVelocity({0, -vv});
		curr_path++;
	}

	else if (curr_path == 4 && getPosition().getY() <= 6) {
		setSprite("mouse-left");
		setVelocity({ -hv, 0 });
		curr_path++;
	}

	else if (curr_path == 5 && getPosition().getX() <= 5) {
		setSprite("mouse-down");
		setVelocity({0, vv });
		curr_path++;
	}

	else if (curr_path == 6 && getPosition().getY() >= 17) {
		setSprite("mouse-right");
		setVelocity({hv, 0 });
		curr_path++;
	}

	else if (curr_path == 7 && getPosition().getX() >= 16) {
		setSprite("mouse-up");
		setVelocity({0, -vv });
		curr_path++;
	}

	else if (curr_path == 8 && getPosition().getY() <= 10) {
		setSprite("mouse-right");
		setVelocity({ hv, 0 });
		curr_path++;
	}

	else if (curr_path == 9 && getPosition().getX() >= 33) {
		setSprite("mouse-down");
		setVelocity({0, vv});
		curr_path++;
	}

	else if (curr_path == 10 && getPosition().getY() >= 16) {
		setSprite("mouse-right");
		setVelocity({hv,0});
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

void Mice::out() {

}