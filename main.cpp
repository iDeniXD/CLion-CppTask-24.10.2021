#include "Allegro/AllegroApp.hpp"
#include "Preferences.h"


int main(int argc, char **argv) {
    srand( time(0) );
    // TODO:
    //  1) Sort files to folders
    //  2) Make Canvas back into no Singleton
    //  3) Make AllegroApp back into no Singleton
    //  4) Make AllegroApp controll keyboard events
    //  5) Improve collision physics
    AllegroApp app;
    if ( !app.Init( Preferences::Instance()->GetScreen().getWidth(),
                    Preferences::Instance()->GetScreen().getHeight(),
                    Preferences::Instance()->GetScreen().getFPS() ) )
    {
        return 1;
    }
    app.Run();
    return 0;
}