#ifndef CHESS_VALIDATOR_H
#define CHESS_VALIDATOR_H

#include "Board.h"
#include "Move.h"

class Validator {
public:
    static bool isValidMove(const Board& board, const Move& move);
};

#endif // CHESS_VALIDATOR_H
