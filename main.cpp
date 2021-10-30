#include "AllegroApp.hpp"
#include "Preferences.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv) {

    srand( time(0) );
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
