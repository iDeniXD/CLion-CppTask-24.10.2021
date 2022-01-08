//
// Created by Denis on 30/10/2021.
//

#ifndef TASK0_MATH2D_H
#define TASK0_MATH2D_H

#include <list>
#include "Figures/Figure.hpp"
#include "Canvas.hpp"

class math2D
{
public:
    static void CheckCollision(SPFigure& f1, SPFigure& f2);
    static double DistanceBetweenTwoPoints(double x1, double y1, double x2, double y2);
    static double DistanceBetweenTwoPoints(Point coords, Point coords0);
    static void CollideTwoFigures(SPFigure &f1, SPFigure &f2);
    static double newVelocity(double v1,double v2,double m1,double m2);
};

#endif //TASK0_MATH2D_H
