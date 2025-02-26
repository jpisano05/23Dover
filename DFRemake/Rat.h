#pragma once

//includes
#include "Object.h"
#include "Event.h"

	//Start of class definition
	class Rat : public df::Object {
	private:
		
	public:
		//Constructor
		Rat();

		//Override the event handler
		int eventHandler(const df::Event* p_e) override;

		//Destructor
		~Rat();

		int draw() override;
	};

