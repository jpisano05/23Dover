//Includes
#include <string>
#include <SFML/Audio.hpp>

namespace df {
	class Sound {
	private:
		//The sound
		sf::Sound* m_p_sound;
		//SFML sound buffer associated with sound
		sf::SoundBuffer m_sound_bugger;
		//Text label to ID sound
		std::string m_label;

	public:
		//Constructor
		Sound();
		//Destructor
		~Sound();

		//Load sound buffer from file
		int loadSound(std::string filename);
		//Getter/setter for label
		void setLabel(std::string new_label);
		std::string getLabel() const;

		//Play sound
		void play(bool loop);

		//Stop sound
		void stop();

		//Pause sound
		void pause();

		//Getter for the sound
		sf::Sound getSound() const;
	};
}