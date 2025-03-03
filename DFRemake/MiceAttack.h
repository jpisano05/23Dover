#pragma once
//includes
#include "Mice.h"


//Start of class definition
class MiceAttack {
private:
	int num_mice;
	// number of seconds between mice
	int time_between;
public:
	MiceAttack(int init_num_mice, int init_time_between);

	void spawn_attack();

	int getNumMice() const;
	void setNumMice(int new_num_mice);
	int getTimeBetween() const;
	void setTimeBetween(int new_time_between);
};