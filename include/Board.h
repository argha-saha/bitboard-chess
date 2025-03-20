#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Chess.h"
#include <string>

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
    [[nodiscard]] U64 getOccupancy() const;
    [[nodiscard]] bool isTileEmpty(int tile) const;
    [[nodiscard]] Color getPieceColor(int tile) const;
    [[nodiscard]] bool isWhite(int tile) const;
    [[nodiscard]] bool isBlack(int tile) const;

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
    [[nodiscard]] Color getTurn() const;

    // Setters
    void setWhitePawns(U64 value);
    void setWhiteKnights(U64 value);
    void setWhiteBishops(U64 value);
    void setWhiteRooks(U64 value);
    void setWhiteQueens(U64 value);
    void setWhiteKing(U64 value);
    void setBlackPawns(U64 value);
    void setBlackKnights(U64 value);
    void setBlackBishops(U64 value);
    void setBlackRooks(U64 value);
    void setBlackQueens(U64 value);
    void setBlackKing(U64 value);
    void clearPiece(int tile);

    // Static methods
    static int getFile(int tile);
    static int getRank(int tile);

    // Converts an index to a tile (e.g. 63 => h8)
    static std::string indexToTile(int index);

    // Converts a tile to an index (e.g. h8 => 63)
    static int tileToIndex(const std::string& tile);
};

#endif // CHESS_BOARD_H