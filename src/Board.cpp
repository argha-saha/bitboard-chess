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
    bool res = getOccupancy() & mask;
    return res == 0ULL;
}

Color Board::getPieceColor(int tile) const {
    U64 mask = (1ULL << tile);
    if (isWhite(tile)) return WHITE;
    if (isBlack(tile)) return BLACK;
    return EMPTY;
}

bool Board::isWhite(int tile) const {
    U64 mask = (1ULL << tile);
    U64 white = (whitePawns | whiteKnights | whiteBishops | 
                 whiteRooks | whiteQueens | whiteKing) & mask;
    return white != 0ULL;
}

bool Board::isBlack(int tile) const {
    U64 mask = (1ULL << tile);
    U64 black = (blackPawns | blackKnights | blackBishops | 
                 blackRooks | blackQueens | blackKing) & mask;
    return black != 0ULL;
}

int Board::getFile(int tile) {
    return tile % 8;
}

int Board::getRank(int tile) {
    return tile / 8;
}

U64 Board::getWhitePawns() const {
    return whitePawns;
}

U64 Board::getWhiteKnights() const {
    return whiteKnights;
}

U64 Board::getWhiteBishops() const {
    return whiteBishops;
}

U64 Board::getWhiteRooks() const {
    return whiteRooks;
}

U64 Board::getWhiteQueens() const {
    return whiteQueens;
}

U64 Board::getWhiteKing() const {
    return whiteKing;
}

U64 Board::getBlackPawns() const {
    return blackPawns;
}

U64 Board::getBlackKnights() const {
    return blackKnights;
}

U64 Board::getBlackBishops() const {
    return blackBishops;
}

U64 Board::getBlackRooks() const {
    return blackRooks;
}

U64 Board::getBlackQueens() const {
    return blackQueens;
}

U64 Board::getBlackKing() const {
    return blackKing;
}