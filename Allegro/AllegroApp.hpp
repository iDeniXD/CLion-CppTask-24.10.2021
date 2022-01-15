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
    ~AllegroApp() override;

    void Fps() override;
    void Draw() override;
    void OnKeyDown(const ALLEGRO_KEYBOARD_EVENT &keyboard ) override;

private:
    Canvas canvas;

};
#endif // AllegroApp_H
