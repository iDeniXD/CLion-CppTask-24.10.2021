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
    virtual void Collapsed(Figure *f);

    virtual double DistanceToEdgeFacingPoint(Point coords0);

    virtual string ToString() const;
    virtual void FromString(string &s);

    virtual Figure* Divide();
};
#endif // SQUARE_H