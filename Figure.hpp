#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
protected:
    double x_, y_, dx_, dy_;
    unsigned char color_;
public:
    Figure(unsigned char color);
    virtual void Bounce();
    virtual void Draw() = 0;
    virtual void Move();
};
#endif // FIGURE_H
