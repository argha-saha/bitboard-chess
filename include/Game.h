#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "Board.h"
#include "Chess.h"
#include <iostream>

typedef std::uint64_t U64;

class Game {
private:
    Board board;
public:
    Game();
    const char* getPieceChar(int tile) const;
    void printBoard() const;
    Color getOppositeColor();
};

#endif // CHESS_GAME_H
