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

void math2D::CheckCollision(SPFigure& f1, SPFigure& f2) {
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
        throw EFigureCollision(&f1,&f2);
}
double math2D::DistanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}
double math2D::DistanceBetweenTwoPoints(Point coords, Point coords0) {
    return DistanceBetweenTwoPoints(coords.GetX(),coords.GetY(),coords0.GetX(),coords0.GetY());
}
void math2D::CollapseTwoFigures(SPFigure& f1, SPFigure& f2) {
    double dxTMP = f1->GetdX(), dyTMP = f1->GetdY(); // TODO try to do tmp figure and f->Collapse(f2/tmpF)

    f1->SetdX(math2D::newVelocity(f1->GetdX(), f2->GetdX(), f1->GetMass(), f2->GetMass()));
    f1->SetdY(math2D::newVelocity(f1->GetdY(), f2->GetdY(), f1->GetMass(), f2->GetMass()));

    f2->SetdX(math2D::newVelocity(f2->GetdX(), dxTMP, f2->GetMass(), f1->GetMass()));
    f2->SetdY(math2D::newVelocity(f2->GetdY(), dyTMP, f2->GetMass(), f1->GetMass()));

    MovableSquare *ms1 = dynamic_cast<MovableSquare *>(&*f1);
    MovableSquare *ms2 = dynamic_cast<MovableSquare *>(&*f2);

    if (rand() % 5 == 1 && !ms1 && !ms2) // if random and both figures are not MovableSquare
    {
        throw EFigureDeath(f1->GetMass() > f2->GetMass() ? &f2 : &f1);
    }
    else
    {
        EFigureDeath *e = 0;
        if (ms1)
        {
            try {
                ms1->Collapsed(&*f2);
            }
            catch (const EFigureDeath&)
            {
                e = new EFigureDeath(&f1);
            }
        }
        if (ms2)
        {
            try {
                ms2->Collapsed(&*f1);
            }
            catch (const EFigureDeath& e0) {
                if (e)
                    e->f2 = &f2;
                else
                    e = new EFigureDeath(&f1);
            }
        }
        if (e)
            throw *e;
    }
}
double math2D::newVelocity(double v1, double v2, double m1, double m2) {
    return ((m1-m2)*v1 + 2*m2*v2)/(m1+m2);
}




