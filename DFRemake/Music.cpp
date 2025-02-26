#pragma once

//Includes
#include "Music.h"
#include "LogManager.h"

using namespace df;

//Constructor
Music::Music() {
	m_label = "";
}

//Associate music buffer with file
int Music::loadMusic(std::string filename) {
	if (m_music.openFromFile(filename) == false) {
		return -1;
	}

	return 0;
}

//Set label associated with music
void Music::setLabel(std::string new_label) {
	m_label = new_label;
}

std::string Music::getLabel() const {
	return m_label;
}

//Play music
void Music::play(bool loop) {
	LM.writeLog("Trying to play music");

	m_music.setLooping(loop);

	LM.writeLog("looping set");

	m_music.play();

	LM.writeLog("Music playing!");
}

//Stop music
void Music::stop() {
	m_music.stop();
}

//Pause music
void Music::pause() {
	m_music.pause();
}

//Return pointer
sf::Music* Music::getMusic() {
	return &m_music;
}