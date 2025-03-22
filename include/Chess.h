#ifndef CHESS_H
#define CHESS_H

#include <cstdint>

using U64 = std::uint64_t;

enum Color {
    WHITE,
    BLACK,
    EMPTY
};

enum Type {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    NONE
};

#endif // CHESS_H
