//Includes
#include "SendWaveButton.h"
#include "ScoreManager.h"
#include "MiceWave.h"
#include "MiceAttack.h"
#include "LogManager.h"

//Constructor
SendWaveButton::SendWaveButton() {
	//Set sprite
	setSprite("send-wave-button");

	setAltitude(3);

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