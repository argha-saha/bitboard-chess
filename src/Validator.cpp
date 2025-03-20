#include "Validator.h"

bool Validator::isValidMove(const Board& board, const Move& move) {
    int from = move.getFromTile();
    int to = move.getToTile();

    // Bounds check
    if (from < 0 || from > 63 || to < 0 || to > 63) {
        return false;
    }

    // Turn check
    Color movingColor = board.getPieceColor(from);

    if (movingColor != board.getTurn()) {
        return false;
    }

    // Destination tile can't be same color
    Color toColor = board.getPieceColor(to);

    if (toColor == movingColor) {
        return false;
    }

    return true;
}