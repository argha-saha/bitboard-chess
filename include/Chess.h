#ifndef CHESS_H
#define CHESS_H

#include <cstdint>

using U64 = std::uint64_t;

enum class Color {
    WHITE,
    BLACK,
    EMPTY
};

enum class Type {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    NONE
};

#endif // CHESS_H
