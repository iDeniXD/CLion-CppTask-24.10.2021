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
    al_draw_filled_circle( GetX(), GetY(), r_, al_map_rgb( 0, color_, 0 ) );
}
void Circle::Move()
{
    Figure::Move();

    if (GetX() - r_ < 1.0 || GetX() + r_ > Preferences::Instance()->GetScreen().getWidth())
    {
        dx_ = -dx_;
        if (GetX() - r_ < 1.0)
            GetX() = 1.0 + r_;
        else
            GetX() = Preferences::Instance()->GetScreen().getWidth() - r_;
    }
    if (GetY() - r_ < 1.0 || GetY() + r_ > Preferences::Instance()->GetScreen().getHeight())
    {
        dy_ = -dy_;
        if (GetY() - r_ < 1.0)
            GetY() = 1.0 + r_;
        else
            GetY() = Preferences::Instance()->GetScreen().getHeight() - r_;
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
    if (s.substr(0,s.find(':')) == "Circle")
    {
        Figure::FromString(s.replace(0, 6, "Figure"));
        Figure::SetParameter(s, this->r_, "r");
        mass_ = 3.14*r_*r_;
    }
    else
    {
        cout << "Error occurred! This info is not for circle" << endl;
    }
}


