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
    // TODO throw EBorderCollision
    if (GetX() - r_ < 1.0 || GetX() + r_ > Preferences::Instance()->GetScreen().getWidth())
    {
        SetdX(-GetdX());
        if (GetX() - r_ < 1.0)
            SetX(1.0 + r_);
        else
            SetX(Preferences::Instance()->GetScreen().getWidth() - r_);
    }
    if (GetY() - r_ < 1.0 || GetY() + r_ > Preferences::Instance()->GetScreen().getHeight())
    {
        SetdY(-GetdY());
        if (GetY() - r_ < 1.0)
            SetY(1.0 + r_);
        else
            SetY(Preferences::Instance()->GetScreen().getHeight() - r_);
    }
}



double Circle::DistanceToEdgeFacingPoint(Point coords0) {
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


