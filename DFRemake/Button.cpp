//Includes
#include "Button.h"
#include "EventMouse.h"
#include "LogManager.h"
#include "DisplayManager.h"
#include "WorldManager.h"

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
		if (this->getWorldBox(getPosition()).boxIntersectsBox(Box(DM.pixelsToSpaces(m_e->getMousePosition()), 0, 0))) {
			LM.writeLog("Click was on");
			c = true;
		}
		else {
			LM.writeLog("Didnt click button at, (%f, %f). Box corner at: (%f, %f) with h/w (%f, %f)", DM.pixelsToSpaces(m_e->getMousePosition()).getX(), DM.pixelsToSpaces(m_e->getMousePosition()).getY(), this->getWorldBox(getPosition()).getCorner().getX(), this->getWorldBox(getPosition()).getCorner().getY(), this->getWorldBox(getPosition()).getVertical(), this->getWorldBox(getPosition()).getHorizontal());
		}
	}

	return c;
}

void Button::onClicked() {

}