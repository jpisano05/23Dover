//Includes
#include "GlueTrapButton.h"
#include "ScoreManager.h"
#include "GlueTrap.h"
#include "InputManager.h"
#include "LogManager.h"
#include "DisplayManager.h"

//Constructor
GlueTrapButton::GlueTrapButton() {
	//Set sprite
	setSprite("glue-trap-button");

	setAltitude(4);
	setPosition(df::Vector(28, 20));
	setSolidness(df::SPECTRAL);
}

//Override the onClicked
void GlueTrapButton::onClicked() {
	LM.writeLog("Glue Trap Button was clicked");

	if (SM.getPoints() >= price) {
		LM.writeLog("Subtracted points");
		SM.setPoints(SM.getPoints() - price);
	}
	else {
		LM.writeLog("not enough points");
		return;

	}
	GlueTrap* createdTrap = new GlueTrap(DM.pixelsToSpaces(*IM.getMousePos()), true);
	LM.writeLog("Created mouse trap.");
}