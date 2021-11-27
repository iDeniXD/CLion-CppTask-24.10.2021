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
    al_draw_filled_circle( x_, y_, r_, al_map_rgb( 0, color_, 0 ) );
}
void Circle::Move()
{
    Figure::Move();

    if (x_ - r_ < 1.0 || x_ + r_ > Preferences::Instance()->GetScreen().getWidth())
    {
        dx_ = -dx_;
        if (x_ - r_ < 1.0)
            x_ = 1.0 + r_;
        else
            x_ = Preferences::Instance()->GetScreen().getWidth() - r_;
    }
    if (y_ - r_ < 1.0 || y_ + r_ > Preferences::Instance()->GetScreen().getHeight())
    {
        dy_ = -dy_;
        if (y_ - r_ < 1.0)
            y_ = 1.0 + r_;
        else
            y_ = Preferences::Instance()->GetScreen().getHeight() - r_;
    }
}

double Circle::DistanceToEdgeFacingPoint(double x0, double y0) {
    double dToPoint = math2D::DistanceBetweenTwoPoints(x_,y_,x0,y0);
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


