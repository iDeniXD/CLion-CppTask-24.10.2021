#include "AllegroApp.hpp"
#include "FigureFactory.h"

AllegroApp::AllegroApp() :
    AllegroBase(),
    canvas()
{
    canvas.Add(FigureFactory::Create(FigureFactory::RandomSquare));
    canvas.Add(FigureFactory::Create(FigureFactory::RandomSquare));
    canvas.Add(FigureFactory::Create(FigureFactory::RandomCircle));
    canvas.Add(FigureFactory::Create(FigureFactory::RandomCircle));
}
void AllegroApp::Fps()
{
    canvas.NextFrame();
}
void AllegroApp::Draw()
{
    canvas.Draw();
}
