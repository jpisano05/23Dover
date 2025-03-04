#pragma once
#include "MiceAttack.h"

class MiceWave : public df::Object {
private:
	MiceAttack* attacks[3];
	int wave_num;
	// number of seconds between attacks
	int time_between;

	//Wait counter
	int wait_counter;
	int curr_attack;

public:
	MiceWave(MiceAttack* init_attacks[], int init_wave_num, int init_time_between);

	int getWaveNum() const;

	void sendWave();

	int eventHandler(const df::Event* p_e) override;

	void step();

	// I didn't add getters and setters here cause I didn't see a reason and didn't wanna waste time
};