/*#include "LogManager.h"
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

//test stubs
bool testLogManager();
bool testClockTiming();
bool testStepEvent();
bool testObjectList();
bool testWorldManager();
bool testGameManager();

using namespace df;

int main(int argc, char* argv[]) {
	GM.startUp();
	if (testLogManager()) {
		puts("LogManager Pass");
	}
	else {
		puts("LogManager Fail");
	}

	if (testClockTiming()) {
		puts("Clock Pass");
	}
	else {
		puts("Clock Fail");
	}

	if (testStepEvent()) {
		puts("StepEvent Pass");
	}
	else {
		puts("StepEvent Fail");
	}

	if (testObjectList()) {
		puts("Object Pass");
	}
	else {
		puts("Object Fail");
	}

	if (testWorldManager()) {
		puts("WorldManager Pass");
	}
	else {
		puts("WorldManager Fail");
	}
	
	if (testGameManager()) {
		puts("GameManager Pass");
	}
	else {
		puts("GameManager Fail");
	}

	GM.shutDown();
}

bool testLogManager() {
	LM.writeLog("This Log Manager Works");

	return true;
}

bool testClockTiming() {
	Clock* testClock = new Clock();
	testClock->delta();
	Sleep(1000);

	int t = testClock->split() / 1000000;

	LM.writeLog("split time t is %d", t);

	if (t != 1) {
		LM.writeLog("split time t is %d", t);
		return false;
	}

	LM.writeLog("%s passed.\n", __func__);
	return true;
}

bool testStepEvent() {
	Rat testRat = Rat();

	EventStep* testStep = new EventStep();

	int prev_x = testRat.getPosition().getX();

	testRat.eventHandler(testStep);

	int last_x = testRat.getPosition().getX();

	if (prev_x == last_x) {
		LM.writeLog("Rat wasn't moved by step");
		return false;
	}

	LM.writeLog("Rat moved from %d to %d", prev_x, last_x);
	return true;
}

bool testObjectList() {
	df::Object* test1 = new df::Object();
	df::Object* test2 = new df::Object();
	df::Object* test3 = new df::Object();

	df::ObjectList* testList = new df::ObjectList();

	testList->insert(test1);
	testList->insert(test2);
	testList->insert(test3);

	LM.writeLog("%d", testList->getCount());

	testList->remove(test2);

	LM.writeLog("%d", testList->getCount());
	LM.writeLog("%d", test3->getId());

	if (testList->getCount() != 2) {
		LM.writeLog("Incorrect number of values in testList");
		return false;
	}

	LM.writeLog("ObjectList fully functional");
	return true;
}

//Tests both world manager
bool testWorldManager() {
	//Do some house cleaning
	ObjectList temp = WM.getAllObjects();

	LM.writeLog("%d", temp.getCount());

	for (int i = 0; i < temp.getCount(); i++) {
		LM.writeLog("Deleted %d", i);
		WM.markForDelete(temp[i]);
	}

	WM.update();

	LM.writeLog("%d", WM.getAllObjects().getCount());

	if (!WM.getAllObjects().isEmpty()) {
		LM.writeLog("Emptying failed");
		return false;
	}

	Rat* testRat1 = new Rat();
	Rat* testRat2 = new Rat();
	Rat* testRat3 = new Rat();

	int numObjects = WM.getAllObjects().getCount();

	LM.writeLog("Number of objects in WM: %d", numObjects);

	if (numObjects != 3) {
		LM.writeLog("Didn't add all objects");
		return false;
	}

	WM.markForDelete(testRat2);

	numObjects = WM.getAllObjects().getCount();

	LM.writeLog("Number of objects in WM: %d", numObjects);

	if (numObjects != 3) {
		LM.writeLog("Deleted object with out an update");
		return false;
	}

	WM.update();

	numObjects = WM.getAllObjects().getCount();

	LM.writeLog("Number of objects in WM: %d", numObjects);

	if (numObjects != 2) {
		LM.writeLog("Didn't delete object");
		return false;
	}

	WM.markForDelete(testRat1);
	WM.markForDelete(testRat3);

	WM.update();

	numObjects = WM.getAllObjects().getCount();

	LM.writeLog("Number of objects in WM: %d", numObjects);

	if (numObjects != 0) {
		LM.writeLog("Didn't empty list");
		return false;
	}


	return true;
}

bool testGameManager() {
	Clock* testClock = new Clock();
	//Test frame rate
	long int startTime = testClock->delta();
	//runs for 90 frames AKA 3 seconds at 33 ms / frame
	GM.run();

	long int endTime = testClock->delta();

	LM.writeLog("GM ran for: %d", endTime);

	//If didn't run for 3 seconds then test failed
	if (endTime / 1000000 != 3) {
		LM.writeLog("GM didn't run for right amount of time");
		return false;
	}

	//Test GameManager running stepevent in run loop, will once again end after 90 frames, so rat should move 90 spots x 90 spots y
	//This tests essentially all previous pieces

	Rat* testRat = new Rat;

	GM.setGameOver(false);

	int startX = testRat->getPosition().getX();

	startTime = testClock->delta();

	GM.run();

	endTime = testClock->delta();

	int endX = testRat->getPosition().getX();

	//Check that the frame time was not disrupted by actions in the run() function
	LM.writeLog("Time of Execution (Should be 3 seconds): %d", endTime);
	if (endTime / 1000000 != 3) {
		LM.writeLog("Execution time distruped");
		return false;
	}

	//Check that the rat did indeed move ~90 (+/- 1 due to rounding) times
	LM.writeLog("Rat moved %d", endX);
	if (endX != 89 && endX != 90 && endX != 91) {
		LM.writeLog("Rat didn't move right amount");
		return false;
	}

	return true;
}
*/