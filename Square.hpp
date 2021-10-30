#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.hpp"

class Square : public Figure
{
protected:
    double a_;
public:
    Square(double a, unsigned char color);
    virtual void Draw();
    virtual void Move();

    virtual double DistanceToEdgeFacingPoint(double x0, double y0);

    virtual double tmp();

};
#endif // SQUARE_H
