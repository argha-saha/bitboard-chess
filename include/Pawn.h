#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include <cmath>

class Pawn {
public:
    static bool canMoveToTile(int dFile, int dRank, bool isWhite);
};

#endif // CHESS_PAWN_H

