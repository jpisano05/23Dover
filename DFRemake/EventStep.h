#pragma once
#ifndef __EVENTSTEP_H__
#define __EVENTSTEP_H__

//Includes
#include "Event.h"

//Namespace def
namespace df {

	//Start of class definition
	class EventStep : public Event {

	private:
		//Iteration count
		int m_step_count;

	public:
		//Constructor
		EventStep();
		
		//Constructor with initial step input
		EventStep(int init_step_count);

		//Setter/Getter for step count
		void setStepCount(int new_step_count);
		int getStepCount() const;
	};
}

#endif __EVENTSTEP_H__