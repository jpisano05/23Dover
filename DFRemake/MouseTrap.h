#pragma once
#include "Trap.h"

class MouseTrap : public Trap {
private:

public:
	//Constructor with defaults
	MouseTrap(df::Vector position, bool isGrabbed);

	//Override action
	void action() override;
};