#pragma once

//Includes
#include "Manager.h"
#include "WorldManager.h"


using namespace df;

//Constructor
Manager::Manager() {
	m_is_started = false;
	m_type = "Manager";
}

Manager::~Manager() {

}

//Setter for m_type, to change the type ID of the manager
void Manager::setType(std::string type) {
	m_type = type;
}

//Getter for m_is_started, whether the manager has yet been started
bool Manager::isStarted() const {
	bool answer = m_is_started;
	return answer;
}

int Manager::startUp() {
	m_is_started = true;
	return 0;
}

void Manager::shutDown() {
	m_is_started = false;
}

//Send event to all objects
int Manager::onEvent(const Event* p_event) const {
	int count = 0;

	ObjectList all_objects = WM.getAllObjects();
	for (int i = 0; i < all_objects.getCount(); i++) {
		all_objects[i]->eventHandler(p_event);
		count++;
	}

	return count;
}
