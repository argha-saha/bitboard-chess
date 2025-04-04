#include "Game.h"
#include <iostream>

Game::Game() = default;

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

// Main for testing in ChessTest.cpp
void Game::printBoard(const Board& b) {
    for (int rank = 7; rank >= 0; --rank) {
        std::cout << (rank + 1) << " ";

        for (int file = 0; file < 8; ++file) {
            int tile = rank * 8 + file;
            std::cout << b.getPieceChar(tile) << " ";
        }

        std::cout << "\n";
    }

    std::cout << "  a b c d e f g h\n\n";
}

void Game::play() {
    exitGame = false;
    bool whiteTurn;

    while (!exitGame) {
        board.initBoard();
        activeGame = true;

        while (activeGame) {
            whiteTurn = (board.getTurn() == Color::WHITE);

            // Check for check or checkmate
            if (Validator::isCheckmate(board, whiteTurn)) {
                std::cout << "Checkmate!" << std::endl;
                activeGame = false;
                break;
            }

            if (Validator::isInCheck(board, whiteTurn)) {
                std::cout << "Check!" << std::endl;
            }

            if (Validator::isStalemate(board, whiteTurn)) {
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

            if (Validator::isValidMove(board, move)) {
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