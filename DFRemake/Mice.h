// Mice Header
#pragma once
#include "Object.h"
#include "EventCollision.h"

class Mice : public df::Object {
private:
	// true if the mouse is sticky (hit by glue trap), false otherwise
	bool sticky;

	// timer for when the mouse is sticky
	int sticky_timer;

	// timer for when the mouse is travelling backward
	int reversed_timer;

	int curr_path;

	int health;

	float speedmod;

	// keeps track of the direction of the mouse. 1 is forward, -1 is backward
	int direction;

	const float normal_hv = 0.25;
	const float normal_vv = 0.075;

	// horizontal and vertical velocities of the mouse, respectively
	float hv;
	float vv;

	void out();

	// private function that handles step events for the mice
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