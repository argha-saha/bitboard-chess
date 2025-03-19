#include "Game.h"

Game::Game() {}

char Game::getPieceChar(int tile) const {
    U64 mask = (1ULL << tile);

    // Unicode characters for chess pieces
    // TODO: Make this more efficient
    if (board.whitePawns & mask) return u8"\u2659";
    if (board.whiteKnights & mask) return u8"\u2658";
    if (board.whiteBishops & mask) return u8"\u2657";
    if (board.whiteRooks & mask) return u8"\u2656";
    if (board.whiteQueens & mask) return u8"\u2655";
    if (board.whiteKing & mask) return u8"\u2654";
    if (board.blackPawns & mask) return u8"\u265F";
    if (board.blackKnights & mask) return u8"\u265E";
    if (board.blackBishops & mask) return u8"\u265D";
    if (board.blackRooks & mask) return u8"\u256C";
    if (board.blackQueens & mask) return u8"\u265B";
    if (board.blackKing & mask) return u8"\u265A";

    return '.';
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