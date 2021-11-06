#include "AllegroApp.hpp"
#include "FigureFactory.h"

#include "Circle.hpp"
#include "Square.hpp"

AllegroApp::AllegroApp() :
    AllegroBase(),
    canvas()
{
    canvas.Add(FigureFactory::Create(FigureFactory::RandomSquare));
    canvas.Add(FigureFactory::Create(FigureFactory::RandomSquare));
    canvas.Add(FigureFactory::Create(FigureFactory::RandomCircle));
    canvas.Add(FigureFactory::Create(FigureFactory::RandomCircle));


    // *****************************************
    // ****************TEST CODE****************
    // *****************************************
    Figure *f;
    string s;
    cout << "Input your own figure:" << endl;
    getline(cin, s);
    string type = s.substr(0,s.find(':'));
    if (type == "Circle") {
        f = new Circle();
        f->FromString(s);
    }
    else if (type == "Square") // If incorrect type then throw exception
    {
        f = new Square();
        f->FromString(s);
    }
    canvas.Add(f);
    // *********************************************
    // ****************TEST CODE END****************
    // *********************************************
}
void AllegroApp::Fps()
{
    canvas.NextFrame();
}
void AllegroApp::Draw()
{
    canvas.Draw();
}
