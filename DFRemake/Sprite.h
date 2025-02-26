#pragma once
#include <string>
#include "Frame.h"

using namespace std;

namespace df {
	class Sprite {
	private:
		//Sprite width
		int m_width;
		//Sprite height
		int m_height;
		//Max number of frames
		int m_max_frame_count;
		//Actual frames
		int m_frame_count;
		//Optional color
		Color m_color;
		//Animation slowdown, 1 == none 0 == stop
		int m_slowdown;
		//Array of frames
		Frame* m_frame;
		//Text label for ID
		string m_label;
		//Constructor
		Sprite();
	public:
		//Destructor
		~Sprite();
		//Constructor with max frames
		Sprite(int max_frames);

		//Getter/setter width
		void setWidth(int new_width);
		int getWidth() const;
		//Getter/setter height
		void setHeight(int new_height);
		int getHeight() const;
		//Getter/setter color
		void setColor(Color new_color);
		Color getColor() const;
		//Getter for frame
		Frame getFrame(int frame_number) const;
		//Add a frame
		int addFrame(Frame new_frame);
		//Getter/setter label
		void setLabel(std::string new_label);
		string getLabel() const;
		//getter/setter slowdown
		void setSlowdown(int new_sprite_slowdown);
		int getSlowdown() const;
		//Draw current frame at position
		int draw(int frame_number, Vector position) const;
		//getter for frame count
		int getFrameCount() const;
	};
}