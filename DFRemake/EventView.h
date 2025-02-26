#pragma once

//Includes
#include "Event.h"
#include <string>

namespace df {
	const std::string VIEW_EVENT = "df::view";

	class EventView : public Event {
	private:
		//Tag
		std::string m_tag;
		//Value
		int m_value;
		//True if change in value
		bool m_delta;
	public:
		//Constrcutor
		EventView();
		//Constructor with parameters
		EventView(std::string new_tag, int new_value, bool new_delta);

		//Setter/getter for tag
		void setTag(std::string new_tag);
		std::string getTag() const;

		//Setter/getter value
		void setValue(int new_value);
		int getValue() const;

		//Setter/getter delta
		void setDelta(bool new_delta);
		bool getDelta() const;
	};
}