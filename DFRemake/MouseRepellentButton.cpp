//Includes
#include "MouseRepellentButton.h"
#include "ScoreManager.h"
#include "MouseRepellent.h"
#include "InputManager.h"
#include "LogManager.h"
#include "DisplayManager.h"

//Constructor
MouseRepellentButton::MouseRepellentButton() {
	//Set sprite
	setSprite("mouse-repellent-button");

	setAltitude(4);
	setPosition(df::Vector(47, 20));
	setSolidness(df::SPECTRAL);
}

//Override the onClicked
void MouseRepellentButton::onClicked() {
	LM.writeLog("Mouse Repellent Button was clicked");

	if (SM.getPoints() >= price) {
		LM.writeLog("Subtracted points");
		SM.setPoints(SM.getPoints() - price);
	}
	else {
		LM.writeLog("not enough points");
		return;

	}
	MouseRepellent* createdTrap = new MouseRepellent(DM.pixelsToSpaces(*IM.getMousePos()), true);
	LM.writeLog("Created mouse trap.");
}