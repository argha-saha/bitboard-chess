#include "Move.h"
#include "Board.h"

Move::Move(int fromTile, int toTile, char promotion)
    : fromTile(fromTile),
      toTile(toTile),
      promotion(promotion) {}

int Move::getFromTile() const {
    return fromTile;
}

int Move::getToTile() const {
    return toTile;
}

char Move::getPromotion() const {
    return promotion;
}

Move Move::moveString(const std::string& move) {
    // Invalid move
    if (move.size() < 4 || move.size() > 5) {
        return {-1, -1, '\0'};
    }

    std::string fromTile = move.substr(0, 2);
    std::string toTile = move.substr(2, 2);
    int from = Board::tileToIndex(fromTile);
    int to = Board::tileToIndex(toTile);

    if (from == -1 || to == -1) {
        return {-1, -1, '\0'};
    }

    char promo = '\0';

    if (move.size() == 5) {
        promo = static_cast<char>(std::tolower(move[4]));
    }

    return {from, to, promo};
}