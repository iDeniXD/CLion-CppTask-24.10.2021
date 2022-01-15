#include "Allegro/AllegroApp.hpp"
#include "Preferences.h"


int main(int argc, char **argv) {
    srand( time(0) );
    AllegroApp app;
    if ( !app.Init(Preferences::Instance()->GetScreen().GetWidth(),
                   Preferences::Instance()->GetScreen().GetHeight(),
                   Preferences::Instance()->GetScreen().GetFPS() ) )
    {
        return 1;
    }
    app.Run();
    return 0;
}