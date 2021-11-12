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

MovableSquare::MovableSquare(double a, unsigned char color, int health) :
        Square(a, color),
        health_(health)
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

void MovableSquare::SetHealth(int health)
{
    this->health_ = health;
//    if (health_ < 1)
//    {
//        this = nullptr;
//    }
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

void MovableSquare::Bounce(Figure *pFigure) {
    Figure::Bounce(pFigure);
    this->SetHealth(health_ - (int)(pFigure->GetMass() / this->mass_ * 10) % 50);
}

void MovableSquare::Draw() {
    double half = a_ / 2;
    al_draw_filled_rectangle(
            x_ - half, y_ - half,
            x_ + half, y_ + half,
            al_map_rgb( 0, 0, color_ )
    );

    al_draw_filled_rectangle(
            x_ - half, y_ - half-10,
            x_ - half + (health_*a_/100), y_ - half-5,
            al_map_rgb( 255, 0, 0 )
    );
}

