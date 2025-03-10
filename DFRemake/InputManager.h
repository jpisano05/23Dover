#pragma once

#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__
#define IM df::InputManager::getInstance()

//includes
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "Manager.h"
#include "Vector.h"

//Namespace def
namespace df {

	//Start of class definition
	class InputManager : public Manager {
	private:
		//Constructor
		InputManager();
		//Prevent copies
		InputManager(InputManager const&);
		//Prevent assignment
		void operator=(InputManager const&);

		//Last mouse pos
		Vector* lastMousePos;

	public:
		//Destructor
		~InputManager();

		//Get the only instance of the InputManager
		static InputManager& getInstance() {
			static InputManager instance;
			return instance;
		};

		//Start the InputManager
		int startUp();

		//Shutdown the InputManager
		void shutDown();

		//Get input from keyboard and mouse
		void getInput() const;

		//Get last mouse pos
		Vector* getMousePos();
		void setMousePos(Vector* newMousePos);
	};

}

#endif __INPUT_MANAGER_H__