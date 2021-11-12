#ifndef ALLEGROAPP_H
#define ALLEGROAPP_H

#include "AllegroBase.hpp"
#include "Canvas.hpp"


class AllegroApp : public AllegroBase
{
public:
    AllegroApp();
    virtual void Fps();
    virtual void Draw();
};
#endif // AllegroApp_H
