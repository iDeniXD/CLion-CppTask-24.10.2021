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
}
Canvas &Canvas::Instance() {
    static Canvas instance;
    return instance;
}
void Canvas::Draw()
{
    al_clear_to_color( al_map_rgb( 0, 0, 0 ) ); // Clear creen
    for(list<Figure *>::iterator it = figures_.begin(); it != figures_.end(); ++it) {
        (*it)->Draw();
    }
}
void Canvas::NextFrame()
{
    for(list<Figure *>::iterator it = figures_.begin(); it != figures_.end(); ++it) {
        (*it)->Move();
    }
    for(list<Figure *>::iterator i = figures_.begin(); i != figures_.end(); ++i) {
        if (next(i) != figures_.end())
        {
            for (list<Figure *>::iterator j = next(i); j != figures_.end(); ++j) {
                if (
                        math2D::DistanceBetweenTwoPoints(
                                (*i)->GetX(),(*i)->GetY(),
                                (*j)->GetX(),(*j)->GetY())
                        <
                        (*i)->DistanceToEdgeFacingPoint(
                                (*j)->GetX(),
                                (*j)->GetY())
                        +
                        (*j)->DistanceToEdgeFacingPoint(
                                (*i)->GetX(),
                                (*i)->GetY())
                        )
                {
                    math2D::CollapseTwoFigures((*i), (*j));
                }
            }
        }
    }
    for(list<Figure *>::iterator it = toDel_.begin(); it != toDel_.end(); ++it) {
        figures_.remove((*it));
        toDel_.erase(it++);
    }
}
void Canvas::Add(Figure *f)
{
    figures_.push_back(f);
}
void Canvas::Remove(int i)
{
    list<Figure *>::iterator it = figures_.begin();
    advance(it,i);
    toDel_.push_back((*it));
// The reason the figure has to be added to toDel list is following:
// Each figure is checked where it collides with any other figure.
// If it does, then new velocity and direction is calculated for both of these figures.
// But if there is a MovableFigure that is controlled by player, then it has to be treated differently
// since it has a health bar. If the health falls below 1, then it has to be removed. But if the program
// removes the figure right on collision then it will crash, since collision method is inside the for-loop(line 34 & 49).
// Thus removing the figure right away will break the loop. So the figure gets added to the toDel list
// and gets removed after the loop is run
}
void Canvas::Remove(Figure *f)
{
    for(list<Figure *>::iterator it = figures_.begin(); it != figures_.end();++it) {
        if ((*it) == f) {
            toDel_.push_back((*it)); // Look up 68th line
            return;
        }
    }
}


