//
// Created by Denis on 23/12/2021.
//

#ifndef TASK0_POINT_H
#define TASK0_POINT_H

template<typename Dimension>
class PointImpl
{
private:
    Dimension x_, y_;
public:
    PointImpl(Dimension x = 0, Dimension y = 0) :
        x_(x),
        y_(y)
    {}



    Dimension GetX() const
    {
        return x_;
    }
    Dimension GetY() const
    {
        return y_;
    }
    void SetX(Dimension x)
    {
        x_ = x;
    }
    void SetY(Dimension y)
    {
        y_ = y;
    }



    void operator+= (const PointImpl<Dimension> &other)
    {
        x_ += other.x_;
        y_ += other.y_;
    }
    PointImpl<Dimension> operator* (const double &multiplier)
    {
        return PointImpl<Dimension>(x_*multiplier,y_*multiplier);
    }
    friend ostream & operator << (ostream &os, const PointImpl<Dimension> &point)
    {
        os << point.GetX() << ":" << point.GetY() << endl;
        return os;
    }
};
typedef PointImpl<double> Point;

#endif //TASK0_POINT_H
