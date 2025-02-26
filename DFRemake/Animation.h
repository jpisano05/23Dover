#pragma once
//Includes
#include <string>
#include "Sprite.h"
#include "Box.h"

namespace df {
	class Animation {
	private:
		//Sprite with animation
		df::Sprite* m_p_sprite;
		//Sprite name
		std::string m_name;
		//Index frame of sprite
		int m_index;
		//Slowdown counter
		int m_slowdown_count;
	public:
		//Constructor
		Animation();

		//Getter/setter for sprite
		void setSprite(df::Sprite* p_new_sprite);
		df::Sprite* getSprite() const;

		//Getter/setter for sprite name
		void setName(std::string new_name);
		std::string getName() const;

		//Getter/setter for frame index
		void setIndex(int new_index);
		int getIndex() const;

		//Getter/setter for animation slowdown counter
		void setSlowdownCount(int new_slowdown_count);
		int getSlowdownCount() const;

		//Draw frame at position
		int draw(Vector position);

		//Get bounding box of sprite
		df::Box getBox() const;
	};
};