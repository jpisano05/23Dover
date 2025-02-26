#pragma once

//Includes
#include "Frame.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include <string>

using namespace df;

//constructor
Frame::Frame() {
	m_width = 0;
	m_height = 0;
	m_frame_str = "";
}
//Constructor with pre-set variables
Frame::Frame(int new_width, int new_height, std::string frame_str) {
	m_width = new_width;
	m_height = new_height;
	m_frame_str = frame_str;
}

//Getter/setter ofr width
void Frame::setWidth(int new_width) {
	m_width = new_width;
}
int Frame::getWidth() const {
	return m_width;
}

//Getter/setter of height
void Frame::setHeight(int new_height) {
	m_height = new_height;
}
int Frame::getHeight() const {
	return m_height;
}

//Getter/setter for frame characters
void Frame::setString(std::string new_frame_str) {
	m_frame_str = new_frame_str;
}
std::string Frame::getString() const {
	return m_frame_str;
}

//Draw self at position with color
int Frame::Draw(Vector position, Color color) const {
	LM.writeLog("Frame string is: %s", m_frame_str.c_str());
	//if (m_frame_str.isE() == 0) {
	//	LM.writeLog("Frame string is empty");
	//	return -1;
	//}

	int x_offset = m_width / 2;
	int y_offset = m_height / 2;

	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			LM.writeLog("Trying to draw %d", m_frame_str.size());
			LM.writeLog("Also: %c", m_frame_str.c_str()[0]);

			Vector temp_pos(position.getX() + x - x_offset, position.getY() + y - y_offset);
			DM.drawCh(temp_pos, m_frame_str.c_str()[y*m_width + x], color);

			LM.writeLog("Drew character %c", m_frame_str.c_str()[y * m_width + x]);
		}
	}

	LM.writeLog("Drew whole frame");
	return 0;
}