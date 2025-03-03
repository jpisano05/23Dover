#pragma once

//Includes
#include "DisplayManager.h"
#include "LogManager.h"
#include "WorldManager.h"

using namespace df;

//Constructor
DisplayManager::DisplayManager() {
	m_p_window = NULL;

	m_window_horizontal_chars = WINDOW_HORIZONTAL_CHARS_DEFAULT;
	m_window_horizontal_pixels = WINDOW_HORIZONTAL_PIXELS_DEFAULT;
	m_window_vertical_chars = WINDOW_VERTICAL_CHARS_DEFAULT;
	m_window_vertical_pixels = WINDOW_VERTICAL_PIXELS_DEFAULT;
}

//Destructor
DisplayManager::~DisplayManager() {
	
}

//Start the DisplayManager
int DisplayManager::startUp() {
	if (m_p_window != NULL) {
		return 0;
	}

	int window_horizontal = WINDOW_HORIZONTAL_PIXELS_DEFAULT;
	int window_vertical = WINDOW_VERTICAL_PIXELS_DEFAULT;

	sf::Vector2u dummy = sf::Vector2u(window_horizontal, window_vertical);

	m_p_window = new sf::RenderWindow(sf::VideoMode({ dummy }), "Title - Dragonfly", sf::Style::Titlebar);

	m_p_window->setMouseCursorVisible(false);

	m_p_window->setVerticalSyncEnabled(true);

	m_p_window->setKeyRepeatEnabled(false);

	if (m_font.openFromFile(FONT_FILE_DEFAULT) == false) {
		LM.writeLog("Failed to open font file");
		return -1;
	}

	Manager::startUp();
	return 0;
}

//Shutdown the DisplayManager
void DisplayManager::shutDown() {
	Manager::shutDown();
}

//Draw character at window location(x,y) with given color
//0 good, -1 error
int DisplayManager::drawCh(Vector world_pos, char ch, df::Color color) const {
	Vector view_pos = WM.worldToView(world_pos);
	
	if (m_p_window == NULL) {
		return -1;
	}

	LM.writeLog("Trying to draw %c", ch);

	Vector pixel_pos = spacesToPixels(view_pos);
	LM.writeLog("Calculated pixels");

	static sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));
	rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
	rectangle.setPosition({pixel_pos.getX() - charWidth()/10, pixel_pos.getY() + charHeight()/5});
	m_p_window->draw(rectangle);
	LM.writeLog("Drew rectangle");

	static sf::Text text(m_font);
	text.setString(ch);
	text.setStyle(sf::Text::Bold);

	if (charWidth() < charHeight()) {
		text.setCharacterSize(charWidth() * 2);
	}
	else {
		text.setCharacterSize(charHeight() * 2);
	}

	switch (color) {
	case YELLOW:
		text.setFillColor(sf::Color::Yellow);
		break;
	case RED:
		text.setFillColor(sf::Color::Red);
		break;
	case GREEN:
		text.setFillColor(sf::Color::Green);
		break;
	case BLUE:
		text.setFillColor(sf::Color::Blue);
		break;
	case MAGENTA:
		text.setFillColor(sf::Color::Magenta);
		break;
	case CYAN:
		text.setFillColor(sf::Color::Cyan);
		break;
	case WHITE:
		text.setFillColor(sf::Color::White);
		break;
	case BLACK:
		text.setFillColor(sf::Color::Black);
		break;
	}

	text.setPosition({ pixel_pos.getX(), pixel_pos.getY() });

	m_p_window->draw(text);
	LM.writeLog("Wrote text");

	return 0;
}

//Render current window buffer
//0 good, -1 error
int DisplayManager::swapBuffers() {
	LM.writeLog("Swapping buffers");
	if (m_p_window == NULL) {
		return -1;
	}

	m_p_window->display();
	LM.writeLog("Displayed");

	m_p_window->clear();
	LM.writeLog("Cleared");

	return 0;
}

//Getters
int DisplayManager::getHorizontal() const {
	return m_window_horizontal_chars;
}
int DisplayManager::getVertical() const {
	return m_window_vertical_chars;
}
int DisplayManager::getHorizontalPixels() const {
	return m_window_horizontal_pixels;
}
int DisplayManager::getVerticalPixels() const {
	return m_window_vertical_pixels;
}
sf::RenderWindow* DisplayManager::getWindow() const {
	return m_p_window;
}

float DisplayManager::charHeight() const {
	return ((float) getVerticalPixels()) / ((float) getVertical());
}
float DisplayManager::charWidth() const {
	return ((float)getHorizontalPixels()) / ((float)getHorizontal());
}
Vector DisplayManager::spacesToPixels(Vector spaces) const {
	LM.writeLog("Calculating");

	Vector solution = Vector((spaces.getX() * charWidth()), (spaces.getY() * charHeight()));

	LM.writeLog("Calculated");
	return solution;
}
Vector DisplayManager::pixelsToSpaces(Vector pixels) const {
	return Vector((pixels.getX() / charWidth()), (pixels.getY() / charHeight()));
}

//Converts from DF color to SFML color
sf::Color DisplayManager::convertColor(df::Color c) {
	switch (c) {
	case BLACK: return sf::Color::Black;
	case RED: return sf::Color::Red;
	case GREEN: return sf::Color::Green;
	case YELLOW: return sf::Color::Yellow;
	case BLUE: return sf::Color::Blue;
	case MAGENTA: return sf::Color::Magenta;
	case CYAN: return sf::Color::Cyan;
	case WHITE: return sf::Color::White;
	default: return sf::Color::White;
	}
}

//Draw string at x,y
int DisplayManager::drawString(Vector pos, std::string str, Justification just, Color color) {
	Vector starting_pos = pos;
	switch (just) {
	case CENTER_JUSTIFIED:
		starting_pos.setX(pos.getX() - str.size() / 2);
		break;
	case RIGHT_JUSTIFIED:
		starting_pos.setX(pos.getX() - str.size());
	case LEFT_JUSTIFIED:
	default:
		break;
	}

	for (int i = 0; i < str.size(); i++) {
		Vector temp_pos(starting_pos.getX() + i, starting_pos.getY());
		drawCh(temp_pos, str[i], color);
	}

	return 0;
}