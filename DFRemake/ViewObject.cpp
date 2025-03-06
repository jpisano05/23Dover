//Includes
#include "ViewObject.h"
#include "WorldManager.h"
#include <sstream>
#include "DisplayManager.h"
#include "EventView.h"
#include "LogManager.h"
using namespace df;

//Constrcutor
ViewObject::ViewObject() {
	setSolidness(SPECTRAL);
	setAltitude(MAX_ALTITUDE);
	setType("ViewObject");

	setValue(0);
	setDrawValue(true);
	setBorder(true);
	setLocation(TOP_CENTER);
	setColor(WHITE);
}

//Draw view string and value
int ViewObject::draw() {
	std::string temp_str = "";
	if (m_border) {
		temp_str = "|" + getViewString() + " " + toString(m_value) + "|";
	}
	else {
		temp_str = getViewString() + " " + toString(m_value);
	}

	Vector pos = WM.viewToWorld(getPosition());
	DM.drawString(pos, temp_str, CENTER_JUSTIFIED, getColor());

	if (m_border) {
		std::string horizontal = "";
		for (int i = 0; i < temp_str.length(); i++) {
			horizontal += "-";
		}
		Vector modPos = pos;
		modPos.setY(modPos.getY() - 1);
		DM.drawString(modPos, horizontal, CENTER_JUSTIFIED, getColor());
		modPos.setY(modPos.getY() + 2);
		DM.drawString(modPos, horizontal, CENTER_JUSTIFIED, getColor());

	}

	return 0;
}

std::string ViewObject::toString(int i) {
	std::stringstream ss;
	ss << i;
	return ss.str();
}

//Handle 'view' event
int ViewObject::eventHandler(const Event* p_e) {
	if (p_e->getType() == VIEW_EVENT) {
		const EventView* p_ve = dynamic_cast<const EventView*>(p_e);

		if (p_ve->getTag() == getViewString()) {
			if (p_ve->getDelta()) {
				setValue(getValue() + p_ve->getValue());
			}
			else {
				//LM.writeLog("Increasing value");
				setValue(p_ve->getValue());
			}
			return 0;
		}
		else {
			//LM.writeLog("Denied, %s != %s", p_ve->getTag().c_str(), getViewString().c_str());
		}
	}
	else {
		//LM.writeLog(" %s, Not a view_event", p_e->getType().c_str());
	}

	Object::eventHandler(p_e);
	return -1;
}

//General location of ViewObject on screen
void ViewObject::setLocation(ViewObjectLocation new_location) {
	Vector* p = new Vector();
	float y_delta = 0;
	switch (new_location) {
	case TOP_LEFT:
		p->setXY(WM.getView().getHorizontal() * 1 / 6, 1);
		if (getBorder() == false) {
			y_delta = -1;
		}
		break;
	case TOP_CENTER:
		p->setXY(WM.getView().getHorizontal() * 3 / 6, 1);
		if (getBorder() == false) {
			y_delta = -1;
		}
		break;
	case TOP_RIGHT:
		p->setXY(WM.getView().getHorizontal() * 5 / 6, 1);
		if (getBorder() == false) {
			y_delta = -1;
		}
		break;
	case CENTER_LEFT:
		p->setXY(WM.getView().getHorizontal() * 1 / 6, WM.getView().getVertical() * 3/6);
		if (getBorder() == false) {
			y_delta = 0;
		}
		break;
	case CENTER_CENTER:
		p->setXY(WM.getView().getHorizontal() * 3 / 6, WM.getView().getVertical() * 3 / 6);
		if (getBorder() == false) {
			y_delta = 0;
		}
		break;
	case CENTER_RIGHT:
		p->setXY(WM.getView().getHorizontal() * 5 / 6, WM.getView().getVertical() * 3 / 6);
		if (getBorder() == false) {
			y_delta = 0;
		}
		break;
	case BOTTOM_LEFT:
		p->setXY(WM.getView().getHorizontal() * 2 / 12, WM.getView().getVertical() * 11 / 12);
		if (getBorder() == false) {
			y_delta = -1;
		}
		break;
	case BOTTOM_CENTER:
		p->setXY(WM.getView().getHorizontal() * 3 / 6, WM.getView().getVertical() * 11 / 12);
		if (getBorder() == false) {
			y_delta = -1;
		}
		break;
	case BOTTOM_RIGHT:
		p->setXY(WM.getView().getHorizontal() * 10 / 12, WM.getView().getVertical() * 11 / 12);
		if (getBorder() == false) {
			y_delta = -1;
		}
		break;
	}
	p->setY(p->getY() + y_delta);

	setPosition(*p);

	m_location = new_location;
}

//Get general location of View object on screen
ViewObjectLocation ViewObject::getLocation() const {
	return m_location;
}

//Setter/getter value
void ViewObject::setValue(int new_value) {
	m_value = new_value;
}
int ViewObject::getValue() const {
	return m_value;
}

//Setter/getter view border
void ViewObject::setBorder(bool new_border) {
	if (m_border != new_border) {
		m_border = new_border;

		setLocation(getLocation());
	}
}
bool ViewObject::getBorder() const {
	return m_border;
}

//Setter/getter color
void ViewObject::setColor(df::Color new_color) {
	m_color = new_color;
}
df::Color ViewObject::getColor() const {
	return m_color;
}

//Setter/getter display string
void ViewObject::setViewString(std::string new_view_string) {
	view_string = new_view_string;
}
std::string ViewObject::getViewString() const {
	return view_string;
}

//Setter.getter drawvalue
void ViewObject::setDrawValue(bool new_draw_value) {
	m_draw_value = new_draw_value;
}
bool ViewObject::getDrawValue() const {
	return m_draw_value;
}