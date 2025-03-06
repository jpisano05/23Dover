#pragma once
//includes
#include "Mice.h"


//Start of class definition
class MiceAttack : public df::Object {
private:
	int num_mice;
	// number of seconds between mice
	int time_between;

	//Wait counter
	int wait_counter;
	int curr_mouse;

	int speedmod;
	int healthmod;
public:
	MiceAttack();
	MiceAttack(int init_num_mice, int init_time_between, int inithealthmod, float initspeedmod);

	void spawn_attack();

	int eventHandler(const df::Event* p_e) override;

	void step();

	int getNumMice() const;
	void setNumMice(int new_num_mice);
	int getTimeBetween() const;
	void setTimeBetween(int new_time_between);
};