#pragma once
#ifndef __CLOCK_H__
#define __CLOCK_H__

//includes
#include <stdlib.h>
#include <time.h>

//Namespace def
namespace df {

	//Start of class definition
	class Clock {

		private:

			//Stores the previous delta() call
			long int m_previous_time;

		public:
			//Constructor
			Clock();

			//Returns a human-readable time string
			char* getTimeString();

			//Return time elapsed since delta() was last called
			long int delta();

			//Return time elapsed since last delta() was called, does not reset m_previous_time
			long int split() const;

	};
}

#endif __CLOCK_H__