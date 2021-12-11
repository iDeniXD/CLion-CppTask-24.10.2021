#include "AllegroApp.hpp"
#include "FigureFactory.h"

#include "Circle.hpp"
#include "Square.hpp"
#include "MovableSquare.h"

static MovableSquare *moveableSquare;

AllegroApp::AllegroApp() :
    AllegroBase()
{
    moveableSquare = new MovableSquare(30);
    Canvas::Instance().Add(moveableSquare);

    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::RandomCircle));
    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::RandomSquare));
//    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::RandomCircle));
//    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::Input));
}
void AllegroApp::Fps()
{
    if ( IsPressed( ALLEGRO_KEY_UP ) )
    {
        moveableSquare->Up();
    }
    if ( IsPressed( ALLEGRO_KEY_DOWN ) )
    {
        moveableSquare->Down();
    }
    if ( IsPressed( ALLEGRO_KEY_LEFT ) )
    {
        moveableSquare->Left();
    }
    if ( IsPressed( ALLEGRO_KEY_RIGHT ) )
    {
        moveableSquare->Right();
    }
    if ( IsPressed( ALLEGRO_KEY_LSHIFT ) )
    {
        moveableSquare->SpeedUp();
    }
    Canvas::Instance().NextFrame();
}
void AllegroApp::Draw()
{
    Canvas::Instance().Draw();
}

void AllegroApp::OnKeyDown(const ALLEGRO_KEYBOARD_EVENT &keyboard) {
    switch (keyboard.keycode) {
        case ALLEGRO_KEY_F:
            Canvas::Instance().CountIfTest();
            break;
        case ALLEGRO_KEY_G:
            Canvas::Instance().AccumulateTest();
            break;
        case ALLEGRO_KEY_S:
            Canvas::Instance().SaveFigures();
            break;
        case ALLEGRO_KEY_L:
            Canvas::Instance().LoadFigures();
            break;

//        default:
//            cout << keyboard.keycode << endl;
//            break;
    }
}

void AllegroApp::Stop() {
    Canvas::Instance().ClearMemory();
}
