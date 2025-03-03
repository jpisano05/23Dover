#include "MiceAttack.h"
#include <Windows.h>

MiceAttack::MiceAttack() {

}

MiceAttack::MiceAttack(int init_num_mice, int init_steps_between) {
	num_mice = init_num_mice;
	time_between = init_steps_between;
}

void MiceAttack::spawn_attack() {
	for (int i = 0; i < num_mice; i++) {
		new Mice();
		Sleep(1000 * time_between);
	}
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