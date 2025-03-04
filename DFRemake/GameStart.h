#pragma once

#include "ViewObject.h"
#include "Music.h"

class GameStart : public Object {

private:
    void start();
    //df::Music* p_music;

public:
    GameStart();
    int eventHandler(const Event* p_e) override;
    int draw() override;
    //void playMusic();
};