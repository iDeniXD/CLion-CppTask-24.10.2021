#include "Square.hpp"
#include "AllegroBase.hpp"
#include "Preferences.h"
#include "math2D.h"

Square::Square(double a, unsigned char color = 1) :
    Figure(color),
    a_(a)
{
    mass_ = a * a;
}
void Square::Draw()
{
    double half = a_ / 2;
    al_draw_filled_rectangle(
                            x_ - half, y_ - half,
                            x_ + half, y_ + half,
                            al_map_rgb( color_, 0, 0 )
                            );
}
void Square::Move()
{
    Figure::Move();

    if (x_ - a_/2 < 1.0 || x_ + a_/2 > Preferences::Instance()->GetScreen().getWidth())
    {
        dx_ = -dx_;
        if (x_ - a_/2 < 1.0)
            x_ = 1.0 + a_/2;
        else
            x_ = Preferences::Instance()->GetScreen().getWidth() - a_/2;

    }
    if (y_ - a_/2 < 1.0 || y_ + a_/2 > Preferences::Instance()->GetScreen().getHeight())
    {
        dy_ = -dy_;
        if (y_ - a_/2 < 1.0)
            y_ = 1.0 + a_/2;
        else
            y_ = Preferences::Instance()->GetScreen().getHeight() - a_/2;
    }
}

double Square::DistanceToEdgeFacingPoint(double x0, double y0) {
    double dToPoint = math2D::DistanceBetweenTwoPoints(x_,y_,x0,y0);
    double dToEdge;
    if (abs(x0-x_) > abs(y0-y_))
        dToEdge = a_/2/abs(x0-x_)*dToPoint;
    else
        dToEdge = a_/2/abs(y0-y_)*dToPoint;
    return (dToPoint > dToEdge ? dToEdge : dToPoint);
}

double Square::tmp()
{
    return a_;
}