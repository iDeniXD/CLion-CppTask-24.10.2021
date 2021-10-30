#include "Square.hpp"
#include "AllegroBase.hpp"
#include "Preferences.h"

Square::Square(double a, unsigned char color = 1) :
    Figure(color),
    a_(a)
{
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
    }
    if (y_ - a_/2 < 1.0 || y_ + a_/2 > Preferences::Instance()->GetScreen().getHeight())
    {
        dy_ = -dy_;
    }
}
