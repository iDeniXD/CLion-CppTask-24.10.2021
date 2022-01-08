#include "Square.hpp"
#include "../Allegro/AllegroBase.hpp"
#include "../Preferences.h"
#include "../math2D.h"
#include "../Exceptions/EFigureDeath.h"

Square::Square(double a, unsigned char color) :
    Figure(color),
    a_(a)
{
    mass_ = a * a;
}
Square::~Square(){}



void Square::Draw()
{
    double half = a_ / 2;
    al_draw_filled_rectangle(
                            GetX() - half, GetY() - half,
                            GetX() + half, GetY() + half,
                            al_map_rgb( color_, 0, 0 )
                            );
}
void Square::Move()
{
    Figure::Move();
    try
    {
        Figure::CheckMoveX(a_);
    }
    catch (const EBorderCollision& e)
    {
        Figure::Bounce(e.border,a_);
    }
    try
    {
        Figure::CheckMoveY(a_);
    }
    catch (const EBorderCollision& e)
    {
        Figure::Bounce(e.border,a_);
    }
}



double Square::DistanceToEdgeFacingPoint(Point coords0) {
    double dToPoint = math2D::DistanceBetweenTwoPoints(coords,coords0);
    double dToEdge;

    // Possible to replace coords.Get.. with simple Get.., but for ease of reading it is done like this

    if (abs(coords0.GetX()-coords.GetX()) > abs(coords0.GetY()-coords.GetY()))
        dToEdge = a_/2/abs(coords0.GetX()-coords.GetX())*dToPoint;
    else
        dToEdge = a_/2/abs(coords0.GetY()-coords.GetY())*dToPoint;
    return (dToPoint > dToEdge ? dToEdge : dToPoint);
}



string Square::ToString() const {
    string s = Figure::ToString();
    s = s.substr(s.find(':'));
    s = "Square"+s+",a="+ to_string(a_);
    return s;
}
void Square::FromString(string &s) {
    if (s.substr(0,s.find(':')) != "Square")
        throw std::invalid_argument("Cannot convert string for class "+s.substr(0,s.find(':'))+" to Square");

    Figure::FromString(s.replace(0, 6, "Figure"));

    this->a_ = Figure::GetParameterDouble(s,"a");
    mass_ = Figure::GetParameterDouble(s,"mass");
}



Figure* Square::Divide() {
    Square *newFigure = new Square(a_, color_);
    newFigure->SetdX(-GetdX());
    newFigure->SetdY(-GetdY());
    newFigure->SetX(GetX()+(GetdX() > 0 ? -a_*2 : a_*2));
    newFigure->SetY(GetY()+(GetdY() > 0 ? -a_*2 : a_*2));

    return newFigure;
}

