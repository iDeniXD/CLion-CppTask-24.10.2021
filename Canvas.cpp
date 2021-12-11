#include <fstream>
#include "Canvas.hpp"
#include "AllegroBase.hpp"

#include "math2D.h"
#include "FigureFactory.h"
#include "Circle.hpp"
#include "Preferences.h"

#include "algorithm"
#include "numeric"
#include "AllegroApp.hpp"


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
    for_each(figures_.begin(),figures_.end(),[](Figure *f){f->Move();});
    for_each(figures_.begin(),figures_.end(),[this](Figure *f)
    {
        if (*prev(figures_.end()) != f)
        {
            for_each(next(std::find(figures_.begin(), figures_.end(), f)),figures_.end(),[&f](Figure *f2)
            {
                if (
                        math2D::DistanceBetweenTwoPoints(
                                f->GetCoords(),
                                f2->GetCoords())
                        <
                        f->DistanceToEdgeFacingPoint(
                                f2->GetCoords())
                        +
                        f2->DistanceToEdgeFacingPoint(
                                f->GetCoords())
                        )
                    math2D::CollapseTwoFigures(f, f2);
            });
        }
    });
    for_each(toDel_.begin(),toDel_.end(),[this](Figure *f)
    {
        delete f;
        figures_.remove(f);
    });
    toDel_.clear();
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
// Each figure is checked whether it collides with any other figure.
// If it does, then new velocity and direction is calculated for both of these figures.
// But if there is a MovableFigure that is controlled by player, then it has to be treated differently
// since it has a health bar. If the health falls below 1, then it has to be removed. But if the program
// removes the figure right on collision then it will crash, since collision method is inside the
// for-loop(third for_each in Canvas::NextFrame()).
// Thus removing the figure right away will break the loop. So the figure gets added to the toDel list
// and gets removed after the loop is run
}
void Canvas::Remove(Figure *f)
{
    for_each(figures_.begin(),figures_.end(),[this, &f](Figure *f1)
    {
        if (f1==f) {
            toDel_.push_back(f); // Look up big comment before Canvas::Remove
            return;
        }
    });
}

void Canvas::CountIfTest() {
    cout << "Figure in the upper part of the screen: " << count_if(figures_.begin(),figures_.end(),[](Figure *f)
    {
        return f->GetY() <= Preferences::Instance()->GetScreen().getHeight() / 2;
    }) << endl;
    cout << "Figure in the lower part of the screen: " << count_if(figures_.begin(),figures_.end(),[](Figure *f)
    {
        return f->GetY() > Preferences::Instance()->GetScreen().getHeight() / 2;
    }) << endl;
}

void Canvas::AccumulateTest() {
    cout << "Total area of all figures: " << accumulate(figures_.begin(),figures_.end(),0.0, Figure::SumArea) << endl;
}

void Canvas::ClearMemory() {
    for_each(figures_.begin(),figures_.end(),[](Figure *f) {delete f;});
    figures_.clear();
}
void Canvas::SaveFigures() {
    cout << "Saving figures..." << endl;

    fstream file("figures.txt",fstream::out);
    for_each(figures_.begin(),figures_.end(),[&file](Figure *f)
    {
        file << f;
    });
    file.close();
}

void Canvas::LoadFigures() {
    fstream file("figures.txt",fstream::in);
    if (!file)
    {
        cout << "Error!" << endl;
        return;
    }
    Figure *f = 0;
    while (file >> f)
        Add(f);
}


