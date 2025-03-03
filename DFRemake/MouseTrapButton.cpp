//Includes
#include "MouseTrapButton.h"
#include "ScoreManager.h"
#include "MouseTrap.h"
#include "InputManager.h"
#include "LogManager.h"
#include "DisplayManager.h"

//Constructor
MouseTrapButton::MouseTrapButton() {
	//Set sprite
	setSprite("mouse-trap-button");

	setAltitude(MAX_ALTITUDE);

	setSolidness(SPECTRAL);
}

//Override the onClicked
void MouseTrapButton::onClicked() {
	LM.writeLog("Mouse Trap Button was clicked");

	if (SM.getPoints() >= price) {
		LM.writeLog("Subtracted points");
		SM.setPoints(SM.getPoints() - price);
	}
	else {
		LM.writeLog("not enough points");
		return;

	}
	MouseTrap* createdTrap = new MouseTrap(DM.pixelsToSpaces(*IM.getMousePos()), true);
	LM.writeLog("Created mouse trap.");
}