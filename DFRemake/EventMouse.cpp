#pragma once

//Includes
#include "EventMouse.h"

//Constructor
EventMouse::EventMouse() {
	Event::setType(MSE_EVENT);
}

//Setter/getter for mouse action
void EventMouse::setMouseAction(EventMouseAction new_mouse_action) {
	m_mouse_action = new_mouse_action;
}
EventMouseAction EventMouse::getMouseAction() const {
	return m_mouse_action;
}

//Setter/getter for mouse button
void EventMouse::setMouseButton(Mouse::Button new_mouse_button) {
	m_mouse_button = new_mouse_button;
}
Mouse::Button EventMouse::getMouseButton() const {
	return m_mouse_button;
}

//Setter/getter for mouse event position
void EventMouse::setMousePosition(Vector new_mouse_xy) {
	m_mouse_xy = new_mouse_xy;
}
Vector EventMouse::getMousePosition() const {
	return m_mouse_xy;
}

//Converts from the SFML button type to the dragonfly version
Mouse::Button EventMouse::convertFromSFML(sf::Mouse::Button button) const {
	switch (button) {
		case sf::Mouse::Button::Left: return Mouse::Button::LEFT;
		case sf::Mouse::Button::Right: return Mouse::Button::RIGHT;
		case sf::Mouse::Button::Middle: return Mouse::Button::MIDDLE;
		default: return Mouse::UNDEFINED_MOUSE_BUTTON;
	}
}