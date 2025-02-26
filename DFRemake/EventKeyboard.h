#pragma once

#include "Event.h"
#include <SFML/Graphics.hpp>

const std::string KEYBOARD_EVENT = "df::keyboard";

using namespace df;

//Recognized keyboard inputs
enum EventKeyboardAction {
	UNDEFINED_KEYBOARD_ACTION = -1,
	KEY_PRESSED,
	KEY_RELEASED,
};

namespace Keyboard {
	enum Key {
		UNDEFINED_KEY = -1, SPACE, RETURN, ESCAPE, TAB, LEFTARROW, RIGHTARROW, UPARROW, DOWNARROW, PAUSE, MINUS, PLUS, TILDE, PERIOD, COMMA, SLASH, LEFTCONTROL, RIGHTCONTROL, LEFTSHIFT, RIGHTSHIFT, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9, NUM0,
	};
} //End of keyboard

class EventKeyboard : public Event {
	private:
		Keyboard::Key m_key_val;
		EventKeyboardAction m_keyboard_action;
	
	public:
		//Constructor
		EventKeyboard();

		//Setter/getter for Key
		void setKey(Keyboard::Key new_key);
		Keyboard::Key getKey() const;

		//Setter/getter for keybord event
		void setKeyboardAction(EventKeyboardAction new_action);
		EventKeyboardAction getKeyboardAction() const;

		//Converts from the SFML key type to the dragonfly version
		Keyboard::Key convertFromSFML(sf::Keyboard::Key key) const;
};
