#include "AllegroApp.hpp"
#include "../Factories/FigureFactory.h"
AllegroApp::AllegroApp() :
    AllegroBase(),
    canvas()
{
    for (auto figure:FigureFactory::Create({
                                            FigureFactory::RandomMovable,
                                            FigureFactory::RandomCircle,
                                            FigureFactory::RandomSquare
                                                })) {
        canvas.Add(figure);
    }
    try {
        canvas.Add(FigureFactory::Create(FigureFactory::Input));
    }
    catch (const invalid_argument&) {}
}
AllegroApp::~AllegroApp(){
    canvas.ClearMemory();
}


void AllegroApp::Fps()
{
    canvas.NextFrame();
    // if any key MovableSquare instance use is pressed, it will be passed to canvas
    vector<int> vec = MovableSquare::GetUsedKeys();
    for(int i = 0; i < vec.size(); i++){
        if (IsPressed(vec[i])) canvas.OnKeyPressed(vec[i]);
    }
}
void AllegroApp::Draw()
{
    canvas.Draw();
}



void AllegroApp::OnKeyDown(const ALLEGRO_KEYBOARD_EVENT &keyboard) {
    switch(keyboard.keycode) {
        case ALLEGRO_KEY_ESCAPE:
            Exit();
        default:
            canvas.OnKeyDown(keyboard.keycode);
    }
}



