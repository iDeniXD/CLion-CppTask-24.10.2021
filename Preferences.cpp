//
// Created by Denis on 30/10/2021.
//

#include "Preferences.h"
Preferences* Preferences::instance = nullptr;

Preferences *Preferences::Instance() {
    if (instance == nullptr)
    {
        instance = new Preferences();
    }
    return instance;
}

Preferences::Preferences() :
        screen(60,640,480)
{
}

Screen Preferences::GetScreen() {
    return screen;
}
