#include "Path.h"
#include "DisplayManager.h"

using namespace df;

Path::Path() {
	
}

int Path::draw() {
	DM.drawCh({ 75, 3 }, 'X', GREEN);
	DM.drawCh({ 75, 13 }, 'X', GREEN);
	DM.drawCh({ 45, 13 }, 'X', GREEN);
	DM.drawCh({ 45, 6 }, 'X', GREEN);
	DM.drawCh({ 5, 6 }, 'X', GREEN);
	DM.drawCh({ 5, 17 }, 'X', GREEN);
	DM.drawCh({ 16, 17 }, 'X', GREEN);
	DM.drawCh({ 16, 10 }, 'X', GREEN);
	DM.drawCh({ 33, 10 }, 'X', GREEN);
	DM.drawCh({ 33, 16 }, 'X', GREEN);
	return 0;
}