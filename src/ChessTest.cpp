#include "Game.h"
#include "Board.h"
#include "Move.h"
#include "Validator.h"
#include <cassert>
#include <iostream>

void testBoardFileRank() {
    int file = Board::getFile(4);
    assert(file == 4);
    std::cout << "PASS: getFile()" << std::endl;

    int rank = Board::getRank(16);
    assert(rank == 2);
    std::cout << "PASS: getRank()" << std::endl;
}

void testBoardIndexToTile() {
    std::string tile = Board::indexToTile(63);
    assert(tile == "h8");
    
    std::cout << "PASS: indexToTile()\n";
}

void testBoardTileToIndex() {
    int index = Board::tileToIndex("h8");
    assert(index == 63);
    std::cout << "PASS: tileToIndex()\n";

    index = Board::tileToIndex("h9");
    assert(index == -1);
    std::cout << "PASS: tileToIndex()\n";
}

void testMoveString() {
    Move moveStr = Move::moveString("e2e4");
    assert(moveStr.getFromTile() == 12);
    assert(moveStr.getToTile() == 28);
    assert(moveStr.getPromotion() == '\0');
    std::cout << "PASS: moveString()\n";

    moveStr = Move::moveString("e7e8q");
    assert(moveStr.getFromTile() == 52);
    assert(moveStr.getToTile() == 60);
    assert(moveStr.getPromotion() == 'q');
    std::cout << "PASS: moveString()\n" << std::endl;
}

void testPrintBoard() {
    Game game;
    game.printBoard();
}

void testPieceSettingAndClearing() {
    Board board;
    
    // Test setting white pieces
    board.setWhitePawns(1ULL << 0);  // Set pawn at a1
    assert(board.getWhitePawns() == (1ULL << 0));
    std::cout << "PASS: setWhitePawns()\n";
    
    board.setWhiteKnights(1ULL << 1);  // Set knight at b1
    assert(board.getWhiteKnights() == (1ULL << 1));
    std::cout << "PASS: setWhiteKnights()\n";
    
    board.setWhiteBishops(1ULL << 2);  // Set bishop at c1
    assert(board.getWhiteBishops() == (1ULL << 2));
    std::cout << "PASS: setWhiteBishops()\n";
    
    board.setWhiteRooks(1ULL << 3);  // Set rook at d1
    assert(board.getWhiteRooks() == (1ULL << 3));
    std::cout << "PASS: setWhiteRooks()\n";
    
    board.setWhiteQueens(1ULL << 4);  // Set queen at e1
    assert(board.getWhiteQueens() == (1ULL << 4));
    std::cout << "PASS: setWhiteQueens()\n";
    
    board.setWhiteKing(1ULL << 5);  // Set king at f1
    assert(board.getWhiteKing() == (1ULL << 5));
    std::cout << "PASS: setWhiteKing()\n";

    board.setWhitePawns(1ULL << 6); // Set pawn at g1
    assert(board.getWhitePawns() == (1ULL << 6));
    std::cout << "PASS: setWhitePawns()\n";

    board.setWhiteKnights(1ULL << 7); // Set knight at h1
    assert(board.getWhiteKnights() == (1ULL << 7));
    std::cout << "PASS: setWhiteKnights()\n";
    
    // Test setting black pieces
    board.setBlackPawns(1ULL << 56);  // Set pawn at a8
    assert(board.getBlackPawns() == (1ULL << 56));
    std::cout << "PASS: setBlackPawns()\n";
    
    board.setBlackKnights(1ULL << 57);  // Set knight at b8
    assert(board.getBlackKnights() == (1ULL << 57));
    std::cout << "PASS: setBlackKnights()\n";
    
    board.setBlackBishops(1ULL << 58);  // Set bishop at c8
    assert(board.getBlackBishops() == (1ULL << 58));
    std::cout << "PASS: setBlackBishops()\n";
    
    board.setBlackRooks(1ULL << 59);  // Set rook at d8
    assert(board.getBlackRooks() == (1ULL << 59));
    std::cout << "PASS: setBlackRooks()\n";
    
    board.setBlackQueens(1ULL << 60);  // Set queen at e8
    assert(board.getBlackQueens() == (1ULL << 60));
    std::cout << "PASS: setBlackQueens()\n";
    
    board.setBlackKing(1ULL << 61);  // Set king at f8
    assert(board.getBlackKing() == (1ULL << 61));
    std::cout << "PASS: setBlackKing()\n";

    board.setBlackPawns(1ULL << 62); // Set pawn at g8
    assert(board.getBlackPawns() == (1ULL << 62));
    std::cout << "PASS: setBlackPawns()\n";

    board.setBlackKnights(1ULL << 63); // Set knight at h8
    assert(board.getBlackKnights() == (1ULL << 63));
    std::cout << "PASS: setBlackKnights()\n";
    
    // Test clearing pieces
    board.clearPiece(0);  // Clear white pawn at a1
    board.clearPiece(6);  // Clear white pawn at g1
    assert(board.getWhitePawns() == 0);
    std::cout << "PASS: clearPiece()\n";
    
    board.clearPiece(56);  // Clear black pawn at a8
    board.clearPiece(62);  // Clear black pawn at g8
    assert(board.getBlackPawns() == 0);
    std::cout << "PASS: clearPiece()\n";
    
    board.clearPiece(1);   // Clear white knight at b1
    board.clearPiece(7);   // Clear white knight at h1
    board.clearPiece(57);  // Clear black knight at b8
    board.clearPiece(63);  // Clear black knight at h8
    assert(board.getWhiteKnights() == 0 && board.getBlackKnights() == 0);
    std::cout << "PASS: clearPiece()\n";
    
    std::cout << std::endl;
}

