#pragma once

#include "ObjectList.h"
#include <list>
#include "LogManager.h"

using namespace df;

//Constructor
ObjectList::ObjectList() {
	m_count = 0;
}

//Insert object into list
//0 normal, -1 error
int ObjectList::insert(Object* p_o) {
	if (isFull()) {
		return -1;
	}
	m_p_obj.push_back(p_o);
	p_o->setId(m_count);
	m_count++;

	//LM.writeLog("Inserted object with count %d", getCount());

	return 0;
}

//Remove object from list
//0 normal, -1 error
int ObjectList::remove(Object* p_o) {
	if (isEmpty()) {
		return -1;
	}

	int index = -1;

	//LM.writeLog("Item id: %d", p_o->getId());
	for (int i = 0; i < m_count; i++) {
		if (m_p_obj.at(i)->getId() == p_o->getId()) {
			index = i;
		}
	}

	if (index == -1) {
		return -1;
	}

	m_p_obj.erase(m_p_obj.begin() + index);
	m_count--;

	return 0;
}

//Clear list completely
void ObjectList::clear() {
	m_p_obj.clear();
	m_count = 0;
}

//Return number of objects in list
int ObjectList::getCount() const {
	return m_p_obj.size();
}

//Return true if list is empty
bool ObjectList::isEmpty() const {
	return m_p_obj.empty();
}

//Return true if list is full
bool ObjectList::isFull() const {
	return m_count == MAX_OBJECTS;
}

//Index into list
Object* ObjectList::operator[](int index) const {
	return m_p_obj.at(index);
}