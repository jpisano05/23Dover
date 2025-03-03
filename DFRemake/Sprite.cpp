//Includes
#include "Sprite.h"
#include "LogManager.h"

using namespace df;

//Destructor
Sprite::~Sprite() {
	if (!m_frame == NULL) {
		delete(m_frame);
	}
}
//Constructor with max frames
Sprite::Sprite(int max_frames) {
	m_frame_count = 0;
	m_width = 0;
	m_height = 0;
	m_frame = new Frame[max_frames];
	m_max_frame_count = max_frames;
	m_color = WHITE;
}

//Getter/setter width
void Sprite::setWidth(int new_width) {
	m_width = new_width;
}
int Sprite::getWidth() const {
	return m_width;
}
//Getter/setter height
void Sprite::setHeight(int new_height) {
	m_height = new_height;
}
int Sprite::getHeight() const {
	return m_height;
}
//Getter/setter color
void Sprite::setColor(Color new_color) {
	m_color = new_color;
}
Color Sprite::getColor() const {
	return m_color;
}
//Getter for frame
Frame Sprite::getFrame(int frame_number) const {
	return m_frame[frame_number];
}
//Add a frame
int Sprite::addFrame(Frame new_frame) {
	if (m_frame_count >= m_max_frame_count) {
		return -1;
	}
	else {
		m_frame[m_frame_count] = new_frame;
		m_frame_count++;
		return 0;
	}
	
}
//Getter/setter label
void Sprite::setLabel(std::string new_label) {
	m_label = new_label;
}
std::string Sprite::getLabel() const {
	return m_label;
}
//getter/setter slowdown
void Sprite::setSlowdown(int new_sprite_slowdown) {
	m_slowdown = new_sprite_slowdown;
}
int Sprite::getSlowdown() const {
	return m_slowdown;
}
//Draw current frame at position
int Sprite::draw(int frame_number, Vector position) const {
	//if (frame_number >= m_max_frame_count) {
		//LM.writeLog("Frame overflow for %d which is too many over %d", frame_number, m_max_frame_count);
		//LM.writeLog("Errored sprite data: %d, %d, %d, %d", m_max_frame_count, m_width, m_height, m_frame);
		//return -1;
	//}
	m_frame[frame_number].Draw(position, m_color);
	//LM.writeLog("Drew sprite ");
	return 0;
}

int Sprite::getFrameCount() const {
	return m_frame_count;
}