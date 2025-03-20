#include "Pawn.h"

bool Pawn::canMoveToTile(int dFile, int dRank) {
    // Single step
    if (dFile == 0 && dRank == 1) {
        return true;
    }

    // Double step
    if (dFile == 0 && dRank == 2) {
        return true;
    }

    // Diagonal capture
    if (std::abs(dFile) == 1 && dRank == 1) {
        return true;
    }

    return false;
}