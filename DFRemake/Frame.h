#pragma once

#include <string>
#include "Color.h"
#include "Vector.h"

namespace df {
	class Frame {
	private:
		//Width of frame
		int m_width;
		//Height of frame
		int m_height;
		//All frame characters stored as string
		std::string m_frame_str;

	public:
		//constructor
		Frame();
		//Constructor with pre-set variables
		Frame(int new_width, int new_height, std::string frame_str);

		//Getter/setter ofr width
		void setWidth(int new_width);
		int getWidth() const;

		//Getter/setter of height
		void setHeight(int new_height);
		int getHeight() const;

		//Getter/setter for frame characters
		void setString(std::string new_frame_str);
		std::string getString() const;

		//Draw self at position with color
		int Draw(Vector position, Color color) const;
	};
};