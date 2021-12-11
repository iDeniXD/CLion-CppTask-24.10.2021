#include "AllegroApp.hpp"
#include "Preferences.h"


int main(int argc, char **argv) {
    srand( time(0) );
    AllegroApp app; // TODO convert class to Singleton so it will be possible to check pressed keys in different class
    if ( !app.Init( Preferences::Instance()->GetScreen().getWidth(),
                    Preferences::Instance()->GetScreen().getHeight(),
                    Preferences::Instance()->GetScreen().getFPS() ) )
    {
        return 1;
    }
    app.Run();
    app.Stop();
    return 0;
}
