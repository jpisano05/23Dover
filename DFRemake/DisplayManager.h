#pragma once

#ifndef __DISPLAY_MANAGER_H__
#define __DISPLAY_MANAGER_H__
#define DM df::DisplayManager::getInstance()

//includes
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "Manager.h"
#include <SFML/Graphics.hpp>
#include "Color.h"
#include "Manager.h"
#include "Vector.h"

//Namespace def
namespace df {

	enum Justification {
		LEFT_JUSTIFIED,
		CENTER_JUSTIFIED,
		RIGHT_JUSTIFIED,
	};

	//Defaults for SFML window
	const int WINDOW_HORIZONTAL_PIXELS_DEFAULT = 1024;
	const int WINDOW_VERTICAL_PIXELS_DEFAULT = 768;
	const int WINDOW_HORIZONTAL_CHARS_DEFAULT = 80;
	const int WINDOW_VERTICAL_CHARS_DEFAULT = 24;
	
	//At current defaults values are: 12.8, 32
	const float WINDOW_HP_TO_HC = (float)WINDOW_HORIZONTAL_PIXELS_DEFAULT / (float)WINDOW_HORIZONTAL_CHARS_DEFAULT;
	const float WINDOW_VP_TO_VC = (float)WINDOW_VERTICAL_PIXELS_DEFAULT / (float)WINDOW_VERTICAL_CHARS_DEFAULT;

	const int WINDOW_STYLE_DEFAULT = sf::Style::Titlebar;
	const sf::Color WINDOW_BACKGROUND_COLOR_DEFAULT = sf::Color::Black;
	const std::string WINDOW_TITLE_DEFAULT = "Dragonfly";
	const std::string FONT_FILE_DEFAULT = "df-font.ttf";

	//Start of class definition
	class DisplayManager : public Manager {
	private:
		//Constructor
		DisplayManager();
		//Prevent copies
		DisplayManager(DisplayManager const&);
		//Prevent assignment
		void operator=(DisplayManager const&);
		//Font used for ASCII
		sf::Font m_font;
		//Pointer to SFML Window
		sf::RenderWindow* m_p_window;
		//Horizontal Pixels
		int m_window_horizontal_pixels;
		//Vertical Pixels
		int m_window_vertical_pixels;
		//Horizontal ASCII Spaces
		int m_window_horizontal_chars;
		//Vertical ASCII Spaces
		int m_window_vertical_chars;

		//Helper Functions
		float charHeight() const;
		float charWidth() const;

	public:
		//Destructor
		~DisplayManager();

		//Get the only instance of the DisplayManager
		static DisplayManager& getInstance() {
			static DisplayManager instance;
			return instance;
		};

		//Start the DisplayManager
		int startUp();

		//Shutdown the DisplayManager
		void shutDown();

		//Draw character at window location(x,y) with given color
		//0 good, -1 error
		int drawCh(Vector world_pos, char ch, Color color) const;

		//Render current window buffer
		//0 good, -1 error
		int swapBuffers();

		//Getters
		int getHorizontal() const;
		int getVertical() const;
		int getHorizontalPixels() const;
		int getVerticalPixels() const;
		sf::RenderWindow* getWindow() const;

		//Converts from DF color to SFML color
		sf::Color convertColor(df::Color c);

		Vector spacesToPixels(Vector spaces) const;
		Vector pixelsToSpaces(Vector pixels) const;

		//Draw string at x,y
		int drawString(Vector pos, std::string str, Justification just, Color color);
	};

}

#endif __DISPLAY_MANAGER_H__