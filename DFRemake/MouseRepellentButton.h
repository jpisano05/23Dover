#pragma once

//Includes
#include "Button.h"
#include "MouseRepellent.h"

class MouseRepellentButton : public Button {
private:
	int price = 50;
public:
	//Constructor
	MouseRepellentButton();

	//Override the onClicked
	void onClicked() override;
};
