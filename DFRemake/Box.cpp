#pragma once

//Includes
#include "Box.h"

using namespace df;

//Constructor
Box::Box() {
	m_corner = Vector();
	m_horizontal = 0;
	m_vertical = 0;
}

//Constructor with custom parameters
Box::Box(Vector init_corner, float init_horizontal, float init_vertical) {
	m_corner = init_corner;
	m_horizontal = init_horizontal;
	m_vertical = init_vertical;
}

//Setter/getter for corner
void Box::setCorner(Vector new_corner) {
	m_corner = new_corner;
}
Vector Box::getCorner() const {
	return m_corner;
}

//Setter/getter for horizontal
void Box::setHorizontal(float new_horizontal) {
	m_horizontal = new_horizontal;
}
float Box::getHorizontal() const {
	return m_horizontal;
}

//Setter/getter for vertical
void Box::setVertical(float new_vertical) {
	m_vertical = new_vertical;
}
float Box::getVertical() const {
	return m_vertical;
}

//Return true if boxes interact
bool Box::boxIntersectsBox(Box other) {
	float Ax1 = m_corner.getX();
	float Ax2 = m_corner.getX() + m_horizontal;
	float Ay1 = m_corner.getY();
	float Ay2 = m_corner.getY() + m_vertical;

	float Bx1 = other.getCorner().getX();
	float Bx2 = other.getCorner().getX() + other.getHorizontal();
	float By1 = other.getCorner().getY();
	float By2 = other.getCorner().getY() + other.getVertical();
	bool x_overlap = (Bx1 <= Ax1 && Ax1 <= Bx2) || (Ax1 <= Bx1 && Bx1 <= Ax2);
	bool y_overlap = (By1 <= Ay1 && Ay1 <= By2) || (Ay1 <= By1 && By1 <= Ay2);

	if (x_overlap && y_overlap) {
		return true;
	}
	else {
		return false;
	}
}