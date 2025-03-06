#pragma once
#include "Trap.h"

class MouseRepellent : public Trap {
private:

public:
	//Constructor with defaults
	MouseRepellent(df::Vector position, bool isGrabbed);

	//Override action
	void action() override;

	//On step
	void step() override;
};