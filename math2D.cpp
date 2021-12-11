//
// Created by Denis on 30/10/2021.
//

#include "math2D.h"
#include "math.h"

double math2D::DistanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}
double math2D::DistanceBetweenTwoPoints(Point coords, Point coords0) {
    return sqrt(pow(coords0.GetX()-coords.GetX(),2) + pow(coords0.GetY()-coords.GetY(),2));
}
void math2D::CollapseTwoFigures(Figure *f1, Figure *f2) {
    double dxTMP = f1->GetdX(), dyTMP = f1->GetdY();

    f1->SetdX(math2D::newVelocity(f1->GetdX(), f2->GetdX(), f1->GetMass(), f2->GetMass()));
    f1->SetdY(math2D::newVelocity(f1->GetdY(), f2->GetdY(), f1->GetMass(), f2->GetMass()));
    f2->SetdX(math2D::newVelocity(f2->GetdX(), dxTMP, f2->GetMass(), f1->GetMass()));
    f2->SetdY(math2D::newVelocity(f2->GetdY(), dyTMP, f2->GetMass(), f1->GetMass()));

    f1->Collapsed(f2);
    f2->Collapsed(f1);
}

double math2D::newVelocity(double v1, double v2, double m1, double m2) {
    return ((m1-m2)*v1 + 2*m2*v2)/(m1+m2);
}


