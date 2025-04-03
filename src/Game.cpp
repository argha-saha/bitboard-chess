#include "Game.h"
#include <iostream>

Game::Game() = default;

// const char* Game::getPieceChar(int tile) const {
//     U64 mask = (1ULL << tile);

//     // Unicode characters for chess pieces
//     // TODO: Make this more efficient
//     if (board.getWhitePawns() & mask) return u8"\u2659";
//     if (board.getWhiteKnights() & mask) return u8"\u2658";
//     if (board.getWhiteBishops() & mask) return u8"\u2657";
//     if (board.getWhiteRooks() & mask) return u8"\u2656";
//     if (board.getWhiteQueens() & mask) return u8"\u2655";
//     if (board.getWhiteKing() & mask) return u8"\u2654";
//     if (board.getBlackPawns() & mask) return u8"\u265F";
//     if (board.getBlackKnights() & mask) return u8"\u265E";
//     if (board.getBlackBishops() & mask) return u8"\u265D";
//     if (board.getBlackRooks() & mask) return u8"\u265C";
//     if (board.getBlackQueens() & mask) return u8"\u265B";
//     if (board.getBlackKing() & mask) return u8"\u265A";

//     return "_";
// }

void Game::printBoard() const {
    for (int rank = 7; rank >= 0; --rank) {
        std::cout << (rank + 1) << " ";

        for (int file = 0; file < 8; ++file) {
            int tile = rank * 8 + file;
            std::cout << board.getPieceChar(tile) << " ";
        }

        std::cout << "\n";
    }

    std::cout << "  a b c d e f g h\n\n";
}

void Game::play() {
    exitGame = false;
    bool turn;

    while (!exitGame) {
        board.initBoard();
        activeGame = true;

        Validator validator;

        while (activeGame) {
            turn = (board.getTurn() == Color::WHITE);

            // Check for check or checkmate
            if (validator.isCheckmate(board, turn)) {
                std::cout << "Checkmate!" << std::endl;
                activeGame = false;
                break;
            }

            if (validator.isInCheck(board, turn)) {
                std::cout << "Check!" << std::endl;
            }

            if (validator.isStalemate(board, turn)) {
                std::cout << "Stalemate!" << std::endl;
                activeGame = false;
                break;
            }

            printBoard();
            Color turn = board.getTurn();
            
            if (turn == Color::WHITE) {
                std::cout << "White to move: ";
            } else {
                std::cout << "Black to move: ";
            }

            std::string input;
            std::getline(std::cin, input);

            if (input == "quit") {
                activeGame = false;
                exitGame = true;
            }

            Move move = Move::moveString(input);

            if (move.getFromTile() == -1) {
                std::cout << "Invalid move" << std::endl;
                continue;
            }

            int fromTile = move.getFromTile();
            int toTile = move.getToTile();

            if (validator.isValidMove(board, move)) {
                board.movePiece(fromTile, toTile);
            } else {
                std::cout << "Invalid move!" << std::endl;
            }
        }

        // Restart logic
        if (!exitGame) {
            std::cout << "Restart? (y/n): ";
            std::string response;
            std::getline(std::cin, response);

            if (response != "y" && response != "Y") {
                exitGame = true;
            }
        }
    }
}