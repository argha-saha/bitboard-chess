#ifndef CHESS_VALIDATOR_H
#define CHESS_VALIDATOR_H

#include "Chess.h"
#include "Board.h"
#include "Move.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include <cmath>

class Validator {
public:
    static bool isValidMove(const Board& board, const Move& move);
    static bool isPathClear(const Board& board, int fromFile, int fromRank, int toFile, int toRank);
    static bool isUnderThreat(const Board& board, int tile, bool byWhite);
    static bool isInCheck(const Board& board, bool whiteKing);
    static bool hasLegalMoves(const Board& board, bool whiteTurn);
    static bool isCheckmate(const Board& board, bool whiteTurn);
    static bool isStalemate(const Board& board, bool whiteTurn);
    static State checkGameState(const Board& board, bool whiteTurn);
};

#endif // CHESS_VALIDATOR_H
