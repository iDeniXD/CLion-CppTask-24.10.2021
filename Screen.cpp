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

int Screen::GetFPS() {
    return fps;
}
int Screen::GetHeight() {
    return height;
}
int Screen::GetWidth() {
    return width;
}
