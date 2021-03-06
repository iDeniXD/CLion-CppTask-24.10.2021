#ifndef CANVAS_H
#define CANVAS_H

#include "Figures/Figure.hpp"

using namespace std;
#include <list>
#include <allegro5/events.h>
#include "memory"

typedef shared_ptr<Figure> SPFigure;

class Canvas
{
private:
    list<SPFigure> figures_;
    list<SPFigure> toDel_;
    list<SPFigure> newFigures;
public:
    Canvas();
    ~Canvas();

    void Draw();
    void NextFrame();
    void MoveFigures();
    void AddNew();
    void ClearDeleted();

    void Add(Figure *f);
    void Remove(int i);
    void Remove(Figure *f);

    void CountIfTest();
    void AccumulateTest();
    static float SumArea(float acc, const SPFigure& f);
    void CalcQuadrantTest();
    list<int> CalcQuadrant();

    void ClearMemory();

    void SaveFigures();
    void LoadFigures();

    void OnKeyDown(int keycode);
    void OnKeyPressed(int keycode);

    void TestMoveConstructor();
};

#endif // CANVAS_H
