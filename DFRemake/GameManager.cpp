#pragma once

//Includes
#include "GameManager.h"
#include <stdio.h>
#include <stdarg.h>
#include "Clock.h"
#include "LogManager.h"
#include <Windows.h>
#include "ObjectList.h"
#include "Object.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "ScoreManager.h"


using namespace df;

//Constructor
GameManager::GameManager() {
	frame_time = FRAME_TIME_DEFAULT;
	game_over = false;
}

//Destructor
GameManager::~GameManager() {
	
}

//Opens log file for editing and sets m_is_started to true
int GameManager::startUp() {
	timeBeginPeriod(1);
	int success = LM.startUp();

	int wSuccess = WM.startUp();
	LM.writeLog("Started WM");
	int dSuccess = DM.startUp();
	LM.writeLog("Started DM");
	int iSuccess = IM.startUp();
	LM.writeLog("Started IM");
	int rSuccess = RM.startUp();

	SM.startUp();

	WM.setBoundary(Box(Vector(0, 0), DM.getHorizontal(), DM.getVertical()));
	WM.setView(Box(Vector(0, 0), DM.getHorizontal(), DM.getVertical()));

	return success;
}

//Closes log file and sets m_is_started to false
void GameManager::shutDown() {
	timeBeginPeriod(1);

	IM.shutDown();
	DM.shutDown();
	WM.shutDown();
	LM.shutDown();
	RM.shutDown();
	SM.shutDown();
	

	setGameOver(true);
}

//Runs the game loop
void GameManager::run() {
	Clock* frameClock = new Clock();
	long int runTime = 0;
	int counter = 0;

	LM.writeLog("Started running game manager");

	while (!game_over) {
		frameClock->delta();

		//Send step event to all objects
		EventStep* step = new EventStep();
		onEvent(step);
		//LM.writeLog("Sent step");

		//Get input
		IM.getInput();
		//LM.writeLog("Got input");

		//Update objects in the world manager
		WM.update();
		//LM.writeLog("World updated");
		WM.draw();
		//LM.writeLog("World drawn");
		DM.swapBuffers();
		//LM.writeLog("Swapped buffers");

		//LM.writeLog("%d", frame_time - (runTime / 1000));

		runTime = frameClock->delta();
		LM.writeLog("Run time: %i", runTime);
		if (runTime / 1000 < frame_time) {
			Sleep(frame_time - (runTime / 1000));
		}
	}
}

//Setter for game_over
void GameManager::setGameOver(bool new_game_over) {
	game_over = new_game_over;
}

//Getter for game_over
bool GameManager::getGameOver() const {
	return game_over;
}

//Getter for frame_time
int GameManager::getFrameTime() const {
	return frame_time;
}