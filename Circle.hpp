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

    virtual double DistanceToEdgeFacingPoint(Point coords0);

    virtual string ToString() const;
    virtual void FromString(string &s);

    virtual Figure* Divide();
};
#endif // CIRCLE_H
