#pragma once
#ifndef __VECTOR_H__
#define __VECTOR_H__

//includes
#include <stdlib.h>

//Namespace def
namespace df {

	//Start of class definition
	class Vector {
		private:
			float m_x;
			float m_y;

		public:

			//Construct0r with preset x,y
			Vector(float init_x, float init_y);

			//Constructor with default x,y (0,0)
			Vector();

			//Getter/Setter X
			void setX(float new_x);
			float getX() const;

			//Getter/Setter Y
			void setY(float new_y);
			float getY() const;

			//Setter for both
			void setXY(float new_x, float new_y);

			//Get the Magnitude
			float getMagnitude() const;

			//Normalize the vector
			void normalize();

			//Scale the Vector
			void scale(float s);

			//Override + so vectors can be added
			Vector operator+(const Vector& other) const;

			//Override - so vectors can be subtracted
			Vector operator-(const Vector& other) const;

			//Override * so vectors can be added
			Vector operator*(const Vector& other) const;

			//Override / so vectors can be subtracted
			Vector operator/(const Vector& other) const;

			//Override == so vectors can be compared
			bool operator==(const Vector& other) const;

			//Checks if this vector and another intersect
			bool positionsIntersect(Vector p2) const;
	};
}

#endif __VECTOR_H__