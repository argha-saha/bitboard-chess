#include "Knight.h"

bool Knight::canMoveToTile(int dFile, int dRank) {
    if ((std::abs(dFile) == 1 && std::abs(dRank) == 2) ||
        (std::abs(dFile) == 2 && std::abs(dRank) == 1)) {
        return true;
    }

    return false;
}