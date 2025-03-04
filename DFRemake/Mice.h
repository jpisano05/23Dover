// Mice Header
#pragma once
#include "Object.h"
#include "EventCollision.h"

class Mice : public df::Object {
private:

	int curr_path;

	int health;

	float speedmod;

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
};