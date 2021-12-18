#ifndef FIGURE_H
#define FIGURE_H

#include "ISerializable.h"
#include "Point.h"
#include "Exceptions/EBorderCollision.h"


class Figure : public ISerializable
{
protected:
    Point coords;
    Point velocity;
    double mass_;
    unsigned char color_;

public:
    Figure(unsigned char color = 1);
    ~Figure();

    virtual void Draw() = 0;
    virtual void Move();
    typedef EBorderCollision::Border Border;
    virtual void Bounce(Border border, double side = 0);
    virtual void CheckMoveX(double side = 0);
    virtual void CheckMoveY(double side = 0);

    virtual double DistanceToEdgeFacingPoint(Point coords0) = 0;

    virtual Point GetCoords();
    virtual void SetCoords(double x, double y);
    virtual void SetCoords(Point newCoords);

    virtual Point GetVelocity();
    virtual void SetVelocity(double dx, double dy);
    virtual void SetVelocity(Point newVelocity);

    virtual double GetX() const;
    virtual double GetY() const;
    virtual void SetX(double x);
    virtual void SetY(double y);

    virtual double GetdX() const;
    virtual double GetdY() const;
    virtual void SetdX(double dx0);
    virtual void SetdY(double dy0);

    double GetMass();

    virtual string ToString() const;
    virtual void FromString(string &s);

    static float SumArea(float acc, const Figure *f);

    friend ostream & operator << (ostream &os, const Figure *f);
    friend istream & operator >> (istream &is, Figure *&f);

protected:
    static double GetParameterDouble(string &s, const string &field);
    static int GetParameterInt(string &s, const string &field);
    static unsigned char GetParameterUnsChar(string &s, const string &field);

private:
    static string GetParameter(string &s, const string &field);
};

#endif // FIGURE_H
