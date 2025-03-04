//Includes
#include "SendWaveButton.h"
#include "ScoreManager.h"
#include "MiceWave.h"
#include "MiceAttack.h"
#include "LogManager.h"
#include "DisplayManager.h"

//Constructor
SendWaveButton::SendWaveButton() {
	//Set sprite
	setSprite("send-wave-button");

	setAltitude(3);
	setPosition(df::Vector(DM.getHorizontal() - 10, 20));
	setSolidness(df::SPECTRAL);
}

//Override the onClicked
void SendWaveButton::onClicked() {
	int waveNum = SM.getWave();

	MiceWave* newWave = SM.generateWave(waveNum);

	newWave->sendWave();
	LM.writeLog("Done sending wave");
	SM.setWave(SM.getWave() + 1);
	LM.writeLog("Updated wave count");
}