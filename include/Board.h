#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include "Chess.h"
#include "Piece.h"

typedef std::uint64_t U64;

class Board {
private:
    // White piece bitboards
    U64 whitePawns;
    U64 whiteKnights;
    U64 whiteBishops;
    U64 whiteRooks;
    U64 whiteQueens;
    U64 whiteKing;

    // Black piece bitboards
    U64 blackPawns;
    U64 blackKnights;
    U64 blackBishops;
    U64 blackRooks;
    U64 blackQueens;
    U64 blackKing;

    // Castling
    bool whiteKingMoved;
    bool whiteKingSideRookMoved;
    bool whiteQueenSideRookMoved;
    bool blackKingMoved;
    bool blackKingSideRookMoved;
    bool blackQueenSideRookMoved;

    // TODO: Add en passant logic

    // Turn
    Color turn;

public:
    Board();
    void initBoard();
    U64 getOccupancy() const;
    bool isTileEmpty(int tile) const;
    bool isWhite() const;
    static int getFile(int tile);
    static int getRank(int tile);
};

#endif // CHESS_BOARD_H