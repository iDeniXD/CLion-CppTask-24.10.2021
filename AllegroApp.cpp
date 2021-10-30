#include "AllegroApp.hpp"
#include "Square.hpp"
#include "Circle.hpp"

AllegroApp::AllegroApp() :
    AllegroBase(),
    canvas()
{
    canvas.Add(new Square(40,60));
    canvas.Add(new Square(60,120));
    canvas.Add(new Circle(60,120));
    canvas.Add(new Circle(100,240));
}
void AllegroApp::Fps()
{
    canvas.NextFrame();
}
void AllegroApp::Draw()
{
    canvas.Draw();
}
