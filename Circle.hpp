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
    virtual double DistanceToEdgeFacingPoint(double x0, double y0);

    virtual double tmp();
};
#endif // CIRCLE_H
