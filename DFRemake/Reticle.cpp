

// Engine Includes
#include "EventMouse.h"
#include "DisplayManager.h"
#include "WorldManager.h"
#include "LogManager.h"
// Game Includes
#include "Reticle.h"

using namespace df;

Reticle::Reticle() {

    setType("Reticle");

    // set solidness to spectral so it collides with nothing
    setSolidness(df::SPECTRAL);

    // Make Reticle in foreground.
    setAltitude(df::MAX_ALTITUDE);

    // Reg interest in the mouse event
    //registerInterest(df::MSE_EVENT);

    // Set starting location in the middle of window.
    int world_horiz = (int)WM.getBoundary().getHorizontal();
    int world_vert = (int)WM.getBoundary().getVertical();
    df::Vector p(world_horiz / 2, world_vert / 2);
    setPosition(p);
}

int Reticle::eventHandler(const df::Event* p_e) {

    if (p_e->getType() == MSE_EVENT) {
        const df::EventMouse* p_mouse_event =
            dynamic_cast <const df::EventMouse*> (p_e);
        if (p_mouse_event->getMouseAction() == df::MOVED) {
            //LM.writeLog("Mouse moved, moving reticle");
            // Change location to new mouse position.
            setPosition(DM.pixelsToSpaces(p_mouse_event->getMousePosition()));

            //LM.writeLog("Mouse moved to position (%f,%f)", getPosition().getX(), getPosition().getY());
            return 1;
        }
    }

    // If get here, have ignored this event.
    return 0;
}

// Draw reticle on window.
int Reticle::draw() {
   // LM.writeLog("Drawing Reticle at (%f,%f)", getPosition().getX(), getPosition().getY());
    return DM.drawCh(getPosition(), RETICLE_CHAR, df::RED);
}