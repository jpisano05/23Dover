#include "MiceWave.h"
#include <Windows.h>
#include "LogManager.h"
#include "WorldManager.h"

MiceWave::MiceWave(MiceAttack* init_attacks[], int init_wave_num, int init_time_between, int inithealthmod, float initspeedmod) {
	attacks[0] = init_attacks[0];
	attacks[1] = init_attacks[1];
	attacks[2] = init_attacks[2];
	wave_num = init_wave_num;
	time_between = init_time_between;

	curr_attack = -1;
	wait_counter = -1;

	healthmod = inithealthmod;
	speedmod = initspeedmod;

	setType("aw");
}

int MiceWave::getWaveNum() const {
	return wave_num;
}

//Override the event handler
int MiceWave::eventHandler(const df::Event* p_e) {
	//Handle step
	if (p_e->getType() == "step") {
		step();
		return 1;
	}

	return 0;
}

void MiceWave::sendWave() {
	// iterate through the array of attacks and send them all, waiting between attacks
	curr_attack = 1;
	attacks[0]->spawn_attack();
	wait_counter = time_between * 30;
	LM.writeLog("setup first attack");
}

void MiceWave::step() {
	if (curr_attack == -1) {
		return;
	}

	if (wait_counter > 0) {
		wait_counter--;
		return;
	}

	if (curr_attack >= 0) {
		LM.writeLog("Spawning attack number, %d", curr_attack);
		attacks[curr_attack]->spawn_attack();
		wait_counter = time_between * 30;
		curr_attack++;
		if (curr_attack == 3) {
			curr_attack = -1;
			WM.markForDelete(this);
		}
	}
	else {
		return;
	}
}