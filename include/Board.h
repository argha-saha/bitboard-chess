#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Chess.h"

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
    Color getPieceColor(int tile) const;
    bool isWhite(int tile) const;
    bool isBlack(int tile) const;
    static int getFile(int tile);
    static int getRank(int tile);

    // Getters
    U64 getWhitePawns() const;
    U64 getWhiteKnights() const;
    U64 getWhiteBishops() const;
    U64 getWhiteRooks() const;
    U64 getWhiteQueens() const;
    U64 getWhiteKing() const;
    U64 getBlackPawns() const;
    U64 getBlackKnights() const;
    U64 getBlackBishops() const;
    U64 getBlackRooks() const;
    U64 getBlackQueens() const;
    U64 getBlackKing() const;
};

#endif // CHESS_BOARD_H