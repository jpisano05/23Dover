#include "Path.h"
#include "DisplayManager.h"

using namespace df;

Path::Path() {
	setSprite("path");
	setSolidness(SPECTRAL);
	setAltitude(0);

	setPosition({40, 9});
}