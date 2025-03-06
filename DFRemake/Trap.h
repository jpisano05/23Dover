#pragma once

//Includes
#include "Object.h"
#include "Sprite.h"
#include <string.h>

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
	//Active frames
	int activeFrames;
	//aa
	int aa;

	bool spriteActive;

	//Hold sprite for mod
	std::string label;
public:
	//Override draw to draw range
	int draw() override;

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
	virtual void step();

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

	//Getter/setter for label
	void setLabel(std::string newLabel);
	std::string getLabel() const;
	
	//Getter/setter for active frames
	void setActive(int newActive);
	int getActive() const;
	//Getter/setter for aa
	void setAA(int newAA);
	int getAA() const;

	void setSpriteActive(bool newActive);
	bool getSpriteActive();
};