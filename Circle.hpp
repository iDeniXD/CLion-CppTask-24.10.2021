#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.hpp"

class Circle : public Figure
{
protected:
    double r_;
public:
    Circle(double r, unsigned char color);
    virtual void Draw();
    virtual void Move();
};
#endif // CIRCLE_H
