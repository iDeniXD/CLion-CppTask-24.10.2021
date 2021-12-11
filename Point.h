//
// Created by Denis on 04/12/2021.
//

#ifndef TASK0_POINT_H
#define TASK0_POINT_H

#include <ostream>
using namespace std;

class Point
{
private:
    double x_,y_;
public:
    Point();
    Point(double x, double y);

    double GetX() const;
    double GetY() const;
    void SetX(double x);
    void SetY(double y);

    Point & operator=(const Point &p);
    void operator+= (const Point &p);
    friend ostream & operator << (ostream &os, const Point &p);
};


#endif //TASK0_POINT_H
