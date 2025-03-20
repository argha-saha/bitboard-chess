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

int main() {
    std::cout << "Running Tests...\n\n";
    
    testBoardFileRank();
    testBoardIndexToTile();
    testBoardTileToIndex();
    testMoveString();
    testPrintBoard();
    testPieceSettingAndClearing();
    testIsPathClear();
    
    std::cout << "All tests passed successfully!\n";

    return 0;
} 