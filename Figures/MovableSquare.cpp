//
// Created by Denis on 06/11/2021.
//

#include "MovableSquare.h"

#include <iostream>
#include "../Allegro/AllegroBase.hpp"
#include "../Canvas.hpp"
#include "../Allegro/AllegroApp.hpp"
#include "../Exceptions/EDivide.h"
#include "../Exceptions/EFigureDeath.h"
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

MovableSquare::MovableSquare(double a, int health) :
        Square(a, 255),
        health_(health)
{
    SetdX(0);
    SetdY(0);

    maxHealth_ = health_;
}
MovableSquare::MovableSquare(MovableSquare &&other) :
        Square(move(other))
{
    std::cout << "Move of MovableSquare class" << std::endl;
    health_ = other.health_;
    other.health_ = 0;
    maxHealth_ = other.maxHealth_;
    maxHealth_ = 0;
}
MovableSquare::~MovableSquare(){}



bool MovableSquare::MbyDivide() {
    return false;
}
void MovableSquare::Draw() {
    double half = a_ / 2;
    al_draw_filled_rectangle(
            (float)(GetX() - half), (float)(GetY() - half),
            (float)(GetX() + half), (float)(GetY() + half),
            al_map_rgb( 255 - (health_*255/maxHealth_), health_*255/maxHealth_, 0 )
    );

    al_draw_filled_rectangle(
            (float)(GetX() - half), (float)(GetY() - half-10),
            (float)(GetX() - half + (health_*a_/maxHealth_)), (float)(GetY() - half-5),
            al_map_rgb( 255, 255, 255 )
    );
}
void MovableSquare::Collided(Figure *f) {
    this->SetHealth(health_ - (int)(f->GetMass() / this->mass_ * 10) % 50);
}



void MovableSquare::Up() {
    if(GetdY() > -10)
        SetdY(GetdY()-1);
}
void MovableSquare::Down() {
    if(GetdY() < 10)
        SetdY(GetdY()+1);
}
void MovableSquare::Left() {
    if(GetdX() > -10)
        SetdX(GetdX()-1);
}
void MovableSquare::Right() {
    if(GetdX() < 10)
        SetdX(GetdX()+1);
}
void MovableSquare::SpeedUp() {
    SetVelocity(GetVelocity()*1.01);
}



void MovableSquare::OnKeyPressed(int i) {
    if ( i == ALLEGRO_KEY_UP )
    {
        Up();
    }
    if ( i == ALLEGRO_KEY_DOWN )
    {
        Down();
    }
    if ( i == ALLEGRO_KEY_LEFT )
    {
        Left();
    }
    if ( i == ALLEGRO_KEY_RIGHT )
    {
        Right();
    }
    if ( i == ALLEGRO_KEY_LSHIFT )
    {
        SpeedUp();
    }
}


void MovableSquare::SetHealth(int health)
{
    this->health_ = health;
    if (health_ < 1) {
        throw EFigureDeath();
    }
}



string MovableSquare::ToString() const {
    string s = Square::ToString();
    s = s.substr(s.find(':'));
    s = "MovableSquare"+s+",maxhealth="+ to_string(maxHealth_)+",health="+to_string(health_);
    return s;
}
void MovableSquare::FromString(string &s) {
    if (s.substr(0,s.find(':')) != "MovableSquare")
        throw std::invalid_argument("Cannot convert string for class "+s.substr(0,s.find(':'))+" to MovableSquare");

    Square::FromString(s.replace(0, 13, "Square"));

    this->maxHealth_ = Figure::GetParameterInt(s,"maxhealth");
    if (maxHealth_ == 0)
        maxHealth_ = 1; // Otherwise, in Draw() health will be divided by 0
    this->health_ = Figure::GetParameterInt(s,"health");
}

Figure *MovableSquare::Divide()
{
    return nullptr;
}
std::vector<int> used_keys_ = {
        ALLEGRO_KEY_UP,
        ALLEGRO_KEY_DOWN,
        ALLEGRO_KEY_LEFT,
        ALLEGRO_KEY_RIGHT,
        ALLEGRO_KEY_LSHIFT
};
vector<int> MovableSquare::GetUsedKeys() {
    return used_keys_;
}



