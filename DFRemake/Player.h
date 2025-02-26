#pragma once

//includes
#include "Object.h"
#include "Event.h"
#include "EventKeyboard.h"

	//Start of class definition
class Player : public df::Object {
private:
	int move_cooldown = 3;
	int move_slowdown = 3;

public:
	//Constructor
	Player();

	//Override the event handler
	int eventHandler(const df::Event* p_e) override;

	//Destructor
	~Player();

	int draw() override;

	void step();
	
	void move(int dx, int dy);

	void kbd(const EventKeyboard* p_keyboard_event);
};

