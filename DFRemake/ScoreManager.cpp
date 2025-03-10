#pragma once

//Includes
#include "ScoreManager.h"
#include "WorldManager.h"
#include "EventView.h"
#include "MiceAttack.h"
#include "LogManager.h"

using namespace df;

//Constructor
ScoreManager::ScoreManager() {

}

//Destructor
ScoreManager::~ScoreManager() {

}

//Start the InputManager
int ScoreManager::startUp() {
	m_points = 0;
	curr_wave = 1;

	Manager::startUp();

	return 0;
}

//Shutdown the InputManager
void ScoreManager::shutDown() {

	Manager::shutDown();
}

//Getter/setter for points
int ScoreManager::getPoints() const {
	return m_points;
}
void ScoreManager::setPoints(int newPoints) {
	m_points = newPoints;

	EventView ev("Points", newPoints, true);
	WM.onEvent(&ev);
}

//Getter/setter for wave num
int ScoreManager::getWave() const {
	return curr_wave;
}
void ScoreManager::setWave(int newWave) {
	int dif = newWave - curr_wave;
	curr_wave = newWave;

	LM.writeLog("calculated difference");

	EventView ev("Wave", dif, true);
	LM.writeLog("Created the event view");
	WM.onEvent(&ev);

	LM.writeLog("Updated wave");
}

//Generate a wave using a preset formula
MiceWave* ScoreManager::generateWave(int numWave) {
	//Need 3 attacks, wave number, and time between
	MiceAttack* attacks[3];
	for (int i = 0; i < 3; i++) {
		attacks[i] = new MiceAttack(numWave + i, 1);
	}

	MiceWave* generatedWave = new MiceWave(attacks, numWave, 5);

	LM.writeLog("Generated wave");

	return generatedWave;
}