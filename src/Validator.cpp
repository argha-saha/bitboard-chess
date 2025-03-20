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
            // TODO: Add additional logic
            return Pawn::canMoveToTile(dFile, dRank);
        }

        // Knight logic
        if (board.getWhiteKnights() & fromMask) {
            return Knight::canMoveToTile(dFile, dRank);
        }

        // Bishop logic
        if (board.getWhiteBishops() & fromMask) {
            // TODO: Add additional logic (need to check if path is clear)
            return Bishop::canMoveToTile(dFile, dRank);
        }

        // Rook logic
        if (board.getWhiteRooks() & fromMask) {
            // TODO: Add additional logic (need to check if path is clear)
            return Rook::canMoveToTile(dFile, dRank);
        }

        // Queen logic
        if (board.getWhiteQueens() & fromMask) {
            return Queen::canMoveToTile(dFile, dRank);
        }

        // King logic
    } else {

    }

    return true;
}

bool Validator::isPathClear(
    const Board& board,
    int fromFile, int fromRank,
    int toFile, int toRank
) {
    int dFile = 0;
    int dRank = 0;

    // Determine direction
    if (toFile > fromFile) {
        dFile = 1;
    } else if (toFile < fromFile) {
        dFile = -1;
    }

    if (toRank > fromRank) {
        dRank = 1;
    } else if (toRank < fromRank) {
        dRank = -1;
    }

    int currentFile = fromFile + dFile;
    int currentRank = fromRank + dRank;

    // Path
    while (currentFile != toFile || currentRank != toRank) {
        int index = currentRank * 8 + currentFile;

        if (!board.isTileEmpty(index)) {
            return false;
        }

        currentFile += dFile;
        currentRank += dRank;
    }

    return true;
}

bool Validator::isUnderThreat(const Board& board, int tile, bool byWhite) {
    int file = Board::getFile(tile);
    int rank = Board::getRank(tile);

    // Pawn
    if (byWhite) {
        // Up-left attack
        if (file > 0) {
            int attackTile = tile - 9;

            if (attackTile >= 0 && Board::getRank(attackTile) == rank - 1) {
                if (board.getWhitePawns() & (1ULL << attackTile)) {
                    return true;
                }
            }
        }

        // Up-right attack
        if (file < 7) {
            int attackTile = tile - 7;

            if (attackTile >= 0 && Board::getRank(attackTile) == rank - 1) {
                if (board.getWhitePawns() & (1ULL << attackTile)) {
                    return true;
                }
            }
        }
    } else {
        // Down-left attack
        if (file > 0) {
            int attackTile = tile + 7;

            if (attackTile < 64 && Board::getRank(attackTile) == rank + 1) {
                if (board.getWhitePawns() & (1ULL << attackTile)) {
                    return true;
                }
            }
        }

        // Down-right attack
        if (file < 7) {
            int attackTile = tile + 9;

            if (attackTile < 64 && Board::getRank(attackTile) == rank + 1) {
                if (board.getWhitePawns() & (1ULL << attackTile)) {
                    return true;
                }
            }
        }
    }

    return false;
}