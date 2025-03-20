#ifndef CHESS_VALIDATOR_H
#define CHESS_VALIDATOR_H

#include "Board.h"
#include "Move.h"
#include "Knight.h"
#include <cmath>

class Validator {
public:
    static bool isValidMove(const Board& board, const Move& move);
    static bool isPathClear(const Board &board, int fromFile, int fromRank, int toFile, int toRank);
};

#endif // CHESS_VALIDATOR_H
