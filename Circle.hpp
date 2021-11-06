#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.hpp"

class Circle : public Figure
{
protected:
    double r_;
public:
    Circle(double r = 10, unsigned char color = 1);
    ~Circle();
    virtual void Draw();
    virtual void Move();
    virtual double DistanceToEdgeFacingPoint(double x0, double y0);

    virtual string ToString();
    virtual void FromString(string &s);
};
#endif // CIRCLE_H
