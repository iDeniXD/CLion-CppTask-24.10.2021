#include "AllegroApp.hpp"
#include "Preferences.h"


int main(int argc, char **argv) {
    srand( time(0) );

    if ( !AllegroApp::Instance().Init( Preferences::Instance()->GetScreen().getWidth(),
                    Preferences::Instance()->GetScreen().getHeight(),
                    Preferences::Instance()->GetScreen().getFPS() ) )
    {
        return 1;
    }
    AllegroApp::Instance().Run();
    AllegroApp::Instance().Stop();
    return 0;
}
