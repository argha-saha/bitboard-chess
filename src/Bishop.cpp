#include "Bishop.h"

bool Bishop::canMoveToTile(int dFile, int dRank) {
    if (std::abs(dFile) == std::abs(dRank)) {
        return true;
    }

    return false;
}