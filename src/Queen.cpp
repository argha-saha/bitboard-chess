#include "Queen.h"

bool Queen::canMoveToTile(int dFile, int dRank) {
    bool straight = (dFile == 0 || dRank == 0);
    bool diagonal = (std::abs(dFile) == std::abs(dRank));

    if (straight || diagonal) {
        return true;
    }

    return false;
}