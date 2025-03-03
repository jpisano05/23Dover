#include "Path.h"
#include "DisplayManager.h"

using namespace df;

Path::Path() {
	setSprite("path");
	setSolidness(SPECTRAL);
	setAltitude(0);

	setPosition({40, 9});
}

int Path::draw() {
	DM.drawCh({ 75, 3 }, 'X', GREEN);
	for (float i = 0; i < 74; i++) {
		DM.drawCh({ i, 3 }, '-', GREEN);
	}
	DM.drawCh({ 75, 13 }, 'X', GREEN);
	for (float i = 4; i < 12; i++) {
		DM.drawCh({ 75, i }, '|', GREEN);
	}
	DM.drawCh({ 45, 13 }, 'X', GREEN);
	for (float i = 46; i < 74; i++) {
		DM.drawCh({ i, 13 }, '-', GREEN);
	}
	DM.drawCh({ 45, 6 }, 'X', GREEN);
	for (float i = 7; i < 12; i++) {
		DM.drawCh({ 45, i }, '|', GREEN);
	}
	DM.drawCh({ 5, 6 }, 'X', GREEN);
	for (float i = 6; i < 44; i++) {
		DM.drawCh({ i, 6 }, '-', GREEN);
	}
	DM.drawCh({ 5, 17 }, 'X', GREEN);
	for (float i = 7; i < 16; i++) {
		DM.drawCh({ 5, i }, '|', GREEN);
	}
	DM.drawCh({ 16, 17 }, 'X', GREEN);
	for (float i = 6; i < 15; i++) {
		DM.drawCh({ i, 17 }, '-', GREEN);
	}
	DM.drawCh({ 16, 10 }, 'X', GREEN);
	for (float i = 11; i < 16; i++) {
		DM.drawCh({ 16, i }, '|', GREEN);
	}
	DM.drawCh({ 33, 10 }, 'X', GREEN);
	for (float i = 17; i < 32; i++) {
		DM.drawCh({ i, 10 }, '-', GREEN);
	}
	DM.drawCh({ 33, 16 }, 'X', GREEN);
	for (float i = 11; i < 15; i++) {
		DM.drawCh({ 33, i }, '|', GREEN);
	}
	for (float i = 34; i < 80; i++) {
		DM.drawCh({ i, 16 }, '-', GREEN);
	}
	return 0;
}