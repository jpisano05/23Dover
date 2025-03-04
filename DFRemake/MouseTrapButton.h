#pragma once

//Includes
#include "Button.h"
#include "MouseTrap.h"

class MouseTrapButton : public Button {
private:
	int price = 100;
public:
	//Constructor
	MouseTrapButton();

	//Override the onClicked
	void onClicked() override;
};