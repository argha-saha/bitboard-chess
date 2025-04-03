#include "Application.h"
#include "Game.h"

int main(int argc, char *argv[]) {
    // GUI game
    // Application app;
    
    // if (!app.init()) {
    //     return 1;
    // }
    
    // app.run();

    // CLI game
    Game game;
    game.play();
    
    return 0;
}