#ifndef ALLEGROAPP_H
#define ALLEGROAPP_H

#include "AllegroBase.hpp"
#include "../Canvas.hpp"
#include "../Figures/MovableSquare.h"


class AllegroApp : public AllegroBase
{
public:
    static AllegroApp &Instance();

    virtual void Fps();
    virtual void Draw();
    virtual void OnKeyDown(const ALLEGRO_KEYBOARD_EVENT &keyboard );
    void Stop();
private:
    AllegroApp();
    ~AllegroApp();
    Canvas canvas;

};
#endif // AllegroApp_H
