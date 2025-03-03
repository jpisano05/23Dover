//Includes
#include "Button.h"
#include "EventMouse.h"
<<<<<<< HEAD
using namespace df;
=======
>>>>>>> parent of 6e4716b (Purchasing a mouse trap now works and they can be placed)

//Constructor
Button::Button() {

}

//Override the event handler
int Button::eventHandler(const df::Event* p_e) {
	//Handle step
	if (p_e->getType() == MSE_EVENT) {
		const EventMouse* p_mouse_event = dynamic_cast<const EventMouse*> (p_e);
		if (wasClicked(p_mouse_event)) {
			onClicked();
		}
		return 1;
	}

	return 0;
}

bool Button::wasClicked(const EventMouse* m_e) {
	bool c = false;

	if (m_e->getMouseAction() == CLICKED) {
		if (getBox().boxIntersectsBox(Box(m_e->getMousePosition(), 0, 0))) {
			c = true;
		}
	}

	return c;
}

void Button::onClicked() {

}