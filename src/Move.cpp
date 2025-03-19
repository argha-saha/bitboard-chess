#include "Move.h"
#include "Board.h"

Move::Move(int fromTile, int toTile) : fromTile(fromTile), toTile(toTile) {}

Move Move::moveString(const std::string& move) {
    // Invalid move
    if (move.size() < 4) {
        return {-1, -1};
    }

    std::string fromTile = move.substr(0, 2);
    std::string toTile = move.substr(2, 2);
    int from = Board::tileToIndex(fromTile);
    int to = Board::tileToIndex(toTile);

    return {from, to};
}