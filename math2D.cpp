//
// Created by Denis on 30/10/2021.
//

#include "math2D.h"
#include "math.h"

double math2D::DistanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}
