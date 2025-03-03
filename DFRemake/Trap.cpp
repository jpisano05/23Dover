//Includes
#include "Trap.h"
#include "Vector.h"
#include "InputManager.h"
#include "LogManager.h"
#include "DisplayManager.h"
#include "EventMouse.h"
#include "ObjectList.h"
#include "WorldManager.h"

//Constructor
Trap::Trap() {
	cooldown = 3;
	cc = 0;
	range = 0;
	damage = 0;
	grabbed = false;

}

//Constructor with preset positon
Trap::Trap(df::Vector position) {

	cooldown = 3;
	cc = 0;
	range = 0;
	damage = 0;
	grabbed = false;

	setPosition(position);
}

Trap::Trap(df::Vector position, int cooldown, int cc, int range, int damage) {
	setPosition(position);

	this->cooldown = cooldown;
	this->cc = cc;
	this->range = range;
	this->damage = damage;
	grabbed = false;
}

int Trap::draw()  {
	int store = getAnimation().draw(getPosition());
	if (grabbed) {
		for (int i = 1; i < range / df::WINDOW_HP_TO_HC; i++) {
			DM.drawCh(df::Vector(getPosition().getX() + i, getPosition().getY()), '-', df::RED);
			DM.drawCh(df::Vector(getPosition().getX() - i, getPosition().getY()), '-', df::RED);
		}
		for (int i = 1; i < range / df::WINDOW_VP_TO_VC; i++) {
			DM.drawCh(df::Vector(getPosition().getX(), getPosition().getY() + i), '|', df::RED);
			DM.drawCh(df::Vector(getPosition().getX(), getPosition().getY() - i), '|', df::RED);
		}
	}
	return store;
}

//Override the event handler
int Trap::eventHandler(const df::Event* p_e) {
	//Handle step
	if (p_e->getType() == "step") {
		step();
		return 1;
	}
	if (p_e->getType() == MSE_EVENT) {
		const df::EventMouse* p_mouse_event = dynamic_cast<const df::EventMouse*> (p_e);
		if (p_mouse_event->getMouseAction() == df::CLICKED) {
			onClick();
		}
		return 1;
	}

	return 0;
}

void Trap::onClick() {
	if (grabbed) {
		df::ObjectList collisions = WM.getCollisions(this, getPosition());

		if (collisions.isEmpty()) {
			grabbed = false;
		}
	}
}

//On step
void Trap::step() {
	if (grabbed) {
		LM.writeLog("Grabbed, moving to: (%f, %f)", DM.pixelsToSpaces(*IM.getMousePos()).getX(), DM.pixelsToSpaces(*IM.getMousePos()).getY());
		setPosition(DM.pixelsToSpaces(*IM.getMousePos()));
		return;
	}

	if (cc != 0) {
		cc--;
		return;
	}

	//Do action
	action();


	cc = cooldown;
}

void Trap::action() {

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

//Setter/getter for grabbed
void Trap::setGrabbed(bool newGrabbed) {
	grabbed = newGrabbed;
}
bool Trap::getGrabbed() const {
	return grabbed;
}