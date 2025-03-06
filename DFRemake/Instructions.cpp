#include "Instructions.h"
#include "DisplayManager.h"
#include "EventKeyboard.h"
#include "WorldManager.h"
#include "GameStart.h"


Instructions::Instructions() {
	// set type
	setType("Instructions");

	// set sprite
	setSprite("instructions");
	setPosition(df::Vector(DM.getHorizontal() / 2, DM.getVertical() / 2));
}

int Instructions::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == KEYBOARD_EVENT) {
        EventKeyboard* p_keyboard_event = (EventKeyboard*)p_e;
        switch (p_keyboard_event->getKey()) {
        case Keyboard::B: 			// back
            new GameStart();
            WM.markForDelete(this);
            break;
        default: // Key is not handled.
            break;
        }
        return 1;
    }
}

int Instructions::draw() {
	return Object::draw();
}