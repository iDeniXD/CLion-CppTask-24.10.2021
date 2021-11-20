#ifndef FIGURE_H
#define FIGURE_H

#include "ISerializable.h"

class Figure : public ISerializable
{
protected:
    double x_, y_, dx_, dy_;
    double mass_;
    unsigned char color_;

    static double newVelocity(double v1,double v2,double m1,double m2);
public:
    Figure(unsigned char color = 1);
    ~Figure();
    virtual void Bounce();
    virtual void Bounce(Figure *pFigure);
    virtual void Collapsed(Figure *f);
    virtual void Draw() = 0;
    virtual void Move();

    virtual double DistanceToEdgeFacingPoint(double x0, double y0) = 0;

    virtual double GetX();
    virtual double GetY();
    virtual double GetDX();
    virtual void SetDX(double dx0);
    virtual double GetDY();
    virtual void SetDY(double dy0);
    double GetMass();

    virtual string ToString();
    virtual void FromString(string &s);

    static float SumArea(float acc, const Figure *f);

protected:
    static bool SetParameter(string &s, double &param, const string& field);
    static bool SetParameter(string &s, unsigned char &param, const string& field);

private:
    static string GetParameter(string &s, const string &field);
};
#endif // FIGURE_H
