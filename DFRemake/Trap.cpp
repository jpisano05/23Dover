//Includes
#include "Trap.h"
#include "Vector.h"

//Constructor
Trap::Trap() {
	cooldown = 3;
	cc = 0;
	range = 0;
	damage = 0;

	Object();
}

//Constructor with preset positon
Trap::Trap(df::Vector position) {

	cooldown = 3;
	cc = 0;
	range = 0;
	damage = 0;

	setPosition(position);
}

Trap::Trap(df::Vector position, int cooldown, int cc, int range, int damage) {
	setPosition(position);

	this->cooldown = cooldown;
	this->cc = cc;
	this->range = range;
	this->damage = damage;

	Object::Object();
}

//Override the event handler
int Trap::eventHandler(const df::Event* p_e) {
	//Handle step
	if (p_e->getType() == "step") {
		step();
		return 1;
	}

	return 0;
}

//On step
void Trap::step() {
	if (cc != 0) {
		cc--;
		return;
	}

	//Do action

	cc = cooldown;
}

//Setter/getter for range
void Trap::setRange(int newRange) {
	range = newRange;
}
int Trap::getRange() const {
	return range;
}

//Setter/getter for damage
void Trap::setDamage(int newDamage) {
	damage = newDamage;
}
int Trap::getDamage() const {
	return damage;
}

//Setter/getter for cooldown
void Trap::setCooldown(int newCooldown) {
	cooldown = newCooldown;
}
int Trap::getCooldown() const {
	return cooldown;
}

//Setter/getter for cc
void Trap::setCC(int newCC) {
	cc = newCC;
}
int Trap::getCC() const {
	return cc;
}