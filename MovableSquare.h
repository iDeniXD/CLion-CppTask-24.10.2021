//
// Created by Denis on 06/11/2021.
//

#ifndef TASK0_MOVABLESQUARE_H
#define TASK0_MOVABLESQUARE_H

#include "Square.hpp"

class MovableSquare : public Square
{
protected:
    int health_;
public:
    MovableSquare(double a = 10, unsigned char color = 1, int health = 100);
    ~MovableSquare();

    virtual void Draw();
    virtual void Bounce(Figure *pFigure);

    void Up();
    void Down();
    void Left();
    void Right();
    void SpeedUp();

    void SetHealth(int health);

    virtual void FromString(string &s);


};

#endif //TASK0_MOVABLESQUARE_H
