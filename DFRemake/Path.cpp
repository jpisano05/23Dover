#include "Path.h"
#include "DisplayManager.h"

using namespace df;

Path::Path() {
	DM.drawCh({ 75, 2 }, 'X', GREEN);
	DM.drawCh({ 75, 12 }, 'X', GREEN);
	DM.drawCh({ 40, 12 }, 'X', GREEN);
	DM.drawCh({ 40, 5 }, 'X', GREEN);
	DM.drawCh({ 5, 5 }, 'X', GREEN);
	DM.drawCh({ 5, 16 }, 'X', GREEN);
	DM.drawCh({ 12, 16 }, 'X', GREEN);
	DM.drawCh({ 35, 8 }, 'X', GREEN);
	DM.drawCh({ 35, 14 }, 'X', GREEN);

}