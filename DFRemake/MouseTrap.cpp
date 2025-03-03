//Includes
#include "MouseTrap.h"
#include "WorldManager.h"
#include "ObjectList.h"
#include "Mice.h"

//Constructor with defaults
MouseTrap::MouseTrap(df::Vector position, bool isGrabbed) {
	setSprite("mouse-trap");
	setPosition(position);
	setGrabbed(isGrabbed);
	//Trap(position, 5, 5, 4, 3);
}

void MouseTrap::action() {
	df::ObjectList mice = WM.objectsOfType("mouse");
	for (int i = 0; i < mice.getCount(); i++) {
		if ((getPosition() - mice[i]->getPosition()).getMagnitude() <= getRange()) {
			dynamic_cast<Mice*>(mice[i])->setHealth(0);
		}
	}
}