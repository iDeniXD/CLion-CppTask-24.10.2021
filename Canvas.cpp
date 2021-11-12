#include "Canvas.hpp"
#include "AllegroBase.hpp"

#include "math2D.h"
#include "FigureFactory.h"
#include "Circle.hpp"


Canvas::Canvas()
{
}
Canvas::~Canvas()
{
    for(int i=0; i < figures_.GetSize(); i++) {
        delete figures_.Get(i);
    }
}
void Canvas::Draw()
{
    al_clear_to_color( al_map_rgb( 0, 0, 0 ) ); // Clear creen
    for(int i = 0; i < figures_.GetSize(); i++) {
        figures_.Get(i)->Draw();
    }
}
void Canvas::NextFrame()
{
    for(int i = 0; i < figures_.GetSize(); i++) {
        figures_.Get(i)->Move();
    }
    for(int i = 0; i < figures_.GetSize(); i++) {
        if (i != figures_.GetSize())
        {
            for (int j = i+1; j < figures_.GetSize(); ++j) {
                if (
                        math2D::DistanceBetweenTwoPoints(
                                figures_.Get(i)->GetX(),figures_.Get(i)->GetY(),
                                figures_.Get(j)->GetX(),figures_.Get(j)->GetY())
                        <
                        figures_.Get(i)->DistanceToEdgeFacingPoint(
                                figures_.Get(j)->GetX(),
                                figures_.Get(j)->GetY())
                        +
                        figures_.Get(j)->DistanceToEdgeFacingPoint(
                                figures_.Get(i)->GetX(),
                                figures_.Get(i)->GetY())
                        )
                {
                    figures_.Get(i)->Bounce(figures_.Get(j));
                }
            }
        }
    }

}
void Canvas::Add(Figure *f)
{
    figures_.Add(f);
}
void Canvas::Remove(int i)
{
    figures_.Remove(i);
}
Canvas &Canvas::Instance() {
    static Canvas instance;
    return instance;
}
//TODO create method, that will hit two Figures
