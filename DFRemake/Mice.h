// Mice Header
#pragma once
#include "Object.h"
#include "EventCollision.h"

class Mice : public df::Object {
private:
	bool sticky;

	int curr_path;

	int health;

	float speedmod;

	// keeps track of the direction of the mouse. 1 is forward, -1 is backward
	int direction;

	// horizontal and vertical velocities of the mouse, respectively
	float hv;
	float vv;

	void out();
	void step();
public:
	Mice();
	~Mice();
	int eventHandler(const df::Event* p_e) override;

	//Setter/getter for health
	void setHealth(int newHealth);
	int getHealth();

	//Setter/getter for speed mod
	void setSpeedMod(float newMod);
	float getSpeedMod() const;

	// setter for sticky
	void setSticky(bool new_sticky);

	// check if the mouse should turn
	void checkForward();
	void checkBackward();

	// reverse the direction the mouse is moving
	void reversePath();
};