#include "Figure.hpp"
#include "Preferences.h"
#include <stdlib.h>
#include <time.h>

Figure::Figure(unsigned char color = 1):
    color_(color)
{
    x_ = (double)Preferences::Instance()->GetScreen().getWidth() / 2;
    y_ = (double)Preferences::Instance()->GetScreen().getHeight() / 2;
    dx_ = 10.0 - rand() % 21;
    dy_ = 10.0 - rand() % 21;
}
void Figure::Bounce()
{
    dx_ = -dx_;
    dy_ = -dy_;
}
void Figure::Move()
{
    x_ += dx_;
    y_ += dy_;
}
