//Includes
#include <string>
#include "Object.h"
#include "Event.h"
#include "Box.h"

namespace df {
	enum ViewObjectLocation {
		UNDERFINED = -1,
		TOP_LEFT,
		TOP_CENTER,
		TOP_RIGHT,
		CENTER_LEFT,
		CENTER_CENTER,
		CENTER_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_CENTER,
		BOTTOM_RIGHT,
	};

	class ViewObject : public Object {
	private:
		//Label
		std::string view_string;
		//Value displayed
		int m_value;
		//True if should draw value
		bool m_draw_value;
		//True if border around display
		bool m_border;
		//Color for text
		df::Color m_color;
		//Location of ViewObject
		ViewObjectLocation m_location;

	public:
		//Constrcutor
		ViewObject();

		//Draw view string and value
		virtual int draw() override;

		//Handle 'view' event
		virtual int eventHandler(const Event* p_e) override;

		//General location of ViewObject on screen
		void setLocation(ViewObjectLocation new_location);

		//Get general location of View object on screen
		ViewObjectLocation getLocation() const;

		//Setter/getter value
		void setValue(int new_value);
		int getValue() const;

		//Setter/getter view border
		void setBorder(bool new_border);
		bool getBorder() const;
		
		//Setter/getter color
		void setColor(df::Color new_color);
		df::Color getColor() const;

		//Setter/getter display string
		void setViewString(std::string new_view_string);
		std::string getViewString() const;

		//Setter.getter drawvalue
		void setDrawValue(bool new_draw_value);
		bool getDrawValue() const;

		//To string
		std::string toString(int i);
	};
}