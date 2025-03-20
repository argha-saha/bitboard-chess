#include "Validator.h"

bool Validator::isValidMove(const Board& board, const Move& move) {
    int from = move.getFromTile();
    int to = move.getToTile();

    // Bounds check
    if (from < 0 || from > 63 || to < 0 || to > 63) {
        return false;
    }

    Color movingColor = board.getPieceColor(from);

    // Checks if piece exists and turn is correct
    if (movingColor != board.getTurn()) {
        return false;
    }

    // Destination tile can't be same color
    Color toColor = board.getPieceColor(to);

    if (toColor == movingColor) {
        return false;
    }

    // Get file/rank of source and destination
    int fromFile = Board::getFile(from);
    int fromRank = Board::getRank(from);
    int toFile = Board::getFile(to);
    int toRank = Board::getRank(to);

    // Calculate changes in file and rank
    int dFile = toFile - fromFile;
    int dRank = toRank - fromRank;

    U64 fromMask = (1ULL << from);

    bool whiteTurn = (movingColor == Color::WHITE);

    if (whiteTurn) {
        // Pawn logic
        if (board.getWhitePawns() & fromMask) {

        }

        // Knight logic
        if (board.getWhiteKnights() & fromMask) {
            return Knight::canMoveToTile(dFile, dRank);
        }

        // Bishop logic

        // Rook logic

        // Queen logic

        // King logic
    } else {

    }

    return true;
}