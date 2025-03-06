#pragma once

#include "ViewObject.h"
#include "Object.h"

class GameOver : public df::ViewObject {
private:
	int time_to_live;
	void step();
	void restart();
public:
	GameOver();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
};
