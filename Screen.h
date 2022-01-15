//
// Created by Denis on 30/10/2021.
//

#ifndef TASK0_SCREEN_H
#define TASK0_SCREEN_H

class Screen
{
private:
    int fps, width, height;
public:
    Screen(int f, int w, int h);
    int GetFPS();
    int GetWidth();
    int GetHeight();
};

#endif //TASK0_SCREEN_H
