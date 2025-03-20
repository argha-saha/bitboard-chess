#include "Rook.h"

bool Rook::canMoveToTile(int dFile, int dRank) {
    if (dFile == 0 || dRank == 0) {
        return true;
    }

    return false;
}