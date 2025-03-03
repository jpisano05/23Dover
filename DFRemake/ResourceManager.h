#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__
#define RM df::ResourceManager::getInstance()

//includes
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "Manager.h"
#include "Sprite.h"
#include "Sound.h"
#include "Music.h"

//Namespace def
namespace df {

	const int MAX_SPRITES = 500;
	const int MAX_SOUNDS = 50;
	const int MAX_MUSICS = 50;

	//Start of class definition
	class ResourceManager : public Manager {
	private:
		//Constructor
		ResourceManager();
		//Prevent copies
		ResourceManager(ResourceManager const&);
		//Prevent assignment
		void operator=(ResourceManager const&);

		//Array of sprites
		Sprite* m_p_sprite[MAX_SPRITES];

		int m_sprite_count; //Current num of sprites

		//Array of sound buffers
		Sound sound[MAX_SOUNDS];
		//Count number of loaded sounds
		int sound_count;
		//Array of music buffers
		Music music[MAX_MUSICS];
		//Count of number of loaded musics
		int music_count;
	public:
		//Destructor
		~ResourceManager();

		//Get the only instance of the ResourceManager
		static ResourceManager& getInstance() {
			static ResourceManager instance;
			return instance;
		};

		//Start the ResourceManager
		int startUp();

		//Shutdown the ResourceManager
		void shutDown();

		//Load sprite from file
		int loadSprite(std::string filename, std::string label);

		//Unload sprite with indicated label
		int unloadSprite(std::string label);

		//Find sprite with indicated label
		df::Sprite* getSprite(std::string label) const;

		//Load sound from file
		int loadSound(std::string filename, std::string label);
		//Remove sound with indicated label
		int unloadSound(std::string label);

		//Find sound with label
		Sound* getSound(std::string label);

		//Associate file with Music
		int loadMusic(std::string filename, std::string label);
		//Remove lbale for Music with indicated label
		int unloadMusic(std::string label);
		//Find music with indicated label
		Music* getMusic(std::string label);
	};

}

#endif __RESOURCE_MANAGER_H__