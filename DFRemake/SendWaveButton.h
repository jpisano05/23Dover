#pragma once

//Includes
#include "Button.h"

class SendWaveButton : public Button {
private:
	
public:
	//Constructor
	SendWaveButton();

	//Override the onClicked
	void onClicked() override;
};