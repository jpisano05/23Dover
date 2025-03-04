//Includes
#include "MouseRepellent.h"
#include "WorldManager.h"
#include "ObjectList.h"
#include "Mice.h"
#include "LogManager.h"
#include "DisplayManager.h"
#include <stdlib.h>
#include <vector>

//Constructor with defaults
MouseRepellent::MouseRepellent(df::Vector position, bool isGrabbed) {
	setType("Trap");
	setSprite("mouse-repellent");
	setLabel("mouse-repellent");
	setPosition(position);
	setGrabbed(isGrabbed);

	setAltitude(2);
	//Trap(position, 5, 5, 4, 3);

	//Set stats
	setCooldown(100);
	setCC(100);
	//In pixels so the aspect ratio is normalized
	setRange(100);
	setActive(1);
	setAA(0);
}

void MouseRepellent::action() {
	//LM.writeLog("getting all mice");

	//WM.objectsOfType("mouse");
	std::vector<Object*> mice = WM.objectsOfType("mouse");
	//LM.writeLog("got all mice");
	for (int i = 0; i < mice.size(); i++) {
		//LM.writeLog("Current checked mouse at a range of %f", (getPosition() - mice[i]->getPosition()).getMagnitude());
		if (DM.spacesToPixels(getPosition() - mice.at(i)->getPosition()).getMagnitude() <= getRange()) {
			dynamic_cast<Mice*>(mice.at(i))->reversePath();
			//LM.writeLog("Setting all mice to 0 health in range");
		}
	}
}