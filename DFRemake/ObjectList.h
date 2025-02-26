#pragma once
#ifndef __OBJECTLIST_H__
#define __OBJECTLIST_H__

//includes
#include <stdlib.h>
#include "Object.h"
#include <string>
#include <vector>

const int MAX_OBJECTS = 1000;

//Namespace def
namespace df {

	//Start of class definition
	class ObjectList {
	private:
		//Number of objects in list
		int m_count;
		//Array of pointers to each object
		vector<Object*> m_p_obj;

	public:

		//Constructor
		ObjectList();

		//Insert object into list
		//0 normal, -1 error
		int insert(Object* p_o);

		//Remove object from list
		//0 normal, -1 error
		int remove(Object* p_o);

		//Clear list completely
		void clear();

		//Return number of objects in list
		int getCount() const;

		//Return true if list is empty
		bool isEmpty() const;

		//Return true if list is full
		bool isFull() const;

		//Index into list
		Object* operator[](int index) const;

	};
}

#endif __OBJECTLIST_H__