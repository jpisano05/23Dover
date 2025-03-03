
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
#include "ViewObject.h"
#include "EventView.h"
#include "MouseTrapButton.h"
#include "Reticle.h"

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
}

// populate world
void populateWorld() {
	// add path map 
	//df::Vector* t1p = new df::Vector(10, 10);
	//MouseTrap* t1 = new MouseTrap(*t1p);

	//Create the mouse reticle
	Reticle* r1 = new Reticle();

	MouseTrapButton* mtb1 = new MouseTrapButton();
	mtb1->setPosition(df::Vector(7, 22));

	//Create points counter
	ViewObject* p_vo = new ViewObject();
	p_vo->setViewString("Points");
	p_vo->setValue(0);
	p_vo->setLocation(BOTTOM_RIGHT);
	p_vo->setColor(YELLOW);
	p_vo->setBorder(true);

	//Update points for testing purposes/ initial points
	SM.setPoints(999);

	new Path();

	//Player* p1 = new Player();
	Mice* m1 = new Mice();
}
