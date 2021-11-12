//
// Created by Denis on 06/11/2021.
//

#ifndef TASK0_MOVABLESQUARE_H
#define TASK0_MOVABLESQUARE_H

#include "Square.hpp"

class MovableSquare : public Square
{
protected:
    int health_, maxHealth_;
public:
    MovableSquare(double a = 10, int health = 100);
    ~MovableSquare();

    virtual void Draw();
    virtual void Bounce(Figure *pFigure);
    virtual void Collapsed(Figure *f);

    void Up();
    void Down();
    void Left();
    void Right();
    void SpeedUp();

    void SetHealth(int health);

    virtual void FromString(string &s);


};

#endif //TASK0_MOVABLESQUARE_H
