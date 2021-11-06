//
// Created by Denis on 06/11/2021.
//

#ifndef TASK0_MOVABLESQUARE_H
#define TASK0_MOVABLESQUARE_H

#include "Square.hpp"

class MovableSquare : public Square
{
protected:
    double a_;
public:
    MovableSquare(double a = 10, unsigned char color = 1);
    ~MovableSquare();

    void Up();
    void Down();
    void Left();
    void Right();
    void SpeedUp();

    virtual void FromString(string &s);


};

#endif //TASK0_MOVABLESQUARE_H
