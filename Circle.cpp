#include "Circle.hpp"
#include "AllegroBase.hpp"
#include "Preferences.h"
#include "math2D.h"

Circle::Circle(double r, unsigned char color) :
    Figure(color),
    r_(r)
{
    mass_ = 3.14*r*r;
}
Circle::~Circle(){}



void Circle::Draw()
{
    al_draw_filled_circle( (float)GetX(), (float)GetY(), (float)r_, al_map_rgb( 0, color_, 0 ) );
}
void Circle::Move()
{
    Figure::Move();
    try
    {
        Figure::CheckMoveX(r_);
    }
    catch (const EBorderCollision& e)
    {
        Figure::Bounce(e.border,r_);
    }
    try
    {
        Figure::CheckMoveY(r_);
    }
    catch (const EBorderCollision& e)
    {
        Figure::Bounce(e.border,r_);
    }
}



double Circle::DistanceToEdgeFacingPoint(PointImpl<> coords0) {
    double dToPoint = math2D::DistanceBetweenTwoPoints(coords, coords0);
    return (dToPoint > r_ ? r_ : dToPoint);
}



string Circle::ToString() const {
    string s = Figure::ToString();
    s = s.substr(s.find(':'));
    s = "Circle"+s+",r="+ to_string(r_);
    return s;
}
void Circle::FromString(string &s) {
    if (s.substr(0,s.find(':')) != "Circle")
        throw std::invalid_argument("Cannot convert string for class "+s.substr(0,s.find(':'))+" to Circle");

    Figure::FromString(s.replace(0, 6, "Figure"));

    this->r_ = Figure::GetParameterDouble(s,"r");
    this->mass_ = Figure::GetParameterDouble(s,"mass");
}

Figure *Circle::Divide() {
    Circle *newFigure = new Circle(r_, color_);
    newFigure->SetdX(-GetdX());
    newFigure->SetdY(-GetdY());
    newFigure->SetX(GetX()+(GetdX() > 0 ? -r_*2 : r_*2));
    newFigure->SetY(GetY()+(GetdY() > 0 ? -r_*2 : r_*2));

    return newFigure;
}


