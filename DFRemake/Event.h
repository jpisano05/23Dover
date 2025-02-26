#pragma once
#ifndef __EVENT_H__
#define __EVENT_H__

//includes
#include <stdlib.h>
#include <string>

const std::string UNDEFINED_EVENT = "df::undefined";

//Namespace def
namespace df {

	//Start of class definition
	class Event {

	private:
		//Event type
		std::string m_event_type;

	public:
		//Constructor
		Event();

		//Destructor
		virtual ~Event();

		//Setter/Getter for event type
		void setType(std::string new_type);
		std::string getType() const;
	};
}

#endif __EVENT_H__