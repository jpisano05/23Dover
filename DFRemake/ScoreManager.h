#pragma once

#ifndef __SCORE_MANAGER_H__
#define __SCORE_MANAGER_H__
#define SM df::ScoreManager::getInstance()

//includes
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "Manager.h"
#include "MiceWave.h"

//Namespace def
namespace df {

	//Start of class definition
	class ScoreManager : public Manager {
	private:
		//Constructor
		ScoreManager();
		//Prevent copies
		ScoreManager(ScoreManager const&);
		//Prevent assignment
		void operator=(ScoreManager const&);

		//Keep track of points
		int m_points;
		//Current wave
		int curr_wave;

	public:
		//Destructor
		~ScoreManager();

		//Get the only instance of the InputManager
		static ScoreManager& getInstance() {
			static ScoreManager instance;
			return instance;
		};

		//Start the InputManager
		int startUp();

		//Shutdown the InputManager
		void shutDown();

		//Getter/setter for points
		int getPoints() const;
		void setPoints(int newPoints);
		
		//Getter/setter for wave num
		int getWave() const;
		void setWave(int newWave);

		//Generate a wave using a preset formula
		MiceWave* generateWave(int numWave);
	};

}

#endif __SCORE_MANAGER_H__