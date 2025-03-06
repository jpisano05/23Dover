
// Engine includes.
#include "EventStep.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "EventKeyboard.h"

// Game Includes
#include "GameOver.h"
#include "GameStart.h"

GameOver::GameOver() {

	// Set type
	setType("GameOver");


	// Link to "message" sprite.
	if (setSprite("game-over") == 0)
		time_to_live = getAnimation().getSprite()->getFrameCount() * getAnimation().getSprite()->getSlowdown();
	else
		time_to_live = 0;

	// Put in center of window.
	setLocation(df::CENTER_CENTER);

	/*
	// Play "game over" sound.
	df::Sound* p_sound = RM.getSound("game over");
	if (p_sound)
		p_sound->play();
	*/
}

int GameOver::eventHandler(const df::Event* p_e) {

	// If step event, call step()
	//if (p_e->getType() == "step") {
	//	step();
	//	return 1;
	//}
	if (p_e->getType() == KEYBOARD_EVENT) {
		EventKeyboard* p_keyboard_event = (EventKeyboard*)p_e;
		switch (p_keyboard_event->getKey()) {
		case Keyboard::C: 			// play
			restart();
			break;
		}
	}

	// If get here, have ignored this event.
	return 0;
}

// Count down to end of "message".
//void GameOver::step() {
//	time_to_live--;
//	if (time_to_live <= 0)
//		WM.markForDelete(this);
//}

// Override default draw so as not to display "value".
int GameOver::draw() {
	return df::Object::draw();
}

void GameOver::restart() {
	WM.markForDelete(this);
	GM.setGameOver();
}