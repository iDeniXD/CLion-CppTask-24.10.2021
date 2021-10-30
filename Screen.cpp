//
// Created by Denis on 30/10/2021.
//

#include "Screen.h"

Screen::Screen(int f, int w, int h) :
    fps(f),
    width(w),
    height(h)
{
}

int Screen::getFPS() {
    return fps;
}
int Screen::getHeight() {
    return height;
}
int Screen::getWidth() {
    return width;
}
