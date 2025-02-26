#pragma once

//includes
#include "Object.h"
#include "Event.h"

	//Start of class definition
class Block : public df::Object {
private:

public:
	//Constructor
	Block();

	//Override the event handler
	int eventHandler(const df::Event* p_e) override;

	//Destructor
	~Block();

	int draw() override;
};

