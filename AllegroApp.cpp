#include "AllegroApp.hpp"
#include "FigureFactory.h"

AllegroApp* AllegroApp::instance = nullptr;
AllegroApp *AllegroApp::Instance() {
    if (instance == nullptr)
    {
        instance = new AllegroApp();
    }
    return instance;
}

AllegroApp::AllegroApp() :
    AllegroBase()
{
    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::RandomMovable));
    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::RandomCircle));
    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::RandomSquare));
//    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::RandomCircle));
//    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::Input));
}
void AllegroApp::Fps()
{
    Canvas::Instance().NextFrame();
}
void AllegroApp::Draw()
{
    Canvas::Instance().Draw();
}

void AllegroApp::OnKeyDown(const ALLEGRO_KEYBOARD_EVENT &keyboard) {
    Canvas::Instance().OnKeyDown(keyboard);
}

void AllegroApp::Stop() {
    Canvas::Instance().ClearMemory();
}
