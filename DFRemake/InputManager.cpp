#pragma once

//Includes
#include "InputManager.h"
#include "DisplayManager.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "WorldManager.h"
#include "LogManager.h"

using namespace df;

//Constructor
InputManager::InputManager() {

}

//Destructor
InputManager::~InputManager() {

}

//Start the InputManager
int InputManager::startUp() {
	if (!DM.isStarted()) {
		LM.writeLog("DM is not started for IM");
		return -1;
	}
	LM.writeLog("DM Started for IM");

	lastMousePos = new Vector();

	sf::RenderWindow* window = DM.getWindow();
	LM.writeLog("Window gotten");

	//window->setKeyRepeatEnabled(false);
	LM.writeLog("Window set key repeat enabled false");

	Manager::startUp();
	LM.writeLog("Should have finished starting IM");
	
	return 0;
}

//Shutdown the InputManager
void InputManager::shutDown() {
	sf::RenderWindow* window = DM.getWindow();

	window->setKeyRepeatEnabled(true);

	Manager::shutDown();
}

//Get input from keyboard and mouse
void InputManager::getInput() const {
	sf::RenderWindow* window = DM.getWindow();
	std::optional anEvent = window->pollEvent();

	bool eventValue = anEvent.has_value();

	while(eventValue){
		LM.writeLog("Event polled");
		if (const auto* press = anEvent->getIf<sf::Event::KeyPressed>()) {
			EventKeyboard* newKeyboard = new EventKeyboard();
			newKeyboard->setKey(newKeyboard->convertFromSFML(press->code));
			newKeyboard->setKeyboardAction(KEY_PRESSED);

			WM.onEvent(newKeyboard);
		}
		else if (const auto* release = anEvent->getIf<sf::Event::KeyPressed>()) {
			EventKeyboard* newKeyboard = new EventKeyboard();
			newKeyboard->setKey(newKeyboard->convertFromSFML(release->code));
			newKeyboard->setKeyboardAction(KEY_RELEASED);

			WM.onEvent(newKeyboard);
		}
		else if (const auto* move = anEvent->getIf<sf::Event::MouseMoved>()) {
			EventMouse* newMouse = new EventMouse();
			newMouse->setMouseAction(MOVED);
			newMouse->setMouseButton(Mouse::UNDEFINED_MOUSE_BUTTON);
			sf::Vector2i pos = move->position;
			newMouse->setMousePosition(Vector(pos.x, pos.y));

			lastMousePos->setXY(pos.x, pos.y);

			WM.onEvent(newMouse);
		}
		else if (const auto* click = anEvent->getIf<sf::Event::MouseButtonPressed>()) {
			LM.writeLog("Click event");
			EventMouse* newMouse = new EventMouse();
			LM.writeLog("New mouse made");
			newMouse->setMouseAction(CLICKED);
			LM.writeLog("Set action to CLICKED");
			newMouse->setMouseButton(newMouse->convertFromSFML(click->button));
			LM.writeLog("Converted from SFML");
			sf::Vector2i pos = click->position;
			LM.writeLog("Got position");
			newMouse->setMousePosition(Vector(pos.x, pos.y));
			LM.writeLog("set click position");

			WM.onEvent(newMouse);
			LM.writeLog("Broadcasted event");
		}

		anEvent = window->pollEvent();
		eventValue = anEvent.has_value();
	}
}

//Get last mouse pos
Vector* InputManager::getMousePos() {
	return lastMousePos;
}

void InputManager::setMousePos(Vector* newMousePos) {
	lastMousePos = newMousePos;
}