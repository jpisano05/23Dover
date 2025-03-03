//Includes
#include "MouseTrap.h"
#include "WorldManager.h"
#include "ObjectList.h"
#include "Mice.h"
#include "LogManager.h"
#include "DisplayManager.h"

//Constructor with defaults
MouseTrap::MouseTrap(df::Vector position, bool isGrabbed) {
	setSprite("mouse-trap");
	setPosition(position);
	setGrabbed(isGrabbed);

	setAltitude(2);
	//Trap(position, 5, 5, 4, 3);

	//Set stats
	setCooldown(5);
	setCC(5);
	//In pixels so the aspect ratio is normalized
	setRange(100);
	setDamage(1);
}

void MouseTrap::action() {
	df::ObjectList mice = WM.objectsOfType("mouse");
	//LM.writeLog("getting all mice");
	for (int i = 0; i < mice.getCount(); i++) {
		//LM.writeLog("Current checked mouse at a range of %f", (getPosition() - mice[i]->getPosition()).getMagnitude());
		if (DM.spacesToPixels(getPosition() - mice[i]->getPosition()).getMagnitude() <= getRange()) {
			dynamic_cast<Mice*>(mice[i])->setHealth(0);
			//LM.writeLog("Setting all mice to 0 health in range");
		}
	}
}