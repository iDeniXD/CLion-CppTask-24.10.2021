#include "AllegroApp.hpp"
#include "FigureFactory.h"

#include "Circle.hpp"
#include "Square.hpp"
#include "MovableSquare.h"

static MovableSquare *moveableSquare;

AllegroApp::AllegroApp() :
    AllegroBase()
{
    moveableSquare = new MovableSquare(30, 255);
    Canvas::Instance().Add(moveableSquare);
    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::RandomSquare));
    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::Input));
//    Canvas::Instance().Add(FigureFactory::Create(FigureFactory::RandomCircle));




    // *****************************************
    // ****************TEST CODE****************
    // *****************************************
//    Figure *f;
//    string s;
//    cout << "Input your own figure:" << endl;
//    getline(cin, s);
//    string type = s.substr(0,s.find(':'));
//    if (type == "Circle") {
//        f = new Circle();
//        f->FromString(s);
//    }
//    else if (type == "Square") // If incorrect type then throw exception
//    {
//        f = new Square();
//        f->FromString(s);
//    } else {
//        f = FigureFactory::Create(FigureFactory::RandomCircle);
//    }
//        Canvas::Instance().Add(f);
    // *********************************************
    // ****************TEST CODE END****************
    // *********************************************
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
