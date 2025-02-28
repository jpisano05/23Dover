//Includes
#include "MouseTrap.h"
#include "WorldManager.h"
#include "ObjectList.h"
#include "Mouse.h"

//Constructor with defaults
MouseTrap::MouseTrap(df::Vector position) {
	setSprite("mouse-trap");
	setPosition(position);
	//Trap(position, 5, 5, 4, 3);
}

void MouseTrap::action() {
	df::ObjectList mice = WM.objectsOfType("mouse");
	for (int i = 0; i < mice.getCount(); i++) {
		if ((getPosition() - mice[i]->getPosition()).getMagnitude() <= getRange()) {
			dynamic_cast<Mouse*>(mice[i])->setHealth(0);
		}
	}
}