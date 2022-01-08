#include <fstream>
#include "Canvas.hpp"
#include "Allegro/AllegroBase.hpp"

#include "math2D.h"
#include "Factories/FigureFactory.h"
#include "Figures/Circle.hpp"
#include "Preferences.h"

#include "algorithm"
#include "numeric"
#include "Allegro/AllegroApp.hpp"
#include "Exceptions/EFigureCollision.h"
#include "Exceptions/EDivide.h"
#include "Exceptions/EFigureDeath.h"


Canvas::Canvas(){}
Canvas::~Canvas(){}
void Canvas::Draw()
{
    al_clear_to_color( al_map_rgb( 0, 0, 0 ) ); // Clear screen
    for(list<SPFigure>::iterator it = figures_.begin(); it != figures_.end(); ++it) {
        (*it)->Draw();
    }
}
void Canvas::NextFrame()
{
    MoveFigures();
    AddNew();
    ClearDeleted();
}
void Canvas::MoveFigures() {
    for_each(figures_.begin(),figures_.end(),[this](SPFigure &f)
    {
        try
        {
            f->Move();
            if (*prev(figures_.end()) != f)
                for_each(next(std::find(figures_.begin(), figures_.end(), f)),figures_.end(),[&f](SPFigure &f2)
                {
                    math2D::CheckCollision(f,f2);
                });
        }
        catch (EFigureCollision& e) // TODO rename all errors
        {
            try
            {
                math2D::CollideTwoFigures(*e.f1, *e.f2);
            }
            catch (const EFigureDeath& ed)
            {
                toDel_.push_back(SPFigure(*ed.f1));
                if (ed.f2)
                    toDel_.push_back(SPFigure(*ed.f2));
            }
        }
        catch (const EDivide& e)
        {
            newFigures.push_back(SPFigure(f->Divide()));
        }
    });
}
void Canvas::AddNew() {
    for_each(newFigures.begin(),newFigures.end(),[this](const SPFigure& f)
    {
        figures_.push_back(f);
    });
    newFigures.clear();
}
void Canvas::ClearDeleted() {
    for_each(toDel_.begin(),toDel_.end(),[this](const SPFigure& f)
    {
        figures_.remove(f);
    });
    toDel_.clear();
}



void Canvas::Add(Figure *f)
{
    newFigures.push_back(SPFigure(f));
}
void Canvas::Remove(int i)
{
    list<SPFigure>::iterator it = figures_.begin();
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
    for_each(figures_.begin(),figures_.end(),[this, &f](SPFigure &f1)
    {
        if (&*f1==f) {
            toDel_.push_back(f1); // Look up big comment before Canvas::Remove
            return;
        }
    });
}



void Canvas::CountIfTest() {
    cout << "Figure in the upper part of the screen: " << count_if(figures_.begin(),figures_.end(),[](SPFigure &f)
    {
        return f->GetY() <= Preferences::Instance()->GetScreen().getHeight() / 2;
    }) << endl;
    cout << "Figure in the lower part of the screen: " << count_if(figures_.begin(),figures_.end(),[](SPFigure &f)
    {
        return f->GetY() > Preferences::Instance()->GetScreen().getHeight() / 2;
    }) << endl;
}
void Canvas::AccumulateTest() { // TODO solve this
    cout << "Total area of all figures: " << accumulate(figures_.begin(),figures_.end(), 0.0, Canvas::SumArea) << endl;
}
float Canvas::SumArea(float acc, const SPFigure& f) {
    return Figure::SumArea(acc,&*f);
}



void Canvas::ClearMemory() {
    toDel_.clear();
    figures_.clear();
}



void Canvas::SaveFigures() {
    cout << "Saving figures..." << endl;

    fstream file("figures.txt",fstream::out);
    for_each(figures_.begin(),figures_.end(),[&file](SPFigure &f)
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



void Canvas::OnKeyDown(int keycode) {
    switch (keycode) {
        case ALLEGRO_KEY_F:
            CountIfTest();
            break;
        case ALLEGRO_KEY_G:
            AccumulateTest();
            break;
        case ALLEGRO_KEY_S:
            SaveFigures();
            break;
        case ALLEGRO_KEY_L:
            LoadFigures();
            break;

    }
}

void Canvas::OnKeyPressed(int keycode) {
    for_each(figures_.begin(), figures_.end(), [keycode](SPFigure &f) {
        MovableSquare *movableSquare = dynamic_cast<MovableSquare *>(&*f);
        if (movableSquare)
            movableSquare->OnKeyPressed(keycode);
    });
}


