#include "Player.h"
#include "EventStep.h"
#include "Vector.h"
#include "DisplayManager.h"
#include "Color.h"
#include "Vector.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "EventMouse.h"

using namespace df;

//Constructor
Player::Player() {
	//Set Object Type
	setType("Player");

	setSprite("mouse-left");

	//Set solidness
	setSolidness(HARD);

	//Set start position
	Vector p = Vector(25, 15);

	LM.writeLog("p x is %f", p.getX());
	setPosition(p);

	LM.writeLog("X is: %f", getPosition().getX());
}

//Destructor
Player::~Player() {

}

int Player::eventHandler(const df::Event* p_e) {
	//Handle step
	if (p_e->getType() == "step") {
		return 1;
	}
	if (p_e->getType() == KEYBOARD_EVENT) {
		LM.writeLog("Player attained a keyboard event");
		const EventKeyboard* p_keyboard_event = dynamic_cast <const EventKeyboard*> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}
	if (p_e->getType() == MSE_EVENT) {
		LM.writeLog("Player attained a mouse event");
		const EventMouse* p_mouse_event = dynamic_cast<const EventMouse*> (p_e);

		if (p_mouse_event->getMouseButton() == Mouse::LEFT) {
			WM.setViewFollowing(this);
		}
		return 1;
	}

	return 0;
}

//Handles what key does what action
void Player::kbd(const EventKeyboard* p_keyboard_event) {
	//Switch statement to handle various key presses
	switch (p_keyboard_event->getKey()) {
	case Keyboard::W: //up
		if (p_keyboard_event->getKeyboardAction() == KEY_PRESSED) {
			LM.writeLog("W pressed");
			move(0, -1);
		}
		break;

	case Keyboard::S: //down
		if (p_keyboard_event->getKeyboardAction() == KEY_PRESSED) {
			LM.writeLog("S pressed");
			move(0, +1);
		}
		break;
	case Keyboard::A: //left
		if (p_keyboard_event->getKeyboardAction() == KEY_PRESSED) {
			LM.writeLog("A pressed");
			move(-1, 0);
		}
		break;

	case Keyboard::D: //right
		if (p_keyboard_event->getKeyboardAction() == KEY_PRESSED) {
			LM.writeLog("D pressed");
			move(+1, 0);
		}
		break;
	}
}

//Override draw
int Player::draw() {
	LM.writeLog("Trying to draw at (%f, %f)", getPosition().getX(), getPosition().getY());
	return Object::draw();
}

void Player::step() {
	//move cooldown
	move_cooldown--;
	if (move_cooldown < 0) {
		move_cooldown = 0;
	}
}

//Moves the object
void Player::move(int dx, int dy) {
	LM.writeLog("Moving player");
	//Check that movement is off cooldown
	if (move_cooldown == 0) {
		return;
	}
	move_cooldown = move_slowdown;

	//if the move won't go offscreen allow it
	df::Vector new_pos(getPosition().getX() + dx, getPosition().getY() + dy);
	WM.moveObject(this, new_pos);
}