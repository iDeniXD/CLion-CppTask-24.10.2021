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
    for (auto figure:figures_) {
        figure->Draw();
    }
}
void Canvas::NextFrame()
{
    MoveFigures();
    AddNew();
    ClearDeleted();
}
void Canvas::MoveFigures() {
    for (auto figure : figures_) {
        try {
            figure->Move();
            if (*prev(figures_.end()) != figure)
            {
                for (auto figure2 : figures_) {
                    math2D::CheckCollision(figure,figure2);
                }
            }
        }
        catch (EFigureCollision& collisionError)
        {
            try
            {
                math2D::CollideTwoFigures(*collisionError.f1, *collisionError.f2);
            }
            catch (const EFigureDeath& FigureDeathError)
            {
                toDel_.push_back(SPFigure(*FigureDeathError.f1));
                if (FigureDeathError.f2)
                    toDel_.push_back(SPFigure(*FigureDeathError.f2));
            }
        }
        catch (const EDivide& e)
        {
            newFigures.push_back(SPFigure(figure->Divide()));
        }
    }
}
void Canvas::AddNew() {
    for (const auto& figure : newFigures) {
        figures_.push_back(figure);
    }
    newFigures.clear();
}
void Canvas::ClearDeleted() {
    for (const auto &figure : toDel_)
    {
        figures_.remove(figure);
    }
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
    for (const auto &figure : figures_)
    {
        if (&*figure==f) {
            toDel_.push_back(figure); // Look up big comment before Canvas::Remove
            return;
        }
    }
}



void Canvas::CountIfTest() {
    cout << "Figure in the upper part of the screen: " << count_if(figures_.begin(),figures_.end(),[](SPFigure &f)
    {
        return f->GetY() <= Preferences::Instance()->GetScreen().GetHeight() / 2;
    }) << endl;
    cout << "Figure in the lower part of the screen: " << count_if(figures_.begin(),figures_.end(),[](SPFigure &f)
    {
        return f->GetY() > Preferences::Instance()->GetScreen().GetHeight() / 2;
    }) << endl;
}
void Canvas::AccumulateTest() {
    cout << "Total area of all figures: " << accumulate(figures_.begin(),figures_.end(), 0.0, Canvas::SumArea) << endl;
}
float Canvas::SumArea(float acc, const SPFigure& f) {
    return Figure::SumArea(acc,&*f);
}
void Canvas::CalcQuadrantTest() {
    list<int> quadrants = CalcQuadrant();
    for (int i = 0; i < 4; ++i) {
        cout << "q" << i+1 << ": " << *std::next(quadrants.begin(), i) << endl;
    }
    cout << endl;
}
list<int> Canvas::CalcQuadrant() {
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    for_each(figures_.begin(),figures_.end(),[&q1, &q2, &q3, &q4](SPFigure f)
    {
        if (f->GetX() <= Preferences::Instance()->GetScreen().GetWidth() / 2)
            if (f->GetY() <= Preferences::Instance()->GetScreen().GetHeight() / 2)
                q1++;
            else
                q3++;
        else
        if (f->GetY() <= Preferences::Instance()->GetScreen().GetHeight() / 2)
            q2++;
        else
            q4++;
    });
    return list<int>{q1,q2,q3,q4};
}



void Canvas::ClearMemory() {
    toDel_.clear();
    figures_.clear();
}



void Canvas::SaveFigures() {
    cout << "Saving figures..." << endl;

    fstream file("figures.txt",fstream::out);
    for (const auto &figure : figures_)
    {
        file << figure;
    }
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
        case ALLEGRO_KEY_Q:
            CalcQuadrantTest();
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
    for (const auto &figure : figures_)
    {
        MovableSquare *movableSquare = dynamic_cast<MovableSquare *>(&*figure);
        if (movableSquare)
            movableSquare->OnKeyPressed(keycode);
    }
}




