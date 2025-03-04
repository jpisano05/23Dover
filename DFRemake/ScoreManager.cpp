#pragma once

//Includes
#include "ScoreManager.h"
#include "WorldManager.h"
#include "EventView.h"
#include "MiceAttack.h"
#include "LogManager.h"
#include "GameManager.h"

using namespace df;

//Constructor
ScoreManager::ScoreManager() {
	player_health = 100;
	curr_wave = 1;
	m_points = 0;
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
	int dif = newPoints - m_points;
	m_points = newPoints;

	EventView ev("Points", dif, true);
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
		// create a new attack and add it to the array of attacks
		// the # of mice is the wave number + attack number
		// the time between mice spawning is 8 - the wave number until the wave number hits 7,
		// in which case the time between mice becomes a constant 2
		attacks[i] = new MiceAttack(numWave + i, numWave < 7 ? 8 - numWave : 2);
	}

	// generate new wave with the attacks created above
	// logic for time_between makes the time between attacks equal to 10 - numWave until the wave number hits 7, 
	// in which case time between attack becomes a constant 4
	MiceWave* generatedWave = new MiceWave(attacks, numWave, numWave < 7 ? 10 - numWave : 4);

	LM.writeLog("Generated wave");

	return generatedWave;
}

//Getter/setter for player health
int ScoreManager::getHealth() const {
	return player_health;
}
void ScoreManager::setHealth(int newHealth) {
	int dif = newHealth - player_health;
	player_health = newHealth;

	if (player_health <= 0) {
		GM.setGameOver(true);
	}

	EventView ev("HP", dif, true);
	WM.onEvent(&ev);
}