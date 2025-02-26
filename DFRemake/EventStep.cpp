#pragma once

#include "EventStep.h"

using namespace df;

//Constructor
EventStep::EventStep() {
	m_step_count = 0;
	setType("step");
}

//Constructor with initial step input
EventStep::EventStep(int init_step_count) {
	m_step_count = init_step_count;
}

//Setter/Getter for step count
void EventStep::setStepCount(int new_step_count) {
	m_step_count = new_step_count;
}
int EventStep::getStepCount() const {
	return m_step_count;
}