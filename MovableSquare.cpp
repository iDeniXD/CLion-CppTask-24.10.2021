//
// Created by Denis on 06/11/2021.
//

#include "MovableSquare.h"
//#include "AllegroBase.hpp"

#include <iostream>
#include "AllegroBase.hpp"
#include <windows.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

MovableSquare::MovableSquare(double a, unsigned char color) :
        Square(a, color)
{
    dx_ = 0;
    dy_ = 0;
}
MovableSquare::~MovableSquare(){}

void MovableSquare::Up() {
    if(dy_ > -10)
        dy_ = (dy_-1);
}

void MovableSquare::Down() {
    if(dy_ < 10)
        dy_ = (dy_+1);
}

void MovableSquare::Left() {
    if(dx_ > -10)
        dx_ = (dx_-1);
}

void MovableSquare::Right() {
    if(dx_ < 10)
        dx_ = (dx_+1);
}

void MovableSquare::SpeedUp() {
    dy_ = (dy_*1.01);
    dx_ = (dx_*1.01);
}

void MovableSquare::FromString(string &s) {
    if (s.substr(0,s.find(':')) == "MovableSquare")
    {
        Square::FromString(s.replace(0, 13, "Square"));
    }
    else
    {
        cout << "Error occurred! This is info is not for movable square" << endl;
    }
}

