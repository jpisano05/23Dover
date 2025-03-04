// Mice Source

#include "Mice.h"
#include "ScoreManager.h"
#include "WorldManager.h"
#include "LogManager.h"

Mice::Mice() {
	health = 1;

	// set the sprite and type
	setSprite("mouse-right");
	setType("mouse");

	setSolidness(SPECTRAL);

	// set starting location
	setPosition({-2, 2});
	
	hv = .25;
	vv = .075;

	direction = 1;

	// set starting velocity
	setVelocity({hv, 0});

	setAltitude(4);

	sticky = false;

	curr_path = 1;

	speedmod = 1;
}

Mice::~Mice() {
	LM.writeLog("Mouse killed");
	SM.setPoints(SM.getPoints() + 10);
}

int Mice::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == "step") {
		step();
		return 0;
	}
	if (p_e->getType() == "out") {
		out();
		return 0;
	}

	return -1;
}

void Mice::step() {
	// NOTE: HORIZONTAL VELOCITY SHOULD BE 0.25 AND VERTICAL VELOCITY SHOULD BE .075 WHEN RELEASED

	//hv = 0.25 * speedmod;
	//vv = 0.075 * speedmod;

	hv *= speedmod;
	vv *= speedmod;

	if (health <= 0) {
		WM.markForDelete(this);
		return;
	}

	if (sticky) {
		setVelocity(df::Vector(hv, vv));
		sticky = false;
	}

	// check for traps

	// check for turn based on direction
	if (direction == 1) {
		checkForward();
	}
	else if(direction == -1){
		checkBackward();
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
	SM.setHealth(SM.getHealth() - 10);
}

//Setter/getter for speed mod
void Mice::setSpeedMod(float newMod) {
	speedmod = newMod;
}
float Mice::getSpeedMod() const  {
	return speedmod;
}

// setter for sticky variable
void Mice::setSticky(bool new_sticky) {
	sticky = new_sticky;
}

void Mice::reversePath() {
	direction = -1;
	hv *= direction;
	vv *= direction;
	if (getVelocity().getX() != 0) {
		setVelocity(df::Vector(hv, 0));
	}
	else {
		setVelocity(df::Vector(0, vv));
	}

	if (getVelocity().getX() > 0) {
		setSprite("mouse-right");
	}
	else if (getVelocity().getX() < 0) {
		setSprite("mouse-left");
	}
	else if (getVelocity().getY() > 0) {
		setSprite("mouse-down");
	}
	else if (getVelocity().getY() < 0){
		setSprite("mouse-up");
	}
}

void Mice::checkForward() {
	// check for change of direction
	if (curr_path == 1 && getPosition().getX() >= 74.5) {
		setSprite("mouse-down");
		setVelocity({ 0, vv });
		curr_path++;
	}

	else if (curr_path == 2 && getPosition().getY() >= 12) {
		setSprite("mouse-left");
		setVelocity({ -hv, 0 });
		curr_path++;
	}

	else if (curr_path == 3 && getPosition().getX() <= 45.5) {
		setSprite("mouse-up");
		setVelocity({ 0, -vv });
		curr_path++;
	}

	else if (curr_path == 4 && getPosition().getY() <= 5) {
		setSprite("mouse-left");
		setVelocity({ -hv, 0 });
		curr_path++;
	}

	else if (curr_path == 5 && getPosition().getX() <= 5.5) {
		setSprite("mouse-down");
		setVelocity({ 0, vv });
		curr_path++;
	}

	else if (curr_path == 6 && getPosition().getY() >= 17) {
		setSprite("mouse-right");
		setVelocity({ hv, 0 });
		curr_path++;
	}

	else if (curr_path == 7 && getPosition().getX() >= 14.5) {
		setSprite("mouse-up");
		setVelocity({ 0, -vv });
		curr_path++;
	}

	else if (curr_path == 8 && getPosition().getY() <= 9) {
		setSprite("mouse-right");
		setVelocity({ hv, 0 });
		curr_path++;
	}

	else if (curr_path == 9 && getPosition().getX() >= 32.5) {
		setSprite("mouse-down");
		setVelocity({ 0, vv });
		curr_path++;
	}

	else if (curr_path == 10 && getPosition().getY() >= 16) {
		setSprite("mouse-right");
		setVelocity({ hv,0 });
		curr_path++;
	}
}

void Mice::checkBackward() {

	if (curr_path == 2 && getPosition().getY() <= 2) {
		setSprite("mouse-right");
		setVelocity({ hv, 0 });
		curr_path--;
	}

	else if (curr_path == 3 && getPosition().getX() >= 74.5) {
		setSprite("mouse-up");
		setVelocity({ 0, -vv });
		curr_path++;
	}

	else if (curr_path == 4 && getPosition().getY() >= 12) {
		setSprite("mouse-left");
		setVelocity({ -hv, 0 });
		curr_path++;
	}

	else if (curr_path == 5 && getPosition().getX() <= 45.5) {
		setSprite("mouse-down");
		setVelocity({ 0, vv });
		curr_path++;
	}

	else if (curr_path == 6 && getPosition().getY() >= 17) {
		setSprite("mouse-right");
		setVelocity({ hv, 0 });
		curr_path++;
	}

	else if (curr_path == 7 && getPosition().getX() >= 14.5) {
		setSprite("mouse-up");
		setVelocity({ 0, -vv });
		curr_path++;
	}

	else if (curr_path == 8 && getPosition().getY() <= 9) {
		setSprite("mouse-right");
		setVelocity({ hv, 0 });
		curr_path++;
	}

	else if (curr_path == 9 && getPosition().getX() >= 32.5) {
		setSprite("mouse-down");
		setVelocity({ 0, vv });
		curr_path++;
	}

	else if (curr_path == 10 && getPosition().getY() >= 16) {
		setSprite("mouse-right");
		setVelocity({ hv,0 });
		curr_path++;
	}
}