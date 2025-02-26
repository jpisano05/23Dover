#pragma once

#include "Event.h"
#include "Vector.h"
#include <SFML/Graphics.hpp>

const std::string MSE_EVENT = "df::mouse";

//Mouse actions
enum EventMouseAction {
	UNDEFINED_MOUSE_ACTION = -1,
	CLICKED,
	MOVED,
};

//Mouse buttons recognized
namespace Mouse {
	enum Button {
		UNDEFINED_MOUSE_BUTTON = -1,
		LEFT,
		RIGHT,
		MIDDLE,
	};
}

using namespace df;

class EventMouse : public Event {

	private:
		//Mouse action
		EventMouseAction m_mouse_action;
		//Mouse button
		Mouse::Button m_mouse_button;
		//Mouse coordinates
		Vector m_mouse_xy;

	public:
		//Constructor
		EventMouse();

		//Setter/getter for mouse action
		void setMouseAction(EventMouseAction new_mouse_action);
		EventMouseAction getMouseAction() const;

		//Setter/getter for mouse button
		void setMouseButton(Mouse::Button new_mouse_button);
		Mouse::Button getMouseButton() const;

		//Setter/getter for mouse event position
		void setMousePosition(Vector new_mouse_xy);
		Vector getMousePosition() const;

		//Converts from the SFML button type to the dragonfly version
		Mouse::Button convertFromSFML(sf::Mouse::Button button) const;
};