#ifndef CANVAS_H
#define CANVAS_H

#include "DynamicFigures.hpp"

class Canvas
{
private:
    DynamicFigures figures_;
public:
    Canvas();
    ~Canvas();
    void Draw();
    void NextFrame();
    void Add(Figure *f);
    void Remove(int i);
};

#endif // CANVAS_H
