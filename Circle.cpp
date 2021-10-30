#include "Circle.hpp"
#include "AllegroBase.hpp"
#include "Preferences.h"

Circle::Circle(double r, unsigned char color = 1) :
    Figure(color),
    r_(r)
{
}
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
    }
    if (y_ - r_ < 1.0 || y_ + r_ > Preferences::Instance()->GetScreen().getHeight())
    {
        dy_ = -dy_;
    }
}
