#include "Figure.hpp"
#include "Preferences.h"
#include <stdlib.h>
#include <time.h>
#include "math.h"
#include "FigureFactory.h"


Figure::Figure(unsigned char color):
    color_(color)
{
    coords = Point(rand() % (Preferences::Instance()->GetScreen().getWidth() - 201) + 100,
                   rand() % (Preferences::Instance()->GetScreen().getHeight() - 201) + 100);
    dx_ = 10.0 - rand() % 21;
    dy_ = 10.0 - rand() % 21;
}
Figure::~Figure(){}
void Figure::Bounce()
{
    dx_ = -dx_;
    dy_ = -dy_;
}

void Figure::Collapsed(Figure *f) {
}
void Figure::Move()
{
    coords += Point(dx_, dy_);
}

double &Figure::GetX()
{
    return coords.GetX();
}
double &Figure::GetY()
{
    return coords.GetY();
}
double Figure::GetX() const
{
    return coords.GetX();
}
double Figure::GetY() const
{
    return coords.GetY();
}

double Figure::GetDX() {
    return dx_;
}
double Figure::GetDY() {
    return dy_;
}
Point Figure::GetCoords() {
    return coords;
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
    return "Figure:x="+to_string(GetX())+",y="+to_string(GetY())+",dx="+to_string(dx_)+",dy="+to_string(dy_)+",mass="+to_string(mass_)+",color="+to_string(color_);
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
    // s = "Figure:x=23.5;"
    if(s.find(','+field+'=') == string::npos && s.find(':'+field+'=') == string::npos)
    {
        return false;
    }
    param = stod(GetParameter(s,field));
    return true;
}

bool Figure::SetParameter(string &s, int &param, const string &field) {
    // s = "Figure:health=23;"
    if(s.find(','+field+'=') == string::npos && s.find(':'+field+'=') == string::npos)
    {
        return false;
    }
    param = stoi(GetParameter(s,field));
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
        SetParameter(s, this->coords.GetX(), "x");
        SetParameter(s, this->coords.GetY(), "y");
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

ostream & operator << (ostream &os, const Figure *f)
{
    os << f->ToString() << endl;
    return os;
}
istream & operator >> (istream &is, Figure *&f)
{
    string s;
    is >> s;
    if (s == "")
        return is;
    f = FigureFactory::FigureOutOfType(FigureFactory::ParseType(s));
    f->FromString(s);
    return is;
}








