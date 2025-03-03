#pragma once
//Includes
#include "Animation.h"
#include "ResourceManager.h"
#include "LogManager.h"

using namespace df;

//Constructor
Animation::Animation() {
	m_p_sprite = NULL;
	m_name = "";
	m_index = 0;
	m_slowdown_count = 0;
}

//Getter/setter for sprite
void Animation::setSprite(df::Sprite* p_new_sprite) {
	m_p_sprite = p_new_sprite;
	m_index = 0;
}
df::Sprite* Animation::getSprite() const {
	return m_p_sprite;
}

//Getter/setter for sprite name
void Animation::setName(std::string new_name) {
	m_name = new_name;
}
std::string Animation::getName() const {
	return m_name;
}

//Getter/setter for frame index
void Animation::setIndex(int new_index) {
	m_index = new_index;
}
int Animation::getIndex() const {
	return m_index;
}

//Getter/setter for animation slowdown counter
void Animation::setSlowdownCount(int new_slowdown_count) {
	m_slowdown_count = new_slowdown_count;
}
int Animation::getSlowdownCount() const {
	return m_slowdown_count;
}

//Draw frame at position
int Animation::draw(Vector position) {
	if (m_p_sprite == NULL) {
		return -1;
	}

	m_p_sprite->draw(m_index, position);

	if (m_slowdown_count == -1) {
		return -1;
	}

	int count = getSlowdownCount();
	count++;

	if (count >= m_p_sprite->getSlowdown()) {
		count = 0;
		m_index++;

		if (m_index >= m_p_sprite->getFrameCount()) {
			m_index = 0;
		}
	}

	//LM.writeLog("Successfully drew a frame");

	setSlowdownCount(count);
	return 0;
}

//Get bounding box of sprite
df::Box Animation::getBox() const {
	if (!m_p_sprite) {
		Box box(Vector(-0.5,-0.5), 0.99, 0.99);
	}

	Vector corner(-1 * m_p_sprite->getWidth() / 2.0, -1 * m_p_sprite->getHeight() / 2.0);
	Box box(corner, m_p_sprite->getWidth(), m_p_sprite->getHeight());

	return box;
}