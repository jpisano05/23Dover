
// Engine Includes
#include "EventKeyboard.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "DisplayManager.h"

// Game Includes
#include "GameStart.h"
#include "ScoreManager.h"
#include "Reticle.h"
#include "MouseTrapButton.h"
#include "SendWaveButton.h"
#include "Path.h"
#include "Object.h"
#include "WorldManager.h"
#include "GlueTrapButton.h"
#include "MouseRepellentButton.h"
#include "Instructions.h"

GameStart::GameStart() {

    // set type
    setType("GameStart");

    // set sprite
    setSprite("game-name");

	setPosition(df::Vector(DM.getHorizontal() / 2, DM.getVertical() / 2));
    /*
    // Play start music.
    p_music = RM.getMusic("start music");
    playMusic();
    */
}
/*
// Play start music.
void GameStart::playMusic() {
    if (p_music)
        p_music->play();
}
*/

int GameStart::eventHandler(const df::Event* p_e) {

    if (p_e->getType() == KEYBOARD_EVENT) {
        EventKeyboard* p_keyboard_event = (EventKeyboard*)p_e;
        switch (p_keyboard_event->getKey()) {
        case Keyboard::P: 			// play
            start();
            break;
		case Keyboard::I:
			new Instructions();
			WM.markForDelete(this);
			break;
        case Keyboard::Q:			// quit
            GM.setGameOver();
            break;
        default: // Key is not handled.
            break;
        }
        return 1;
    }

    // If get here, have ignored this event.
    return 0;
}

// Override default draw so as not to display "value".
int GameStart::draw() {
    return Object::draw();
}

void GameStart::start() {

    // Pause start music.
    //p_music->pause();

	// add path map 
	//df::Vector* t1p = new df::Vector(10, 10);
	//MouseTrap* t1 = new MouseTrap(*t1p);

	//Create the mouse reticle
	Reticle* r1 = new Reticle();

	//Create the path
	//Path* p1 = new Path();

	//Create buttons
	MouseTrapButton* mtb1 = new MouseTrapButton();
	//mtb1->setPosition(df::Vector(30, 20));
	GlueTrapButton* gtb1 = new GlueTrapButton();
	MouseRepellentButton* mrb1 = new MouseRepellentButton();
	SendWaveButton* swb1 = new SendWaveButton();
	//swb1->setPosition(df::Vector(50, 20));

	//Create points counter
	ViewObject* p_vo = new ViewObject();
	p_vo->setViewString("Points");
	p_vo->setValue(0);
	p_vo->setLocation(BOTTOM_RIGHT);
	p_vo->setColor(YELLOW);
	p_vo->setBorder(true);

	//Create waves counter
	ViewObject* w_vo = new ViewObject();
	w_vo->setViewString("Wave");
	w_vo->setValue(0);
	w_vo->setLocation(BOTTOM_LEFT);
	w_vo->setColor(YELLOW);
	w_vo->setBorder(true);

	//Create health counter
	ViewObject* h_vo = new ViewObject();
	h_vo->setViewString("HP");
	h_vo->setValue(100);
	h_vo->setLocation(BOTTOM_CENTER);
	h_vo->setColor(YELLOW);
	h_vo->setBorder(true);


	//Update points for testing purposes/ initial points
	SM.setPoints(100);

	new Path();

	//Player* p1 = new Player();
	//Mice* m1 = new Mice();

	// delete game start screen
	WM.markForDelete(this);
}
