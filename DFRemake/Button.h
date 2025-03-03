#pragma once

//includes
#include "Object.h"
#include "Event.h"
#include "EventMouse.h"


	//Start of class definition
class Button : public df::Object {
private:

public:
	//Constructor
	Button();

	//Override the event handler
	int eventHandler(const df::Event* p_e) override;

	//Check if clicked
	bool wasClicked(const df::EventMouse* m_e);

	//When clicked do
	virtual void onClicked();
};

