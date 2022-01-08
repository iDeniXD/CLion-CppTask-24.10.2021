#include "AllegroApp.hpp"
#include "../Factories/FigureFactory.h"

AllegroApp &AllegroApp::Instance() {
    static AllegroApp instance;
    return instance;
}
AllegroApp::AllegroApp() :
    AllegroBase(),
    canvas()
{
//    canvas.Add(FigureFactory::Create(FigureFactory::RandomMovable));
//    canvas.Add(FigureFactory::Create(FigureFactory::RandomCircle));
//    canvas.Add(FigureFactory::Create(FigureFactory::RandomSquare));
//    canvas.Add(FigureFactory::Create(FigureFactory::Input));
}
AllegroApp::~AllegroApp(){}


void AllegroApp::Fps()
{
    canvas.NextFrame();
}
void AllegroApp::Draw()
{
    canvas.Draw();
}



void AllegroApp::OnKeyDown(const ALLEGRO_KEYBOARD_EVENT &keyboard) {
    canvas.OnKeyDown(keyboard);
}



void AllegroApp::Stop() {
    canvas.ClearMemory();
    Instance().Destroy();
}
