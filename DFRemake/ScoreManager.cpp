#pragma once

//Includes
#include "ScoreManager.h"
#include "WorldManager.h"
#include "EventView.h"

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
	curr_wave = newWave;
}