void testIsPathClear() {
    Board board;

    for (int i = 0; i < 64; i++) {
        board.clearPiece(i);
    }
    
    // Test diagonal path (empty)
    assert(Validator::isPathClear(board, 0, 0, 7, 7) == true);
    std::cout << "PASS: isPathClear() - empty diagonal path\n";
    
    // Test diagonal path (blocked)
    board.setWhitePawns(1ULL << 27);  // Set pawn at d4
    assert(Validator::isPathClear(board, 0, 0, 7, 7) == false);
    std::cout << "PASS: isPathClear() - blocked diagonal path\n";
    
    // Test horizontal path (empty)
    board.clearPiece(27);  // Clear the blocking pawn
    assert(Validator::isPathClear(board, 0, 0, 7, 0) == true);
    std::cout << "PASS: isPathClear() - empty horizontal path\n";
    
    // Test horizontal path (blocked)
    board.setWhitePawns(1ULL << 5);  // Set pawn at f1
    assert(Validator::isPathClear(board, 0, 0, 7, 0) == false);
    std::cout << "PASS: isPathClear() - blocked horizontal path\n";
    
    // Test vertical path (empty)
    board.clearPiece(5);  // Clear the blocking pawn
    assert(Validator::isPathClear(board, 0, 0, 0, 7) == true);
    std::cout << "PASS: isPathClear() - empty vertical path\n";
    
    // Test vertical path (blocked)
    board.setWhitePawns(1ULL << 32);  // Set pawn at a5
    assert(Validator::isPathClear(board, 0, 0, 0, 7) == false);
    std::cout << "PASS: isPathClear() - blocked vertical path\n";
    
    // Test path with piece at destination (should be clear)
    board.clearPiece(32);  // Clear the blocking pawn
    board.setBlackRooks(1ULL << 63);  // Set black rook at h8
    assert(Validator::isPathClear(board, 0, 0, 7, 7) == true);
    std::cout << "PASS: isPathClear() - path with piece at destination\n";
    
    std::cout << std::endl;
}

