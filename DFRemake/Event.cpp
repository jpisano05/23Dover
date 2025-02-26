
#pragma once
#include "Event.h"

using namespace df;

//Constructor
Event::Event() {
	m_event_type = UNDEFINED_EVENT;
}

//Destructor
Event::~Event() {

}

//Setter/Getter for event type
void Event::setType(std::string new_type) {
	m_event_type = new_type;
}
std::string Event::getType() const {
	return m_event_type;
}