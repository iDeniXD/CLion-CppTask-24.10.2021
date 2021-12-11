//
// Created by Denis on 04/12/2021.
//

#include "Point.h"

Point::Point(double x, double y) :
        x_(x),
        y_(y){}
Point::Point(){}



double Point::GetX() const{
    return x_;
}
double Point::GetY() const{
    return y_;
}
void Point::SetX(double x) {
    x_ = x;
}
void Point::SetY(double y) {
    y_ = y;
}



Point &Point::operator=(const Point &p) {
    x_ = p.x_;
    y_ = p.y_;
    return *this;
}
void Point::operator+=(const Point &p) {
    x_ += p.x_;
    y_ += p.y_;
}
ostream & operator << (ostream &os, const Point &p)
{
    os << p.GetX() << ":" << p.GetY() << endl;
    return os;
}