void pawnMovementTest() {
    Board board;
    board.clearBoard();
    
    // Test white pawn movement
    // Set up a white pawn at e2 (index 12)
    board.setWhitePawns(1ULL << 12);
    
    // Test single step forward (e2 -> e3)
    assert(Validator::isValidMove(board, Move(12, 20, '\0')));
    
    // Test double step forward (e2 -> e4)
    assert(Validator::isValidMove(board, Move(12, 28, '\0')));
    
    // Test blocked single step
    board.setBlackPawns(1ULL << 20);  // Block e3
    assert(!Validator::isValidMove(board, Move(12, 20, '\0')));
    
    // Test blocked double step
    board.setBlackPawns(1ULL << 28);  // Block e4
    assert(!Validator::isValidMove(board, Move(12, 28, '\0')));
    
    // Test diagonal capture (e2 -> f3 capture)
    board.setBlackPawns(1ULL << 21);  // Place black pawn at f3
    assert(Validator::isValidMove(board, Move(12, 21, '\0')));
    
    // Test invalid diagonal move (no piece to capture)
    board.clearPiece(21);  // Remove black pawn
    assert(!Validator::isValidMove(board, Move(12, 21, '\0')));
    
    // Test invalid diagonal move (own piece)
    board.setWhitePawns(1ULL << 21);  // Place white pawn at f3
    assert(!Validator::isValidMove(board, Move(12, 21, '\0')));
    
    // Test black pawn movement
    board.clearBoard();
    board.setBlackPawns(1ULL << 52);  // Place black pawn at e7
    board.setTurn(Color::BLACK);
    
    // Test single step forward (e7 -> e6)
    assert(Validator::isValidMove(board, Move(52, 44, '\0')));
    
    // Test double step forward (e7 -> e5)
    assert(Validator::isValidMove(board, Move(52, 36, '\0')));
    
    // Test blocked single step
    board.setWhitePawns(1ULL << 44);  // Block e6
    assert(!Validator::isValidMove(board, Move(52, 44, '\0')));
    
    // Test blocked double step
    board.setWhitePawns(1ULL << 36);  // Block e5
    assert(!Validator::isValidMove(board, Move(52, 36, '\0')));
    
    // Test diagonal capture (e7 -> f6 capture)
    board.setWhitePawns(1ULL << 45);  // Place white pawn at f6
    assert(Validator::isValidMove(board, Move(52, 45, '\0')));
    
    // Test invalid diagonal move (no piece to capture)
    board.clearPiece(45);  // Remove white pawn
    assert(!Validator::isValidMove(board, Move(52, 45, '\0')));
    
    // Test invalid diagonal move (own piece)
    board.setBlackPawns(1ULL << 45);  // Place black pawn at f6
    assert(!Validator::isValidMove(board, Move(52, 45, '\0')));
    
    std::cout << "Pawn movement tests passed!" << std::endl;
}

void knightMovementTest() {
    Board board;
    board.clearBoard();
    
    // Test white knight movement
    board.setWhiteKnights(1ULL << 1);  // Place white knight at b1
    board.setTurn(Color::WHITE);
    
    // Test valid L-shaped moves
    assert(Validator::isValidMove(board, Move(1, 16, '\0')));  // b1 -> a3
    assert(Validator::isValidMove(board, Move(1, 18, '\0')));  // b1 -> c3
    assert(Validator::isValidMove(board, Move(1, 11, '\0')));  // b1 -> d2
    
    // Test invalid moves
    assert(!Validator::isValidMove(board, Move(1, 9, '\0')));   // b1 -> b2 (not L-shaped)
    assert(!Validator::isValidMove(board, Move(1, 10, '\0')));  // b1 -> c2 (not L-shaped)
    
    // Test jumping over pieces
    board.setWhitePawns(1ULL << 8);   // Place white pawn at a2
    board.setWhitePawns(1ULL << 10);  // Place white pawn at c2
    assert(Validator::isValidMove(board, Move(1, 16, '\0')));
    assert(Validator::isValidMove(board, Move(1, 18, '\0')));
    
    // Test black knight movement
    board.clearBoard();
    board.setBlackKnights(1ULL << 57);  // Place black knight at b8
    board.setTurn(Color::BLACK);
    
    // Test valid L-shaped moves
    assert(Validator::isValidMove(board, Move(57, 40, '\0')));  // b8 -> a6
    assert(Validator::isValidMove(board, Move(57, 42, '\0')));  // b8 -> c6
    assert(Validator::isValidMove(board, Move(57, 51, '\0')));  // b8 -> d7
    
    // Test invalid moves
    assert(!Validator::isValidMove(board, Move(57, 49, '\0')));  // b8 -> b7 (not L-shaped)
    assert(!Validator::isValidMove(board, Move(57, 50, '\0')));  // b8 -> c7 (not L-shaped)
    
    // Test jumping over pieces
    board.setBlackPawns(1ULL << 48);  // Place black pawn at a7
    board.setBlackPawns(1ULL << 50);  // Place black pawn at c7
    assert(Validator::isValidMove(board, Move(57, 40, '\0')));
    assert(Validator::isValidMove(board, Move(57, 42, '\0')));
    
    std::cout << "Knight movement tests passed!" << std::endl;
}

