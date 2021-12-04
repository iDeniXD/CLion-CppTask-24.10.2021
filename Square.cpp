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
        dx_ = -dx_;
        if (GetX() - a_/2 < 1.0)
            GetX() = 1.0 + a_/2;
        else
            GetX() = Preferences::Instance()->GetScreen().getWidth() - a_/2;

    }
    if (GetY() - a_/2 < 1.0 || GetY() + a_/2 > Preferences::Instance()->GetScreen().getHeight())
    {
        dy_ = -dy_;
        if (GetY() - a_/2 < 1.0)
            GetY() = 1.0 + a_/2;
        else
            GetY() = Preferences::Instance()->GetScreen().getHeight() - a_/2;
    }
}
double Square::DistanceToEdgeFacingPoint(Point coords0) {
    double dToPoint = math2D::DistanceBetweenTwoPoints(coords,coords0);
    double dToEdge;
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
    if (s.substr(0,s.find(':')) == "Square")
    {
        Figure::FromString(s.replace(0, 6, "Figure"));
        Figure::SetParameter(s, this->a_, "a");
        mass_ = a_ * a_;
    }
    else
    {
        cout << "Error occurred! This is info is not for square" << endl;
    }
}
