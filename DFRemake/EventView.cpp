#pragma once

//Includes
#include "EventView.h"

using namespace df;

//Constrcutor
EventView::EventView() {
	m_tag = VIEW_EVENT;
	m_value = 0;
	m_delta = false;

	Event::setType(VIEW_EVENT);
}
//Constructor with parameters
EventView::EventView(std::string new_tag, int new_value, bool new_delta) {
	m_tag = new_tag;
	m_value = new_value;
	m_delta = new_delta;

	Event::setType(VIEW_EVENT);
}

//Setter/getter for tag
void EventView::setTag(std::string new_tag) {
	m_tag = new_tag;
}
std::string EventView::getTag() const {
	return m_tag;
}

//Setter/getter value
void EventView::setValue(int new_value) {
	m_value = new_value;
}
int EventView::getValue() const {
	return m_value;
}

//Setter/getter delta
void EventView::setDelta(bool new_delta) {
	m_delta = new_delta;
}
bool EventView::getDelta() const {
	return m_delta;
}