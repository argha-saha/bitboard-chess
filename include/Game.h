#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Game {
public:
    Game();
    bool init();
    void run();
    void cleanup();
    ~Game();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
    static const int WINDOW_SIZE = 640;
    static const int BOARD_SIZE = 560;
    static const int SQUARE_SIZE = BOARD_SIZE / 8;
    static const int BORDER_SIZE = (WINDOW_SIZE - BOARD_SIZE) / 2;
    static const int BOARD_OUTLINE_THICKNESS = 2;

    void handleEvents();
    void render();
};

#endif // CHESS_GAME_H