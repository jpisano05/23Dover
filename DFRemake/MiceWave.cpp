#include "MiceWave.h"
#include "Windows.h"

MiceWave::MiceWave(MiceAttack init_attacks[3], int init_wave_num, int init_time_between) {
	attacks[0] = init_attacks[0];
	attacks[1] = init_attacks[1];
	attacks[2] = init_attacks[2];
	wave_num = init_wave_num;
	time_between = init_time_between;
}

int MiceWave::getWaveNum() const {
	return wave_num;
}

void MiceWave::sendWave() {
	// iterate through the array of attacks and send them all, waiting between attacks
	for (int i = 0; i < 3; i++) {
		attacks[i].spawn_attack();
		Sleep(1000 * time_between);
	}
}