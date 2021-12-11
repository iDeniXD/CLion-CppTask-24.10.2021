#include "Square.hpp"
#include "AllegroBase.hpp"
#include "Preferences.h"
#include "math2D.h"

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

    if (GetX() - a_/2 < 1.0 || GetX() + a_/2 > Preferences::Instance()->GetScreen().getWidth())
    {
        SetdX(-GetdX());
        if (GetX() - a_/2 < 1.0)
            SetX(1.0 + a_/2);
        else
            SetX(Preferences::Instance()->GetScreen().getWidth() - a_/2);

    }
    if (GetY() - a_/2 < 1.0 || GetY() + a_/2 > Preferences::Instance()->GetScreen().getHeight())
    {
        SetdY(-GetdY());
        if (GetY() - a_/2 < 1.0)
            SetY(1.0 + a_/2);
        else
            SetY(Preferences::Instance()->GetScreen().getHeight() - a_/2);
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
