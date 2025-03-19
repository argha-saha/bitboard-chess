#include "Game.h"

Game::Game() {}

const char* Game::getPieceChar(int tile) const {
    U64 mask = (1ULL << tile);

    // Unicode characters for chess pieces
    // TODO: Make this more efficient
    if (board.getWhitePawns() & mask) return u8"\u2659";
    if (board.getWhiteKnights() & mask) return u8"\u2658";
    if (board.getWhiteBishops() & mask) return u8"\u2657";
    if (board.getWhiteRooks() & mask) return u8"\u2656";
    if (board.getWhiteQueens() & mask) return u8"\u2655";
    if (board.getWhiteKing() & mask) return u8"\u2654";
    if (board.getBlackPawns() & mask) return u8"\u265F";
    if (board.getBlackKnights() & mask) return u8"\u265E";
    if (board.getBlackBishops() & mask) return u8"\u265D";
    if (board.getBlackRooks() & mask) return u8"\u265C";
    if (board.getBlackQueens() & mask) return u8"\u265B";
    if (board.getBlackKing() & mask) return u8"\u265A";

    return ".";
}

void Game::printBoard() const {
    for (int rank = 7; rank >= 0; --rank) {
        std::cout << (rank + 1) << " ";

        for (int file = 0; file < 8; ++file) {
            int tile = rank * 8 + file;
            std::cout << getPieceChar(tile) << " ";
        }

        std::cout << "\n";
    }

    std::cout << " a b c d e f g h\n\n";
}