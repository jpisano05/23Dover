#pragma once

//Includes
#include "Object.h"

class Trap : public df::Object {
private:
	//Length between actions
	int cooldown;
	//Current cooldown
	int cc;
	//Distance to damage
	int range;
	//Damage
	int damage;
	//Check if grabbed
	bool grabbed;
public:
	//Constructor
	Trap();

	//Constructor with preset positon
	Trap(df::Vector position);

	//Constructor with all preset
	Trap(df::Vector position, int cooldown, int cc, int range, int damage);

	//OVerride with the trap's actual mechanic
	virtual void action();

	//Override the event handler
	int eventHandler(const df::Event* p_e) override;

	//On step
	void step();

	//Setter/getter for range
	void setRange(int newRange);
	int getRange() const;

	//Setter/getter for damage
	void setDamage(int newDamage);
	int getDamage() const;

	//Setter/getter for cooldown
	void setCooldown(int newCooldown);
	int getCooldown() const;

	//Setter/getter for cc
	void setCC(int newCC);
	int getCC() const;

	//Setter/getter for grabbed
	void setGrabbed(bool newGrabbed);
	bool getGrabbed() const;

	//Handle when stuff is clicked
	void onClick();
};