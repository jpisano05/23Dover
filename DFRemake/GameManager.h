#pragma once
#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__
#define GM df::GameManager::getInstance()

//includes
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "Manager.h"

//Namespace def
namespace df {

	const int FRAME_TIME_DEFAULT = 33;

	//Start of class definition
	class GameManager : public Manager {
	private:
		//Constructor
		GameManager();
		//Prevent copies
		GameManager(GameManager const&);
		//Prevent assignment
		void operator=(GameManager const&);
		//Whether the game is ended, determines if game loop should run
		bool game_over;
		//Target time for the frame rate
		int frame_time;

	public:
		//Destructor
		~GameManager();

		//Get the only instance of the LogManager
		static GameManager& getInstance() {
			static GameManager instance;
			return instance;
		};

		//Start the LogManager
		int startUp();

		//Shutdown the LogManager
		void shutDown();

		//Run game loop
		void run();

		//Setter for game_over
		void setGameOver(bool new_game_over = true);

		//Getter for game_over
		bool getGameOver() const;

		//Getter for frame_time, frame_time is in ms
		int getFrameTime() const;
	};

}

#endif __GAME_MANAGER_H__