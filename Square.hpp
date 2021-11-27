#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.hpp"

class Square : public Figure
{
protected:
    double a_;
public:
    Square(double a = 10, unsigned char color = 1);
    ~Square();
    virtual void Draw();
    virtual void Move();
    virtual double DistanceToEdgeFacingPoint(double x0, double y0);

    virtual string ToString() const;
    virtual void FromString(string &s);


};
#endif // SQUARE_H
