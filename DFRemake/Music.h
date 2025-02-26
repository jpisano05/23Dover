#pragma once

//Includes
#include <string>
#include <SFML/Audio.hpp>

namespace df {
	class Music {
	private:
		//Dont allow copy music
		Music(Music const&);
		//Dont allow assignment
		void operator=(Music const&);
		//The music
		sf::Music m_music;
		//Text label to ID music
		std::string m_label;
	public:
		//Constructor
		Music();

		//Associate music buffer with file
		int loadMusic(std::string filename);

		//Set label associated with music
		void setLabel(std::string new_label);
		std::string getLabel() const;

		//Play music
		void play(bool loop);

		//Stop music
		void stop();

		//Pause music
		void pause();

		//Return pointer
		sf::Music* getMusic();
	};
}