#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Chess.h"

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
    [[nodiscard]] U64 getWhitePawns() const;
    [[nodiscard]] U64 getWhiteKnights() const;
    [[nodiscard]] U64 getWhiteBishops() const;
    [[nodiscard]] U64 getWhiteRooks() const;
    [[nodiscard]] U64 getWhiteQueens() const;
    [[nodiscard]] U64 getWhiteKing() const;
    [[nodiscard]] U64 getBlackPawns() const;
    [[nodiscard]] U64 getBlackKnights() const;
    [[nodiscard]] U64 getBlackBishops() const;
    [[nodiscard]] U64 getBlackRooks() const;
    [[nodiscard]] U64 getBlackQueens() const;
    [[nodiscard]] U64 getBlackKing() const;
};

#endif // CHESS_BOARD_H