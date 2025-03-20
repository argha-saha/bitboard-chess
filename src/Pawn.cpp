#include "Pawn.h"

bool Pawn::canMoveToTile(int dFile, int dRank, bool isWhite) {
    // For white pawns, dRank should be positive
    // For black pawns, dRank should be negative
    int expectedRank = isWhite ? 1 : -1;
    int expectedDoubleRank = isWhite ? 2 : -2;

    // Single step forward
    if (dFile == 0 && dRank == expectedRank) {
        return true;
    }

    // Double step forward
    if (dFile == 0 && dRank == expectedDoubleRank) {
        return true;
    }

    // Diagonal capture
    if (std::abs(dFile) == 1 && dRank == expectedRank) {
        return true;
    }

    return false;
}