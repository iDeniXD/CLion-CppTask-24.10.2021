#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.hpp"

class Circle : public Figure
{
protected:
    double r_;
public:
    Circle(double r = 10, unsigned char color = 1);
    ~Circle() override;

    void Draw() override;
    void Move() override;

    double DistanceToEdgeFacingPoint(Point coords0) override;

    string ToString() const override;
    void FromString(string &s) override;

    Figure* Divide() override;
};
#endif // CIRCLE_H
