#include "MiceAttack.h"
#include <Windows.h>
#include "Mice.h"
#include "LogManager.h"
#include "WorldManager.h"

MiceAttack::MiceAttack() {
	setType("aa");
	num_mice = 0;
	time_between = 0;
	curr_mouse = -1;
	wait_counter = -1;

	healthmod = 0;
	speedmod = 0;
}

MiceAttack::MiceAttack(int init_num_mice, int init_steps_between, int inithealthmod, float initspeedmod) {
	num_mice = init_num_mice;
	time_between = init_steps_between;
	setType("aa");
	curr_mouse = -1;
	wait_counter = -1;

	healthmod = inithealthmod;
	speedmod = initspeedmod;
}

void MiceAttack::spawn_attack() {
	LM.writeLog("Spawnining initial attack");
	curr_mouse = 1;
	Mice* m1 = new Mice();

	m1->setHealth(m1->getHealth() + healthmod);
	m1->setSpeedMod(m1->getSpeedMod() + speedmod);

	LM.writeLog("Spawned new mouse");
	wait_counter = 30 * time_between;
	LM.writeLog("Set waiting counter");
}

int MiceAttack::getNumMice() const {
	return num_mice;
}

void MiceAttack::setNumMice(int new_num_mice) {
	num_mice = new_num_mice;
}

int MiceAttack::getTimeBetween() const {
	return time_between;
}

void MiceAttack::setTimeBetween(int new_steps_between) {
	time_between = new_steps_between;
}

//Override the event handler
int MiceAttack::eventHandler(const df::Event* p_e) {
	//Handle step
	if (p_e->getType() == "step") {
		step();
		return 1;
	}

	return 0;
}

void MiceAttack::step() {
	if (curr_mouse == -1) {
		return;
	}

	if (wait_counter > 0) {
		LM.writeLog("Waiting on counter");
		wait_counter--;
		return;
	}

	if (curr_mouse >= 0 && num_mice != 1) {
		LM.writeLog("Spawning next mouse");
		Mice* m1 = new Mice();
		wait_counter = time_between * 30;
		curr_mouse++;
		if (curr_mouse == num_mice) {
			curr_mouse = -1;
			WM.markForDelete(this);
		}
	}
	else if (num_mice == 1) {
		WM.markForDelete(this);
	}
	else {
		return;
	}
}