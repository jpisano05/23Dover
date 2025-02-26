#pragma once
//Includes
#include "Vector.h"

namespace df {
	class Box {
	private:
		//Upper left corner
		Vector m_corner;
		//horizontal dimension
		float m_horizontal;
		//vertical dimension
		float m_vertical;

	public:
		//Constructor
		Box();

		//Constructor with custom parameters
		Box(Vector init_corner, float init_horizontal, float init_vertical);

		//Setter/getter for corner
		void setCorner(Vector new_corner);
		Vector getCorner() const;

		//Setter/getter for horizontal
		void setHorizontal(float new_horizontal);
		float getHorizontal() const;

		//Setter/getter for vertical
		void setVertical(float new_vertical);
		float getVertical() const;

		//Checks if this box intersects with another
		bool boxIntersectsBox(Box other);
	};
}