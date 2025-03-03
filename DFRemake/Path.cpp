#include "Path.h"
#include "DisplayManager.h"

using namespace df;

Path::Path() {
	setSprite("path");
	setSolidness(SPECTRAL);
	setAltitude(0);
	setAltitude(0);
	float horiz = DM.getHorizontal() / 2;
	float vert  = DM.getVertical() / 2 - 3;
	setPosition({horiz, vert});
}