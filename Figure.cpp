#include "Figure.hpp"
#include "Preferences.h"
#include <stdlib.h>
#include <time.h>
#include "math.h"


Figure::Figure(unsigned char color = 1):
    color_(color)
{
    x_ = rand() % (Preferences::Instance()->GetScreen().getWidth() - 201) + 100;
    y_ = rand() % (Preferences::Instance()->GetScreen().getHeight() - 201) + 100;
    dx_ = 10.0 - rand() % 21;
    dy_ = 10.0 - rand() % 21;
}
void Figure::Bounce()
{
    dx_ = -dx_;
    dy_ = -dy_;
}
void Figure::Bounce(Figure *pFigure) {
    double dxTMP = dx_, dyTMP = dy_;

    double dx0 = pFigure->GetDX();
    double dy0 = pFigure->GetDY();
    double mass0 = pFigure->GetMass();
    dx_ = Figure::newVelocity(dx_, dx0, mass_, mass0);
    dx0 = Figure::newVelocity(dx0, dxTMP, mass_, mass0);
    dy_ = Figure::newVelocity(dy_, dy0, mass0, mass_);
    dy0 = Figure::newVelocity(dy0, dyTMP, mass0, mass_);

    if (abs(dx_) > 10)
        dx_ = 10 * (dx_ / abs(dx_));
    if (abs(dx0) > 10)
        dx0 = 10 * (dx0 / abs(dx0));
    if (abs(dy_) > 10)
        dy_ = 10 * (dy_ / abs(dy_));
    if (abs(dy0) > 10)
        dy0 = 10 * (dy0 / abs(dy0));

    pFigure->SetDX(dx0);
    pFigure->SetDY(dy0);
}
double Figure::newVelocity(double v1, double v2, double m1, double m2) {
    return ((m1-m2)*v1 + 2*m2*v2)/(m1+m2);
}
void Figure::Move()
{
    x_ += dx_;
    y_ += dy_;
}

double Figure::GetX()
{
    return x_;
}
double Figure::GetY()
{
    return y_;
}

double Figure::GetDX() {
    return dx_;
}
double Figure::GetDY() {
    return dy_;
}

double Figure::GetMass() {
    return mass_;
}

void Figure::SetDX(double dx0) {
    dx_ = dx0;
}

void Figure::SetDY(double dy0) {
    dy_ = dy0;
}




