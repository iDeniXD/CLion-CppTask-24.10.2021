#include "Figure.hpp"
#include "Preferences.h"
#include <stdlib.h>
#include <time.h>
#include "math.h"


Figure::Figure(unsigned char color):
    color_(color)
{
    x_ = rand() % (Preferences::Instance()->GetScreen().getWidth() - 201) + 100;
    y_ = rand() % (Preferences::Instance()->GetScreen().getHeight() - 201) + 100;
    dx_ = 10.0 - rand() % 21;
    dy_ = 10.0 - rand() % 21;
}
Figure::~Figure(){}
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
    dx0 = Figure::newVelocity(dx0, dxTMP, mass0, mass_);
    dy_ = Figure::newVelocity(dy_, dy0, mass_, mass0);
    dy0 = Figure::newVelocity(dy0, dyTMP, mass0, mass_);

    pFigure->SetDX(dx0);
    pFigure->SetDY(dy0);
}
void Figure::Collapsed(Figure *f) {}
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

string Figure::ToString() const
{
    return "Figure:x="+to_string(x_)+",y="+to_string(y_)+",dx="+to_string(dx_)+",dy="+to_string(dy_)+",mass="+to_string(mass_)+",color="+to_string(color_);
}

string Figure::GetParameter(string &s, const string &field)
{
    int start = s.find(','+field+'=');
    if (start == string::npos)
        start = s.find(':' + field + '=');
    start++;

    string tmp = s.substr(start+field.length()+1);
    // tmp = "23;"

    int end = tmp.find(',');
    // end = 2

    tmp = tmp.substr(0,end);
    // tmp = 23
    return tmp;
}

bool Figure::SetParameter(string &s, double &param, const string& field) {
    // s = "Figure:x=23;"
    if(s.find(','+field+'=') == string::npos && s.find(':'+field+'=') == string::npos)
    {
        return false;
    }
    param = stod(GetParameter(s,field));
    return true;
}
bool Figure::SetParameter(string &s, unsigned char &param, const string& field) {
    // s = "Figure:color=55;"
    if(s.find(','+field+'=') == string::npos && s.find(':'+field+'=') == string::npos)
    {
        return false;
    }
    param = stoi(GetParameter(s,field));
    return true;
}
void Figure::FromString(string &s)
{
    if (s.substr(0,s.find(':')) == "Figure")
    {
        SetParameter(s, this->x_, "x");
        SetParameter(s, this->y_, "y");
        SetParameter(s, this->dx_, "dx");
        SetParameter(s, this->dy_, "dy");
        SetParameter(s, this->mass_, "mass");
        SetParameter(s, this->color_, "color");
    }
    else
    {
        cout << "Error occurred! This info is not for figure" << endl;
    }
}

float Figure::SumArea(float acc, const Figure *f) {
    return acc+(f->mass_);
}








