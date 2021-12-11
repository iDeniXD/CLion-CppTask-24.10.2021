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
    velocity = Point(10.0 - rand() % 21,
                     10.0 - rand() % 21);
}
Figure::~Figure(){}

void Figure::Move()
{
    coords += velocity;
}
void Figure::Collapsed(Figure *f) {
}

Point Figure::GetCoords() {
    return coords;
}
void Figure::SetCoords(double x, double y) {
    SetCoords(Point(x,y));
}
void Figure::SetCoords(Point newCoords) {
    coords = newCoords;
}

Point Figure::GetVelocity() {
    return velocity;
}
void Figure::SetVelocity(double dx, double dy) {
    SetVelocity(Point(dx,dy));
}
void Figure::SetVelocity(Point newVelocity) {
    velocity = newVelocity;
}

double Figure::GetX() const
{
    return coords.GetX();
}
double Figure::GetY() const
{
    return coords.GetY();
}
void Figure::SetX(double x) {
    coords.SetX(x);
}
void Figure::SetY(double y) {
    coords.SetY(y);
}


double Figure::GetdX() const {
    return velocity.GetX();
}
double Figure::GetdY() const {
    return velocity.GetY();
}
void Figure::SetdX(double dx0) {
    velocity.SetX(dx0);
}

void Figure::SetdY(double dy0) {
    velocity.SetY(dy0);
}

double Figure::GetMass() {
    return mass_;
}

string Figure::ToString() const
{
    return "Figure:x="+to_string(GetX())+",y="+to_string(GetY())+",dx="+to_string(GetdX())+",dy="+to_string(GetdY())+",mass="+to_string(mass_)+",color="+to_string(color_);
}
void Figure::FromString(string &s)
{
    if (s.substr(0,s.find(':')) != "Figure")
        throw std::invalid_argument("Cannot convert string for class "+s.substr(0,s.find(':'))+" to Figure");

    this->SetX(GetParameterDouble(s,"x"));
    this->SetY(GetParameterDouble(s,"y"));

    this->SetdX(GetParameterDouble(s,"dx"));
    this->SetdY(GetParameterDouble(s,"dy"));

    this->mass_ = GetParameterDouble(s,"mass");

    this->color_ = GetParameterUnsChar(s,"color");
}

float Figure::SumArea(float acc, const Figure *f) {
    return acc+(float)(f->mass_);
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
    if (s.empty())
        return is;
    f = FigureFactory::FigureOutOfType(FigureFactory::ParseType(s));
    f->FromString(s);
    return is;
}

string Figure::GetParameter(string &s, const string &field) {
    int start = s.find(','+field+'=');
    if (start == string::npos)
        start = s.find(':' + field + '=');
    if (start == string::npos)
        throw std::invalid_argument("The field '"+field+"' does not exist!");
    start++;

    string tmp = s.substr(start+field.length()+1);
    // tmp = "23;"

    int end = tmp.find(',');
    // end = 2

    tmp = tmp.substr(0,end);
    // tmp = 23
    return tmp;
}

double Figure::GetParameterDouble(string &s, const string &field) {
    // "Figure:x=23.5;"
    double param;
    try
    {
        param = stod(GetParameter(s, field));
    }
    catch (std::exception&) {}
    return param;
}
int Figure::GetParameterInt(string &s, const string &field) {
    // "Figure:health=23;"
    int param;
    try
    {
        param = stoi(GetParameter(s, field));
    }
    catch (std::exception&) {}
    return param;
}
unsigned char Figure::GetParameterUnsChar(string &s, const string &field) {
    // "Figure:color=55;"
    int param;
    try
    {
        param = stoi(GetParameter(s, field));
    }
    catch (std::exception&) {}
    return param;
}












