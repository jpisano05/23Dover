
#pragma once

#ifndef __MANAGER_H__
#define __MANAGER_H__

//includes
#include <stdlib.h>
#include <string>
#include "Event.h"

//Namespace def
namespace df {

	//Start of class definition
	class Manager {
		private:
			//identifies the manager type
			std::string m_type;
			//true when the manager is started
			bool m_is_started;

		protected:
			//Sets the type of the manager
			void setType(std::string type);

		public:
			//Constructor
			Manager();

			//Destructor
			virtual ~Manager();

			//Get type ID of manager
			std::string getType() const;

			//Start the manager
			virtual int startUp();

			//Shutdown the manager
			virtual void shutDown();

			//Checks if the manager has been started yet
			bool isStarted() const;

			//Send event to all objects
			int onEvent(const Event* p_event) const;
	};

}

#endif __MANAGER_H__