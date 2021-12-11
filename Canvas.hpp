#ifndef CANVAS_H
#define CANVAS_H

#include "Figure.hpp"

using namespace std;
#include <list>
#include <allegro5/events.h>
#include "memory"

typedef shared_ptr<Figure> SPFigure;

class Canvas
{
private:
    Canvas();
    ~Canvas();

    list<SPFigure> figures_;
    list<SPFigure> toDel_;
public:
    static Canvas &Instance();

    void Draw();
    void NextFrame();
    void MoveFigures();
    void ClearDeleted();

    void Add(Figure *f);
    void Remove(int i);
    void Remove(Figure *f);

    void CountIfTest();
    void AccumulateTest();

    void ClearMemory();

    void SaveFigures();
    void LoadFigures();

    void OnKeyDown(const ALLEGRO_KEYBOARD_EVENT &event);
};

#endif // CANVAS_H
