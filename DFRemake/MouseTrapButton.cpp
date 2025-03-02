//Includes
#include "MouseTrapButton.h"
#include "ScoreManager.h"
#include "MouseTrap.h"
#include "InputManager.h"

//Constructor
MouseTrapButton::MouseTrapButton() {
	//Set sprite
	setSprite("mouse-trap-button");

	setAltitude(MAX_ALTITUDE);

	setSolidness(SPECTRAL);
}

//Override the onClicked
void MouseTrapButton::onClicked() {
	if (SM.getPoints() >= price) {
		SM.setPoints(SM.getPoints() - price);
	}

	MouseTrap* createdTrap = new MouseTrap(*IM.getMousePos(), true);
}