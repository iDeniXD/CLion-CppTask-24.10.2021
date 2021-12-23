//
// Created by Denis on 30/10/2021.
//

#include "math2D.h"
#include "math.h"
#include "MovableSquare.h"
#include "Exceptions/EFigureCollision.h"
#include "Exceptions/EHit.h"
#include "Canvas.hpp"
#include "Exceptions/EHitBoth.h"

void math2D::CheckCollision(Figure *f1, Figure *f2) {
    if (
            math2D::DistanceBetweenTwoPoints(
                    f1->GetCoords(),
                    f2->GetCoords())
            <
            f1->DistanceToEdgeFacingPoint(
                    f2->GetCoords())
            +
            f2->DistanceToEdgeFacingPoint(
                    f1->GetCoords())
            )
        throw EFigureCollision(f1,f2);
}
double math2D::DistanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}
double math2D::DistanceBetweenTwoPoints(PointImpl<> coords, PointImpl<> coords0) {
    return DistanceBetweenTwoPoints(coords.GetX(),coords.GetY(),coords0.GetX(),coords0.GetY());
}
void math2D::CollapseTwoFigures(Figure *f1, Figure *f2) {

    double dxTMP = f1->GetdX(), dyTMP = f1->GetdY();

    f1->SetdX(math2D::newVelocity(f1->GetdX(), f2->GetdX(), f1->GetMass(), f2->GetMass()));
    f1->SetdY(math2D::newVelocity(f1->GetdY(), f2->GetdY(), f1->GetMass(), f2->GetMass()));
    f2->SetdX(math2D::newVelocity(f2->GetdX(), dxTMP, f2->GetMass(), f1->GetMass()));
    f2->SetdY(math2D::newVelocity(f2->GetdY(), dyTMP, f2->GetMass(), f1->GetMass()));

    MovableSquare *ms1 = dynamic_cast<MovableSquare *>(f1);
    MovableSquare *ms2 = dynamic_cast<MovableSquare *>(f2);

    if (rand() % 5 == 1 && !ms1 && !ms2) // if random and both figures are not MovableSquare
        Canvas::Instance().Remove((f1->GetMass() > f2->GetMass() ? f2 : f1));

    if (ms1 and ms2)
        throw EHitBoth(ms1, ms2);
    if (ms1)
        throw EHit(ms1, f2);
    if (ms2)
        throw EHit(ms2, f1);
}
double math2D::newVelocity(double v1, double v2, double m1, double m2) {
    return ((m1-m2)*v1 + 2*m2*v2)/(m1+m2);
}



