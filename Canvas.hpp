#ifndef CANVAS_H
#define CANVAS_H

#include "DynamicFigures.hpp"

class Canvas
{
private:
    Canvas();
    ~Canvas();

    DynamicFigures figures_;
public:
    static Canvas &Instance();

    void Draw();
    void NextFrame();
    void Add(Figure *f);
    void Remove(int i);
    void Remove(Figure *f);
};

#endif // CANVAS_H
