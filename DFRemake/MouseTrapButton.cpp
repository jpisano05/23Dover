//Includes
#include "MouseTrapButton.h"
#include "ScoreManager.h"
#include "MouseTrap.h"

//Constructor
MouseTrapButton::MouseTrapButton() {
	//Set sprite

	setAltitude(MAX_ALTITUDE);

	setSolidness(SPECTRAL);
}

//Override the onClicked
void MouseTrapButton::onClicked() {
	if (SM.getPoints() >= price) {
		SM.setPoints(SM.getPoints() - price);
	}


}