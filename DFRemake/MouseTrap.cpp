//Includes
#include "MouseTrap.h"

//Constructor with defaults
MouseTrap::MouseTrap(df::Vector position) {
	setSprite("mouse-trap");
	setPosition(position);
	//Trap(position, 5, 5, 4, 3);
}