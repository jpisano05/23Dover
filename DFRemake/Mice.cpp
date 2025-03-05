// Mice Source

#include "Mice.h"
#include "ScoreManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventStep.h"

Mice::Mice() {
	health = 1;

	// set the sprite and type
	setSprite("mouse-right");
	setType("mouse");

	setSolidness(SPECTRAL);

	// set starting location
	setPosition({-2, 2});
	
	hv = normal_hv;
	vv = 0;

	// here for testing:
	//hv = 1;
	//vv = .5;

	direction = 1;

	// set starting velocity
	setVelocity({hv, vv});

	setAltitude(4);

	sticky = false;

	sticky_timer = 0;

	reversed_timer = 0;

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
	if (sticky) {
		hv *= speedmod;
		vv *= speedmod;
		sticky = false;
		setVelocity(df::Vector(hv, vv));
	}

	if (health <= 0) {
		WM.markForDelete(this);
		return;
	}

	if (sticky_timer > 0) {
		sticky_timer--;
		if (sticky_timer == 0) {
			// do we let the glue trap stack slowness? No for now
			hv *= (1 / speedmod);
			vv *= (1 / speedmod);
			speedmod = 1;
			setVelocity(df::Vector(hv, vv));
		}
	}
	
	if (reversed_timer > 0) {
		reversed_timer--;
		if (reversed_timer == 0) {
			LM.writeLog("mouse repellent has worn off");
			reversePath();
		}
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
	if (curr_path == 10) {
		SM.setHealth(SM.getHealth() - 10);
		WM.markForDelete(this);
	}
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
	if (sticky) {
		sticky_timer = 150;
	}
}

void Mice::reversePath() {
	LM.writeLog("Mouse direction reversed");
	direction = -direction;
	hv *= -1;
	vv *= -1;
	if (direction == -1) {
		reversed_timer = 90;
	}
	setVelocity(df::Vector(hv, vv));

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
	// var to track if mouse turned
	bool turned = false;
	// check for change of direction
	if (curr_path == 1 && getPosition().getX() >= 74.5) {
		setSprite("mouse-down");
		//setVelocity({ 0, vv });
		hv = 0;
		vv = normal_vv;

		curr_path++;
		turned = true;
	}

	else if (curr_path == 2 && getPosition().getY() >= 12) {
		setSprite("mouse-left");
		//setVelocity({ -hv, 0 });
		hv = -normal_hv;
		vv = 0;
		curr_path++;
		turned = true;
	}

	else if (curr_path == 3 && getPosition().getX() <= 45.5) {
		setSprite("mouse-up");
		//setVelocity({ 0, -vv });
		hv = 0;
		vv = -normal_vv;
		curr_path++;
		turned = true;
	}

	else if (curr_path == 4 && getPosition().getY() <= 5) {
		setSprite("mouse-left");
		//setVelocity({ -hv, 0 });
		hv = -normal_hv;
		vv = 0;
		curr_path++;
		turned = true;
	}

	else if (curr_path == 5 && getPosition().getX() <= 5) {
		setSprite("mouse-down");
		//setVelocity({ 0, vv });
		hv = 0;
		vv = normal_vv;
		curr_path++;
		turned = true;
	}

	else if (curr_path == 6 && getPosition().getY() >= 17) {
		setSprite("mouse-right");
		//setVelocity({ hv, 0 });
		hv = normal_hv;
		vv = 0;
		curr_path++;
		turned = true;
	}

	else if (curr_path == 7 && getPosition().getX() >= 14.5) {
		setSprite("mouse-up");
		//setVelocity({ 0, -vv });
		hv = 0;
		vv = -normal_vv;
		curr_path++;
		turned = true;
	}

	else if (curr_path == 8 && getPosition().getY() <= 9) {
		setSprite("mouse-right");
		//setVelocity({ hv, 0 });
		hv = normal_hv;
		vv = 0;
		curr_path++;
		turned = true;
	}

	else if (curr_path == 9 && getPosition().getX() >= 32.5) {
		setSprite("mouse-down");
		//setVelocity({ 0, vv });
		hv = 0;
		vv = normal_vv;
		curr_path++;
		turned = true;
	}

	else if (curr_path == 10 && getPosition().getY() >= 16) {
		setSprite("mouse-right");
		//setVelocity({ hv,0 });
		hv = normal_hv;
		vv = 0;
		curr_path++;
		turned = true;
	}
	if (turned) {
		hv *= speedmod;
		vv *= speedmod;
		setVelocity(df::Vector(hv, vv));
	}
}

void Mice::checkBackward() {
	// var to track if mouse turned
	bool turned = false;

	if (curr_path == 2 && getPosition().getY() <= 2) {
		setSprite("mouse-left");
		//setVelocity({ hv, 0 });
		hv = -normal_hv;
		vv = 0;
		turned = true;
		curr_path--;
	}

	else if (curr_path == 3 && getPosition().getX() >= 74.5) {
		setSprite("mouse-up");
		//setVelocity({ 0, vv });
		hv = 0;
		vv = -normal_vv;
		curr_path--;
		turned = true;
	}

	else if (curr_path == 4 && getPosition().getY() >= 12) {
		setSprite("mouse-right");
		//setVelocity({ -hv, 0 });
		hv = normal_hv;
		vv = 0;
		curr_path--;
		turned = true;
	}

	else if (curr_path == 5 && getPosition().getX() >= 45.5) {
		setSprite("mouse-down");
		//setVelocity({ 0, 0.075 });
		hv = 0;
		vv = normal_vv;
		turned = true;
		curr_path--;
	}

	else if (curr_path == 6 && getPosition().getY() <= 5) {
		setSprite("mouse-right");
		//setVelocity({ 0.25, 0 });
		hv = -normal_hv;
		vv = 0;
		turned = true;
		curr_path--;
	}

	else if (curr_path == 7 && getPosition().getX() <= 5) {
		setSprite("mouse-up");
		//setVelocity({ 0, -0.075 });
		hv = 0;
		vv = -normal_vv;
		turned = true;
		curr_path--;
	}

	else if (curr_path == 8 && getPosition().getY() >= 17) {
		setSprite("mouse-left");
		//setVelocity({ -0.25, 0 });
		hv = -normal_hv;
		vv = 0;
		turned = true;
		curr_path--;
	}

	else if (curr_path == 9 && getPosition().getX() <= 14.5) {
		setSprite("mouse-down");
		//setVelocity({ 0, 0.075 });
		hv = 0;
		vv = normal_vv;
		turned = true;
		curr_path--;
	}

	else if (curr_path == 10 && getPosition().getY() <= 9) {
		setSprite("mouse-left");
		//setVelocity({-0.25,0 });
		hv = -normal_hv;
		vv = 0;
		turned = true;
		curr_path--;
	}
	else if (curr_path == 11 && getPosition().getX() <= 32.5) {
		setSprite("mouse-up");
		//setVelocity({ 0, -0.075 });
		hv = 0;
		vv = -normal_vv;
		turned = true;
		curr_path--;
	}
	if (turned) {
		hv *= speedmod;
		vv *= speedmod;
		setVelocity(df::Vector(hv, vv));
	}
}