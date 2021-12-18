//
// Created by Denis on 30/10/2021.
//

#ifndef TASK0_PREFERENCES_H
#define TASK0_PREFERENCES_H

#include "Screen.h"

class Preferences
{
public:
    static Preferences *Instance();

    Screen GetScreen();
private:
    Preferences();
    static Preferences *instance;

    Screen screen;

    enum Constants
    {
        FPS = 60,
        WIDTH = 640,
        HEIGHT = 480
    };
};

#endif //TASK0_PREFERENCES_H
