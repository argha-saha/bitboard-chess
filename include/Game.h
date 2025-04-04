#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Board.h"
#include "Chess.h"
#include "Move.h"
#include "Validator.h"
#include <iostream>
#include <string>

class Game {
private:
    Board board;
    bool exitGame = false;
    bool activeGame = false;

public:
    Game();
    void printBoard() const;
    static void printBoard(const Board& b);
    void play();
};

#endif // CHESS_GAME_H
