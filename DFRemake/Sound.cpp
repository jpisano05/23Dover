//Includes
#include "Sound.h"
#include "LogManager.h"

using namespace df;

//Constructor
Sound::Sound() {
	m_p_sound = NULL;
	m_label = "";
}
//Destructor
Sound::~Sound() {
	if (m_p_sound != NULL) {
		delete(m_p_sound);
	}
}

//Load sound buffer from file
int Sound::loadSound(std::string filename) {
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	if (buffer->loadFromFile(filename) == false) {
		LM.writeLog("issue loading");
		return -1;
	}

	m_p_sound = new sf::Sound(*buffer);

	LM.writeLog("Loaded sound fine");
	return 0;
}
//Getter/setter for label
void Sound::setLabel(std::string new_label) {
	m_label = new_label;
}
std::string Sound::getLabel() const {
	return m_label;
}

//Play sound
void Sound::play(bool loop) {
	if (m_p_sound == NULL) {
		return;
	}

	LM.writeLog("trying to play sound");
	m_p_sound->setLooping(loop);
	LM.writeLog("set looping");
	m_p_sound->play();
	LM.writeLog("Successfuly played sound;");
}

//Stop sound
void Sound::stop() {
	m_p_sound->stop();
}

//Pause sound
void Sound::pause() {
	m_p_sound->pause();
}

//Getter for the sound
sf::Sound Sound::getSound() const {
	return *m_p_sound;
}