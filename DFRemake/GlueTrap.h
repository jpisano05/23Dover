#pragma once
#include "Trap.h"

class GlueTrap : public Trap {
private:

public:
	//Constructor with defaults
	GlueTrap(df::Vector position, bool isGrabbed);

	//Override action
	void action() override;
};