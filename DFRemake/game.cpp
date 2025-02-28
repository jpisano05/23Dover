
// Engine includes
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Color.h"

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

	// Show splash screen.
	df::splash();

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

	RM.loadSprite("Sprites/mouse-spr.txt", "mouse");
	RM.loadSprite("Sprites/mouse-repellent-spr.txt", "mouse-repellent");
	RM.loadSprite("Sprites/glue-trap-spr.txt", "glue-trap");

}

// populate world
void populateWorld() {
	// add map 
}
