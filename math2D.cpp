//
// Created by Denis on 30/10/2021.
//

#include "math2D.h"
#include <algorithm>
#include "math.h"
#include "Figures/MovableSquare.h"
#include "Exceptions/EFigureCollision.h"
#include "Exceptions/EHit.h"
#include "Exceptions/EHitBoth.h"
#include "Allegro/AllegroApp.hpp"
#include "Exceptions/EFigureDeath.h"

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
double math2D::DistanceBetweenTwoPoints(Point coords, Point coords0) {
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
    {
        if (f1->GetMass() > f2->GetMass())
            throw EFigureDeath(f2);
        else
            throw EFigureDeath(f1);
    }
    else
    {
        EFigureDeath *e = new EFigureDeath();
        if (ms1)
        {
            try {
                ms1->Collapsed(f2);
            }
            catch (const EFigureDeath& e0)
            {
                e->f1 = ms1;
            }
        }
        if (ms2)
        {
            try {
                ms2->Collapsed(f1);
            }
            catch (const EFigureDeath& e0) {
                if (e->f1)
                    e->f2 = ms2;
                else
                    e->f1 = ms2;
            }
        }
        if (e->f1)
            throw *e;
    }
}
double math2D::newVelocity(double v1, double v2, double m1, double m2) {
    return ((m1-m2)*v1 + 2*m2*v2)/(m1+m2);
}




