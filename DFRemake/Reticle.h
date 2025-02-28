#pragma once

// Engine Includes
#include "Object.h"

// Defines
#define RETICLE_CHAR '+'

class Reticle : public df::Object {

public:
    Reticle();
    int draw(void) override;
    int eventHandler(const df::Event* p_e) override;
};