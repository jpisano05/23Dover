//includes
#include "Vector.h"
#include <math.h>
#include "LogManager.h"

using namespace df;

//Construct0r with preset x,y
Vector::Vector(float init_x, float init_y) {
	m_x = init_x;
	m_y = init_y;
}

//Constructor with default x,y (0,0)
Vector::Vector() {
	m_x = 0;
	m_y = 0;
}

//Getter/Setter X
void Vector::setX(float new_x) {
	m_x = new_x;
}

float Vector::getX() const {
	return m_x;
}

//Getter/Setter Y
void Vector::setY(float new_y) {
	m_y = new_y;
}

float Vector::getY() const {
	return m_y;
}

//Setter for both
void Vector::setXY(float new_x, float new_y) {
	m_x = new_x;
	m_y = new_y;
}

//Get the Magnitude
float Vector::getMagnitude() const {
	float magnitude = sqrt(m_x * m_x + m_y * m_y);
	return magnitude;
}

//Normalize the vector
void Vector::normalize() {
	float length = getMagnitude();
	if (length > 0) {
		m_x = m_x / length;
		m_y = m_y / length;
	}
}

//Scale the Vector
void Vector::scale(float s) {
	m_x *= s;
	m_y *= s;
}

//Override + so vectors can be added
Vector Vector::operator+(const Vector& other) const {
	Vector *sumVector = new Vector(m_x + other.getX(), m_y + other.getY());
	return *sumVector;
}

//Override - so vectors can be added
Vector Vector::operator-(const Vector& other) const {
	Vector* difVector = new Vector(m_x - other.getX(), m_y - other.getY());
	return *difVector;
}

//Override * so vectors can be added
Vector Vector::operator*(const Vector& other) const {
	Vector* sumVector = new Vector(m_x * other.getX(), m_y * other.getY());
	return *sumVector;
}

//Override * so vectors can be added
Vector Vector::operator/(const Vector& other) const {
	Vector* difVector = new Vector(m_x / other.getX(), m_y / other.getY());
	return *difVector;
}

//Override == so vectors can be compared
bool Vector::operator==(const Vector& other) const {
	bool xSame = false;
	bool ySame = false;

	if (m_x == other.getX()) {
		xSame = true;
	}
	if (m_y == other.getY()) {
		ySame = true;
	}

	return xSame && ySame;
}

//Checks if this vector and another intersect
bool Vector::positionsIntersect(Vector p2) const {
	if ((abs(m_x - p2.getX()) <= 1) && (abs(m_y - p2.getY()) <= 1)) {
		LM.writeLog("Position (%f,%f) collides with (%f,%f)", m_x, m_y, p2.getX(), p2.getY());
		LM.writeLog("Absolute value of x is: %f ", abs(m_x - p2.getX()));
		return true;
	}
	else {
		return false;
	}
}