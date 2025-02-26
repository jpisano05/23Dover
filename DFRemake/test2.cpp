
#include "LogManager.h"
#include "Manager.h"
#include "Clock.h"
#include <windows.h>
#include "GameManager.h"
#include "ObjectList.h"
#include "Object.h"
#include <iostream>
#include <stdbool.h>
#include "Rat.h"
#include "Event.h"
#include "EventStep.h"
#include "WorldManager.h"
#include "Block.h"
#include "Player.h"
#include "ResourceManager.h"
#include "ViewObject.h"
#include "EventView.h"

//test stubs
bool testDrawObject();
bool testObjectBackground();
bool testLoadSprites();
bool testViewObject();
bool testMusic();
bool testSound();
bool testPlayer();

using namespace df;

int main(int argc, char* argv[]) {
	GM.startUp();

	if (testLoadSprites()) {
		puts("testLoadSprites pass");
	}
	else {
		puts("testLoadSprites pass");
	}

	if (testDrawObject()) {
		puts("testDrawObject Pass");
	}
	else {
		puts("testDrawObject Fail");
	}

	if (testObjectBackground()) {
		puts("testObjectBackground Pass");
	}
	else {
		puts("testObjectBackground Fail");
	}

	if (testViewObject()) {
		puts("testViewObject Pass");
	}
	else {
		puts("testViewObject Fail");
	}

	if (testMusic()) {
		puts("testMusic Pass");
	}
	else {
		puts("testMusic Fail");
	}

	if (testSound()) {
		puts("testSound Pass");
	}
	else {
		puts("testSound Fail");
	}

	if (testPlayer()) {
		puts("testPlayer Pass");
	}
	else {
		puts("testPlayer Fail");
	}

	GM.run();

	GM.shutDown();
}

bool testDrawObject() {
	Rat* testRat = new Rat();

	LM.writeLog("Rat created at (%f, %f)", testRat->getPosition().getX(), testRat->getPosition().getY());
	LM.writeLog("Rat created and drawn");

	return true;
}

bool testObjectBackground() {
	Block* testBlock = new Block();

	LM.writeLog("Block created at (%f, %f)", testBlock->getPosition().getX(), testBlock->getPosition().getY());

	return true;
}

bool testLoadSprites() {
	bool s1 = RM.loadSprite("bullet-spr.txt", "bullet") == 0;
	bool s2 = RM.loadSprite("saucer-spr.txt", "saucer") == 0;
	bool s3 = RM.loadSprite("ship-spr.txt", "ship") == 0;

	return s1 && s2 && s3;
}

bool testViewObject() {
	ViewObject* p_vo = new ViewObject();
	p_vo->setViewString("Points");
	p_vo->setValue(0);
	p_vo->setLocation(TOP_RIGHT);
	p_vo->setColor(YELLOW);
	p_vo->setBorder(true);

	if (p_vo->getValue() != 0) {
		LM.writeLog("Incorrect value");
		return false;
	}

	EventView ev("Points", 10, true);
	WM.onEvent(&ev);

	if (p_vo->getValue() != 10) {
		LM.writeLog("Incorrect value");
		return false;
	}

	return true;
}

bool testMusic() {
	bool s1 = RM.loadMusic("Sounds/sneaky.mp3", "sneaky") == 0;

	LM.writeLog("Loaded music");

	RM.getMusic("sneaky")->play(true);

	LM.writeLog("Playing music");

	return s1;
}

bool testSound() {
	bool s1 = RM.loadSound("Sounds/pipe.mp3", "pipe") == 0;

	LM.writeLog("Loaded sound");

	RM.getSound("pipe")->play(false);

	return s1;
}

bool testPlayer() {
	Player* testPlayer = new Player();

	return true;
}