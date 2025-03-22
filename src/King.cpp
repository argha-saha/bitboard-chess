#include "King.h"

bool King::canMoveToTile(int dFile, int dRank) {
    return std::abs(dFile) <= 1 && std::abs(dRank) <= 1;
}