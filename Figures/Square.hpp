#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.hpp"

class Square : public Figure
{
protected:
    double a_;
public:
    Square(double a = 10, unsigned char color = 1);
    Square(Square &&other);
    ~Square() override;

    void Draw() override;
    void Move() override;

    double DistanceToEdgeFacingPoint(Point coords0) override;

    string ToString() const override;
    void FromString(string &s) override;

    Figure* Divide() override;
};
#endif // SQUARE_H