void kingMovementTest() {
    Board board;
    board.clearBoard();
    
    // Test white king movement
    board.setWhiteKing(1ULL << 4);  // Place white king at e1
    board.setTurn(Color::WHITE);
    
    // Test normal moves
    assert(Validator::isValidMove(board, Move(4, 3, '\0')));   // e1 -> d1
    assert(Validator::isValidMove(board, Move(4, 5, '\0')));   // e1 -> f1
    assert(Validator::isValidMove(board, Move(4, 11, '\0')));  // e1 -> d2
    assert(Validator::isValidMove(board, Move(4, 12, '\0')));  // e1 -> e2
    assert(Validator::isValidMove(board, Move(4, 13, '\0')));  // e1 -> f2
    
    // Test invalid moves (more than one square)
    assert(!Validator::isValidMove(board, Move(4, 2, '\0')));   // e1 -> c1
    assert(!Validator::isValidMove(board, Move(4, 20, '\0')));  // e1 -> e3
    
    // Test kingside castling
    board.setWhiteRooks(1ULL << 7);  // Place white rook at h1
    assert(Validator::isValidMove(board, Move(4, 6, '\0')));   // e1 -> g1 (castling)
    
    // Test queenside castling
    board.setWhiteRooks(1ULL << 0);  // Place white rook at a1
    assert(Validator::isValidMove(board, Move(4, 2, '\0')));   // e1 -> c1 (castling)
    
    // Test castling with pieces in between
    board.setWhiteKnights(1ULL << 1);  // Place white knight at b1
    assert(!Validator::isValidMove(board, Move(4, 2, '\0')));  // Queenside castling should fail
    
    board.setWhiteBishops(1ULL << 5);  // Place white bishop at f1
    assert(!Validator::isValidMove(board, Move(4, 6, '\0')));  // Kingside castling should fail
    
    // Test black king movement
    board.clearBoard();
    board.setBlackKing(1ULL << 60);  // Place black king at e8
    board.setTurn(Color::BLACK);
    
    // Test normal moves
    assert(Validator::isValidMove(board, Move(60, 59, '\0')));  // e8 -> d8
    assert(Validator::isValidMove(board, Move(60, 61, '\0')));  // e8 -> f8
    assert(Validator::isValidMove(board, Move(60, 51, '\0')));  // e8 -> d7
    assert(Validator::isValidMove(board, Move(60, 52, '\0')));  // e8 -> e7
    assert(Validator::isValidMove(board, Move(60, 53, '\0')));  // e8 -> f7
    
    // Test kingside castling
    board.setBlackRooks(1ULL << 63);  // Place black rook at h8
    assert(Validator::isValidMove(board, Move(60, 62, '\0')));  // e8 -> g8 (castling)
    
    // Test queenside castling
    board.setBlackRooks(1ULL << 56);  // Place black rook at a8
    assert(Validator::isValidMove(board, Move(60, 58, '\0')));  // e8 -> c8 (castling)
    
    // Test castling with pieces in between
    board.setBlackKnights(1ULL << 57);  // Place black knight at b8
    assert(!Validator::isValidMove(board, Move(60, 58, '\0')));  // Queenside castling should fail
    
    board.setBlackBishops(1ULL << 61);  // Place black bishop at f8
    assert(!Validator::isValidMove(board, Move(60, 62, '\0')));  // Kingside castling should fail
    
    std::cout << "King movement tests passed!" << std::endl;
}

int main() {
    std::cout << "Running Tests...\n\n";
    
    testBoardFileRank();
    testBoardIndexToTile();
    testBoardTileToIndex();
    testMoveString();
    testPrintBoard();
    testPieceSettingAndClearing();
    testIsPathClear();
    pawnMovementTest();
    knightMovementTest();
    kingMovementTest();
    
    std::cout << "All tests passed successfully!\n";

    return 0;
}