#pragma once

//Includes
#include "Button.h"
#include "MouseTrap.h"

class GlueTrapButton : public Button {
private:
	int price = 20;
public:
	//Constructor
	GlueTrapButton();

	//Override the onClicked
	void onClicked() override;
};