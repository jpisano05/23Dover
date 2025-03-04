#include "MiceAttack.h"
#include <Windows.h>
#include "Mice.h"
#include "LogManager.h"
#include "WorldManager.h"

MiceAttack::MiceAttack() {
	setType("aw");
	curr_mouse = -1;
	wait_counter = -1;
}

MiceAttack::MiceAttack(int init_num_mice, int init_steps_between) {
	num_mice = init_num_mice;
	time_between = init_steps_between;
	setType("aw");
	curr_mouse = -1;
	wait_counter = -1;
}

void MiceAttack::spawn_attack() {
	//LM.writeLog("Spawnining initial attack");
	curr_mouse = 1;
	Mice* m1 = new Mice();
	//LM.writeLog("Spawned new mouse");
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
	if (wait_counter > 0) {
		wait_counter--;
		return;
	}

	if (curr_mouse >= 0 && num_mice != 1) {
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