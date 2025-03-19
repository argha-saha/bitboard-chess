#include "Board.h"

Board::Board() {
    whitePawns   = 0x000000000000FF00ULL;
    whiteKnights = 0x0000000000000042ULL;
    whiteBishops = 0x0000000000000024ULL;
    whiteRooks   = 0x0000000000000081ULL;
    whiteQueens  = 0x0000000000000008ULL;
    whiteKing    = 0x0000000000000010ULL;
    blackPawns   = 0x00FF000000000000ULL;
    blackKnights = 0x4200000000000000ULL;
    blackBishops = 0x2400000000000000ULL;
    blackRooks   = 0x8100000000000000ULL;
    blackQueens  = 0x0800000000000000ULL;
    blackKing    = 0x1000000000000000ULL;
    whiteKingMoved = false;
    whiteKingSideRookMoved = false;
    whiteQueenSideRookMoved = false;
    blackKingMoved = false;
    blackKingSideRookMoved = false;
    blackQueenSideRookMoved = false;
    turn = WHITE;
}

void Board::initBoard() {
    whitePawns   = 0x000000000000FF00ULL;
    whiteKnights = 0x0000000000000042ULL;
    whiteBishops = 0x0000000000000024ULL;
    whiteRooks   = 0x0000000000000081ULL;
    whiteQueens  = 0x0000000000000008ULL;
    whiteKing    = 0x0000000000000010ULL;
    blackPawns   = 0x00FF000000000000ULL;
    blackKnights = 0x4200000000000000ULL;
    blackBishops = 0x2400000000000000ULL;
    blackRooks   = 0x8100000000000000ULL;
    blackQueens  = 0x0800000000000000ULL;
    blackKing    = 0x1000000000000000ULL;
    whiteKingMoved = false;
    whiteKingSideRookMoved = false;
    whiteQueenSideRookMoved = false;
    blackKingMoved = false;
    blackKingSideRookMoved = false;
    blackQueenSideRookMoved = false;
    turn = WHITE;
}

U64 Board::getOccupancy() const {
    return (whitePawns | whiteKnights | whiteBishops |
            whiteRooks | whiteQueens | whiteKing |
            blackPawns | blackKnights | blackBishops |
            blackRooks | blackQueens | blackKing);
}

bool Board::isTileEmpty(int tile) const {
    U64 mask = (1ULL << tile);
    bool res = (getOccupancy() & mask) == 0ULL;
    return res;
}

int Board::getFile(int tile) {
    return tile % 8;
}

int Board::getRank(int tile) {
    return tile / 8;
}