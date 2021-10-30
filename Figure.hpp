#ifndef FIGURE_H
#define FIGURE_H


class Figure
{
protected:
    double x_, y_, dx_, dy_;
    double mass_;
    unsigned char color_;

    static double newVelocity(double v1,double v2,double m1,double m2);
public:
    Figure(unsigned char color);
    virtual void Bounce();
    virtual void Bounce(Figure *pFigure);
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
    virtual double tmp() = 0;

};
#endif // FIGURE_H
