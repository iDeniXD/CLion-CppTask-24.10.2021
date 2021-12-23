//
// Created by Denis on 23/12/2021.
//

#ifndef TASK0_POINTIMPL_H
#define TASK0_POINTIMPL_H

template<typename Dimension = double>
class PointImpl
{
private:
    Dimension x_, y_;
public:
    PointImpl(Dimension x, Dimension y) :
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
    friend ostream & operator << (ostream &os, const PointImpl<Dimension> &point)
    {
        os << point.GetX() << ":" << point.GetY() << endl;
        return os;
    }
};

#endif //TASK0_POINTIMPL_H
