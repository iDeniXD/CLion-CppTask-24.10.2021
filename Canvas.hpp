#ifndef CANVAS_H
#define CANVAS_H

#include "Figure.hpp"

using namespace std;
#include <list>

class Canvas
{
private:
    Canvas();
    ~Canvas();

    list<Figure*> figures_;
    list<Figure*> toDel_;
public:
    static Canvas &Instance();

    void Draw();
    void NextFrame();
    void Add(Figure *f);
    void Remove(int i);
    void Remove(Figure *f);
};

#endif // CANVAS_H
