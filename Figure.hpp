#ifndef FIGURE_H
#define FIGURE_H

#include "ISerializable.h"
#include "Point.h"


class Figure : public ISerializable
{
protected:
    Point coords;
    double dx_, dy_;
    double mass_;
    unsigned char color_;

public:
    Figure(unsigned char color = 1);
    ~Figure();
    virtual void Bounce();
    virtual void Collapsed(Figure *f);
    virtual void Draw() = 0;
    virtual void Move();

    virtual double DistanceToEdgeFacingPoint(Point coords0) = 0;

    virtual double &GetX();
    virtual double &GetY();
    virtual double GetX() const;
    virtual double GetY() const;
    virtual Point GetCoords();
    virtual double GetDX();
    virtual void SetDX(double dx0);
    virtual double GetDY();
    virtual void SetDY(double dy0);
    double GetMass();

    virtual string ToString() const;
    virtual void FromString(string &s);

    static float SumArea(float acc, const Figure *f);

    friend ostream & operator << (ostream &os, const Figure *f);
    friend istream & operator >> (istream &is, Figure *&f);

protected:
    static bool SetParameter(string &s, double &param, const string& field);
    static bool SetParameter(string &s, int &param, const string& field);
    static bool SetParameter(string &s, unsigned char &param, const string& field);

private:
    static string GetParameter(string &s, const string &field);
};

#endif // FIGURE_H
