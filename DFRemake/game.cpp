
// Engine includes
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Color.h"
#include "MouseTrap.h"
#include "WorldManager.h"
#include "Vector.h"
#include "Rat.h"
#include "Player.h"
#include "Mice.h"
#include "Path.h"
#include "ScoreManager.h"
#include "GameStart.h"

// Prototypes
void loadResources(void);
void populateWorld(void);

int main(int argc, char* argv[]) {
	// Start up game manager.
	if (GM.startUp()) {
		LM.writeLog("Error starting game manager!");
		GM.shutDown();
		return 1;
	}
	// Set flush of logfile during development (when done, make false).
	LM.setFlush(true);

	// Load game resources.
	loadResources();

	// Populate game world with some objects.
	populateWorld();

	// Run game (this blocks until game loop is over).
	GM.run();

	// Shut everything down.
	GM.shutDown();

	return 0;
}

// Load resources (sprites, sound effects, music).
void loadResources(void) {

	RM.loadSprite("Sprites/mouse-left-spr.txt", "mouse-left");
	RM.loadSprite("Sprites/mouse-right-spr.txt", "mouse-right");
	RM.loadSprite("Sprites/mouse-up-spr.txt", "mouse-up");
	RM.loadSprite("Sprites/mouse-down-spr.txt", "mouse-down");

	RM.loadSprite("Sprites/mouse-repellent-spr.txt", "mouse-repellent");
	RM.loadSprite("Sprites/glue-trap-spr.txt", "glue-trap");
	RM.loadSprite("Sprites/mouse-trap-spr.txt", "mouse-trap");

	RM.loadSprite("Sprites/path-spr.txt", "path");

	RM.loadSprite("Sprites/mouse-trap-button-spr.txt", "mouse-trap-button");
	RM.loadSprite("Sprites/glue-trap-button-spr.txt", "glue-trap-button");
	RM.loadSprite("Sprites/mouse-repellent-button-spr.txt", "mouse-repellent-button");
	RM.loadSprite("Sprites/send-wave-button.txt", "send-wave-button");

	RM.loadSprite("Sprites/game-name-spr.txt", "game-name");
	RM.loadSprite("Sprites/instructions-spr.txt", "instructions");
}

// populate world
void populateWorld() {
	new GameStart();
}
