#ifndef ALLEGROAPP_H
#define ALLEGROAPP_H

#include "AllegroBase.hpp"
#include "../Canvas.hpp"
#include "../Figures/MovableSquare.h"
#include <algorithm>


class AllegroApp : public AllegroBase
{
public:
    AllegroApp();
    ~AllegroApp();

    virtual void Fps();
    virtual void Draw();
    virtual void OnKeyDown(const ALLEGRO_KEYBOARD_EVENT &keyboard );

private:
    Canvas canvas;

};
#endif // AllegroApp_H
