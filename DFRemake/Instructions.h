#pragma once

#include "ViewObject.h"
#include "Music.h"

class Instructions : public df::Object {

private:
    //df::Music* p_music;

public:
    Instructions();
    int eventHandler(const df::Event* p_e) override;
    int draw() override;
    //void playMusic();
};
