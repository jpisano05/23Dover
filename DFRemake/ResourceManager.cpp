//Includes
#include "ResourceManager.h"
#include <fstream>
#include "LogManager.h"

using namespace df;

//Constructor
ResourceManager::ResourceManager() {

}

//Destructor
ResourceManager::~ResourceManager() {

}

//Start the ResourceManager
int ResourceManager::startUp() {
	m_sprite_count = 0;

	Manager::startUp();

	return 0;
}

//Shutdown the ResourceManager
void ResourceManager::shutDown() {
	for (int i = 0; i < m_sprite_count - 1; i++) {
		if (m_p_sprite[i] != NULL) {
			delete(m_p_sprite[i]);
		}
	}

	m_sprite_count = 0;

	Manager::shutDown();
}

//Load sprite from file
int ResourceManager::loadSprite(std::string filename, std::string label) {
	if (m_sprite_count >= MAX_SPRITES) {
		return -1;
	}

	std::ifstream s_file(filename);

	std::string line1;
	int frames = 0;
	if (s_file.is_open()) {
		if (std::getline(s_file, line1)) {
			frames = atoi(line1.c_str());

			LM.writeLog("Number of frames: %s", line1.c_str());
			LM.writeLog("Number of frames: %d", frames);
		}
	}
	else {
		LM.writeLog("FILE DIDNT OPEN, PROBABLY A FILE NAME ERROR");
	}

	std::string line2;
	std::getline(s_file, line2);
	int width = atoi(line2.c_str());

	LM.writeLog("Width: %d", width);

	std::string line3;
	std::getline(s_file, line3);
	int height = atoi(line3.c_str());

	LM.writeLog("Height: %d", height);

	std::string line4;
	std::getline(s_file, line4);
	int slowdown = atoi(line4.c_str());
	LM.writeLog("Slowdown: %d", slowdown);
	
	std::string line5;
	std::getline(s_file, line5);
	Color color;
	if (line5 == "black") {
		color = BLACK;
	}
	else if (line5 == "red") {
		color = RED;
	}
	else if (line5 == "green") {
		color = GREEN;
	}
	else if (line5 == "yellow") {
		color = YELLOW;
	}
	else if (line5 == "blue") {
		color = BLUE;
	}
	else if (line5 == "magenta") {
		color = MAGENTA;
	}
	else if (line5 == "cyan") {
		color = CYAN;
	}
	else {
		color = WHITE;
	}

	Sprite* new_sprite = new Sprite(frames);
	new_sprite->setHeight(height);
	new_sprite->setWidth(width);
	new_sprite->setSlowdown(slowdown);
	new_sprite->setColor(color);

	for (int i = 0; i < frames; i++) {
		std::string temp;
		for (int j = 0; j < height; j++) {
			std::string read_s;
			std::getline(s_file, read_s);
			temp += read_s;
			LM.writeLog("Building frame: %s", temp.c_str());
		}

		Frame* tempf = new Frame(width, height, temp);
		new_sprite->addFrame(*tempf);
		LM.writeLog("Added frame! %s", temp.c_str());
	}

	s_file.close();

	new_sprite->setLabel(label);
	m_p_sprite[m_sprite_count] = new_sprite;
	m_sprite_count++;

	LM.writeLog("loaded new sprite with frames equal to: %d", new_sprite->getFrameCount());
	return 0;
}

//Unload sprite with indicated label
int ResourceManager::unloadSprite(std::string label) {
	for (int i = 0; i < m_sprite_count - 1; i++) {
		if (m_p_sprite[i]->getLabel() == label) {
			delete(m_p_sprite[i]);

			for (int j = i; j < m_sprite_count - 2; j++) {
				m_p_sprite[j] = m_p_sprite[j + 1];
			}

			m_sprite_count--;

			return 0;
		}
	}

	return -1;
}

//Find sprite with indicated label
df::Sprite* ResourceManager::getSprite(std::string label) const {
	for (Sprite* s : m_p_sprite) {
		if (s->getLabel() == label) {
			return s;
		}
	}

	return NULL;
}

//Load sound from file
int ResourceManager::loadSound(std::string filename, std::string label) {
	if (sound_count == MAX_SOUNDS) {
		return -1;
	}

	if (sound[sound_count].loadSound(filename) == -1) {
		return -1;
	}

	sound[sound_count].setLabel(label);
	sound_count++;
	return 0;
}
//Remove sound with indicated label
int ResourceManager::unloadSound(std::string label) {
	for (int i = 0; i < sound_count - 1; i++) {
		if (label == sound[i].getLabel()) {
			for (int j = 1; j < sound_count - 2; j++) {
				sound[j] = sound[j + 1];
			}

			sound_count--;
			return 0;
		}
	}
	return -1;
}
//Find sound with label
Sound* ResourceManager::getSound(std::string label) {
	LM.writeLog("Sound count is %d", sound_count);
	for (int i = 0; i < sound_count; i++) {
		if (label == sound[i].getLabel()) {
			LM.writeLog("Correct sound found");
			return (&sound[i]);
		}
		else {
			LM.writeLog("Label: %s didn't equal %s", label.c_str(), sound[i].getLabel().c_str());
		}
	}

	LM.writeLog("Sound not found");

	return NULL;
}

//Associate file with Music
int ResourceManager::loadMusic(std::string filename, std::string label) {
	if (music_count == MAX_MUSICS) {
		return -1;
	}

	if (music[music_count].loadMusic(filename) == -1) {
		return -1;
	}

	music[music_count].setLabel(label);
	music_count++;

	LM.writeLog("Music safely loaded");

	return 0;
}
//Remove lbale for Music with indicated label
int ResourceManager::unloadMusic(std::string label) {
	for (int i = 0; i < music_count - 1; i++) {
		if (label == music[i].getLabel()) {
			music[i].setLabel("");

			music_count--;
			return 0;
		}
	}
	return -1;
}
//Find music with indicated label
Music* ResourceManager::getMusic(std::string label) {
	LM.writeLog("Music count is %d", music_count);
	for (int i = 0; i < music_count; i++) {
		if (label == music[i].getLabel()) {
			LM.writeLog("Found searched for music");
			return (&music[i]);
		}
		else {
			LM.writeLog("Label: %s didn't equal %s", label, music[i].getLabel().c_str());
		}
	}

	LM.writeLog("Music not found");
	return NULL;
}