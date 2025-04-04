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
    assert(moveStr.getFromTile() == e2);
    assert(moveStr.getToTile() == e4);
    assert(moveStr.getPromotion() == '\0');
    std::cout << "PASS: moveString()\n";

    moveStr = Move::moveString("e7e8q");
    assert(moveStr.getFromTile() == e7);
    assert(moveStr.getToTile() == e8);
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
    board.setWhitePawns(1ULL << a1);
    assert(board.getWhitePawns() == (1ULL << 0));
    std::cout << "PASS: setWhitePawns()\n";
    
    board.setWhiteKnights(1ULL << b1);
    assert(board.getWhiteKnights() == (1ULL << 1));
    std::cout << "PASS: setWhiteKnights()\n";
    
    board.setWhiteBishops(1ULL << c1);
    assert(board.getWhiteBishops() == (1ULL << 2));
    std::cout << "PASS: setWhiteBishops()\n";
    
    board.setWhiteRooks(1ULL << d1);
    assert(board.getWhiteRooks() == (1ULL << 3));
    std::cout << "PASS: setWhiteRooks()\n";
    
    board.setWhiteQueens(1ULL << e1);
    assert(board.getWhiteQueens() == (1ULL << 4));
    std::cout << "PASS: setWhiteQueens()\n";
    
    board.setWhiteKing(1ULL << f1);
    assert(board.getWhiteKing() == (1ULL << 5));
    std::cout << "PASS: setWhiteKing()\n";

    board.setWhitePawns(1ULL << g1);
    assert(board.getWhitePawns() == (1ULL << 6));
    std::cout << "PASS: setWhitePawns()\n";

    board.setWhiteKnights(1ULL << h1);
    assert(board.getWhiteKnights() == (1ULL << 7));
    std::cout << "PASS: setWhiteKnights()\n";
    
    // Test setting black pieces
    board.setBlackPawns(1ULL << a8);
    assert(board.getBlackPawns() == (1ULL << 56));
    std::cout << "PASS: setBlackPawns()\n";
    
    board.setBlackKnights(1ULL << b8);
    assert(board.getBlackKnights() == (1ULL << 57));
    std::cout << "PASS: setBlackKnights()\n";
    
    board.setBlackBishops(1ULL << c8);
    assert(board.getBlackBishops() == (1ULL << 58));
    std::cout << "PASS: setBlackBishops()\n";
    
    board.setBlackRooks(1ULL << d8);
    assert(board.getBlackRooks() == (1ULL << 59));
    std::cout << "PASS: setBlackRooks()\n";
    
    board.setBlackQueens(1ULL << e8);
    assert(board.getBlackQueens() == (1ULL << 60));
    std::cout << "PASS: setBlackQueens()\n";
    
    board.setBlackKing(1ULL << f8);
    assert(board.getBlackKing() == (1ULL << 61));
    std::cout << "PASS: setBlackKing()\n";

    board.setBlackPawns(1ULL << g8);
    assert(board.getBlackPawns() == (1ULL << 62));
    std::cout << "PASS: setBlackPawns()\n";

    board.setBlackKnights(1ULL << h8);
    assert(board.getBlackKnights() == (1ULL << 63));
    std::cout << "PASS: setBlackKnights()\n";
    
    // Test clearing pieces
    board.clearPiece(a1);
    board.clearPiece(g1);
    assert(board.getWhitePawns() == 0);
    std::cout << "PASS: clearPiece()\n";
    
    board.clearPiece(a8);
    board.clearPiece(g8);
    assert(board.getBlackPawns() == 0);
    std::cout << "PASS: clearPiece()\n";
    
    board.clearPiece(b1);
    board.clearPiece(h1);
    board.clearPiece(b8);
    board.clearPiece(h8);
    assert(board.getWhiteKnights() == 0 && board.getBlackKnights() == 0);
    std::cout << "PASS: clearPiece()";
    
    std::cout << std::endl;
}

void testIsPathClear() {
    Board board;

    for (int i = 0; i < 64; i++) {
        board.clearPiece(i);
    }
    
    // Test diagonal path (empty)
    assert(Validator::isPathClear(board, File::a, 0, 7, 7) == true);
    std::cout << "PASS: isPathClear() - empty diagonal path\n";
    
    // Test diagonal path (blocked)
    board.setWhitePawns(1ULL << d4);
    assert(Validator::isPathClear(board, 0, 0, 7, 7) == false);
    std::cout << "PASS: isPathClear() - blocked diagonal path\n";
    
    // Test horizontal path (empty)
    board.clearPiece(d4);  // Clear the blocking pawn
    assert(Validator::isPathClear(board, 0, 0, 7, 0) == true);
    std::cout << "PASS: isPathClear() - empty horizontal path\n";
    
    // Test horizontal path (blocked)
    board.setWhitePawns(1ULL << f1);
    assert(Validator::isPathClear(board, 0, 0, 7, 0) == false);
    std::cout << "PASS: isPathClear() - blocked horizontal path\n";
    
    // Test vertical path (empty)
    board.clearPiece(f1);  // Clear the blocking pawn
    assert(Validator::isPathClear(board, 0, 0, 0, 7) == true);
    std::cout << "PASS: isPathClear() - empty vertical path\n";
    
    // Test vertical path (blocked)
    board.setWhitePawns(1ULL << a5);
    assert(Validator::isPathClear(board, 0, 0, 0, 7) == false);
    std::cout << "PASS: isPathClear() - blocked vertical path\n";
    
    // Test path with piece at destination (should be clear)
    board.clearPiece(a5);  // Clear the blocking pawn
    board.setBlackRooks(1ULL << h8);
    assert(Validator::isPathClear(board, 0, 0, 7, 7) == true);
    std::cout << "PASS: isPathClear() - path with piece at destination";
    
    std::cout << std::endl;
}

void pawnMovementTest() {
    Board board;
    board.clearBoard();
    
    // Test white pawn movement
    board.setWhitePawns(1ULL << e2);
    
    // Test single step forward
    assert(Validator::isValidMove(board, Move(e2, e3, '\0')));
    
    // Test double step forward
    assert(Validator::isValidMove(board, Move(e2, e4, '\0')));
    
    // Test blocked single step
    board.setBlackPawns(1ULL << e3);  // Block e3
    assert(!Validator::isValidMove(board, Move(e2, e3, '\0')));
    
    // Test blocked double step
    board.setBlackPawns(1ULL << e4);  // Block e4
    assert(!Validator::isValidMove(board, Move(e2, e4, '\0')));
    
    // Test diagonal capture (e2 -> f3 capture)
    board.setBlackPawns(1ULL << f3);
    assert(Validator::isValidMove(board, Move(e2, f3, '\0')));
    
    // Test invalid diagonal move (no piece to capture)
    board.clearPiece(f3);  // Remove black pawn
    assert(!Validator::isValidMove(board, Move(e2, f3, '\0')));
    
    // Test invalid diagonal move (own piece)
    board.setWhitePawns(1ULL << f3);  // Place white pawn at f3
    assert(!Validator::isValidMove(board, Move(e2, f3, '\0')));
    
    // Test black pawn movement
    board.clearBoard();
    board.setBlackPawns(1ULL << e7);
    board.setTurn(Color::BLACK);
    
    // Test single step forward
    assert(Validator::isValidMove(board, Move(e7, e6, '\0')));
    
    // Test double step forward
    assert(Validator::isValidMove(board, Move(e7, e5, '\0')));
    
    // Test blocked single step
    board.setWhitePawns(1ULL << e6);  // Block e6
    assert(!Validator::isValidMove(board, Move(e7,e6, '\0')));
    
    // Test blocked double step
    board.setWhitePawns(1ULL << e5);  // Block e5
    assert(!Validator::isValidMove(board, Move(e7, e5, '\0')));
    
    // Test diagonal capture (e7 -> f6 capture)
    board.setWhitePawns(1ULL << f6);
    assert(Validator::isValidMove(board, Move(e7, f6, '\0')));
    
    // Test invalid diagonal move (no piece to capture)
    board.clearPiece(f6);  // Remove white pawn
    assert(!Validator::isValidMove(board, Move(e7, f6, '\0')));
    
    // Test invalid diagonal move (own piece)
    board.setBlackPawns(1ULL << f6);  // Place black pawn at f6
    assert(!Validator::isValidMove(board, Move(e7, f6, '\0')));
    
    std::cout << "Pawn movement tests passed!" << std::endl;
}

void knightMovementTest() {
    Board board;
    board.clearBoard();
    
    // Test white knight movement
    board.setWhiteKnights(1ULL << b1);
    board.setTurn(Color::WHITE);
    
    // Test valid L-shaped moves
    assert(Validator::isValidMove(board, Move(b1, a3, '\0')));
    assert(Validator::isValidMove(board, Move(b1, c3, '\0')));
    assert(Validator::isValidMove(board, Move(b1, d2, '\0')));
    
    // Test invalid moves
    assert(!Validator::isValidMove(board, Move(b1, b2, '\0')));  // Not L-shaped
    assert(!Validator::isValidMove(board, Move(b1, c2, '\0')));  // Not L-shaped
    
    // Test jumping over pieces
    board.setWhitePawns(1ULL << a2);
    board.setWhitePawns(1ULL << c2);
    assert(Validator::isValidMove(board, Move(b1, a3, '\0')));
    assert(Validator::isValidMove(board, Move(b1, c3, '\0')));
    
    // Test black knight movement
    board.clearBoard();
    board.setBlackKnights(1ULL << b8);
    board.setTurn(Color::BLACK);
    
    // Test valid L-shaped moves
    assert(Validator::isValidMove(board, Move(b8, a6, '\0')));
    assert(Validator::isValidMove(board, Move(b8, c6, '\0')));
    assert(Validator::isValidMove(board, Move(b8, d7, '\0')));
    
    // Test invalid moves
    assert(!Validator::isValidMove(board, Move(b8, b7, '\0')));  // Not L-shaped
    assert(!Validator::isValidMove(board, Move(b8, c7, '\0')));  // Not L-shaped
    
    // Test jumping over pieces
    board.setBlackPawns(1ULL << a7);
    board.setBlackPawns(1ULL << c7);
    assert(Validator::isValidMove(board, Move(b8, a6, '\0')));
    assert(Validator::isValidMove(board, Move(b8, c6, '\0')));
    
    std::cout << "Knight movement tests passed!" << std::endl;
}

void kingMovementTest() {
    Board board;
    board.clearBoard();
    
    // Test white king movement
    board.setWhiteKing(1ULL << e1);
    board.setTurn(Color::WHITE);
    
    // Test normal moves
    assert(Validator::isValidMove(board, Move(e1, d1, '\0')));
    assert(Validator::isValidMove(board, Move(e1, f1, '\0')));
    assert(Validator::isValidMove(board, Move(e1, d2, '\0')));
    assert(Validator::isValidMove(board, Move(e1, e2, '\0')));
    assert(Validator::isValidMove(board, Move(e1, f2, '\0')));
    
    // Test invalid moves (more than one square)
    assert(!Validator::isValidMove(board, Move(e1, c1, '\0')));
    assert(!Validator::isValidMove(board, Move(e1, e3, '\0')));
    
    // Test kingside castling
    board.setWhiteRooks(1ULL << h1);
    assert(Validator::isValidMove(board, Move(e1, g1, '\0')));   // Castling
    
    // Test queenside castling
    board.setWhiteRooks(1ULL << a1);
    assert(Validator::isValidMove(board, Move(e1, c1, '\0')));   // Castling
    
    // Test castling with pieces in between
    board.setWhiteKnights(1ULL << b1);
    assert(!Validator::isValidMove(board, Move(e1, b1, '\0')));  // Queenside castling fail
    
    board.setWhiteBishops(1ULL << f1);
    assert(!Validator::isValidMove(board, Move(e1, g1, '\0')));  // Kingside castling fail
    
    // Test black king movement
    board.clearBoard();
    board.setBlackKing(1ULL << e8);
    board.setTurn(Color::BLACK);
    
    // Test normal moves
    assert(Validator::isValidMove(board, Move(e8, d8, '\0')));
    assert(Validator::isValidMove(board, Move(e8, f8, '\0')));
    assert(Validator::isValidMove(board, Move(e8, d7, '\0')));
    assert(Validator::isValidMove(board, Move(e8, e7, '\0')));
    assert(Validator::isValidMove(board, Move(e8, f7, '\0')));
    
    // Test kingside castling
    board.setBlackRooks(1ULL << h8);
    assert(Validator::isValidMove(board, Move(e8, g8, '\0')));
    
    // Test queenside castling
    board.setBlackRooks(1ULL << a8);
    assert(Validator::isValidMove(board, Move(e8, c8, '\0')));
    
    // Test castling with pieces in between
    board.setBlackKnights(1ULL << b8);
    assert(!Validator::isValidMove(board, Move(e8, c8, '\0')));  // Queenside castling fail
    
    board.setBlackBishops(1ULL << f8);
    assert(!Validator::isValidMove(board, Move(e8, g8, '\0')));  // Kingside castling fail
    
    std::cout << "King movement tests passed!" << std::endl;
}

void threatDetectionTest() {
    Board board;
    board.clearBoard();
    
    // Test white pawn threats
    board.setWhitePawns(1ULL << d5);
    assert(Validator::isUnderThreat(board, e6, true));  // e6 is threatened
    assert(Validator::isUnderThreat(board, c6, true));  // c6 is threatened
    assert(!Validator::isUnderThreat(board, d6, true)); // d6 is not threatened
    assert(!Validator::isUnderThreat(board, d4, true)); // d4 is not threatened
    
    board.clearBoard();

    // Test black pawn threats
    board.setBlackPawns(1ULL << d4);
    assert(Validator::isUnderThreat(board, e3, false));  // e3 is threatened
    assert(Validator::isUnderThreat(board, c3, false));  // c3 is threatened
    assert(!Validator::isUnderThreat(board, d3, false)); // d3 is not threatened
    assert(!Validator::isUnderThreat(board, d5, false)); // d5 is not threatened
    
    board.clearBoard();

    // Test knight threats
    board.setWhiteKnights(1ULL << e4);
    assert(Validator::isUnderThreat(board, d6, true));  // d6 is threatened
    assert(Validator::isUnderThreat(board, f6, true));  // f6 is threatened
    assert(Validator::isUnderThreat(board, c5, true));  // c5 is threatened
    assert(Validator::isUnderThreat(board, g5, true));  // g5 is threatened
    assert(!Validator::isUnderThreat(board, e5, true)); // e5 is not threatened
    
    board.clearBoard();

    // Test bishop threats
    board.setBlackBishops(1ULL << e4);
    assert(Validator::isUnderThreat(board, d5, false));  // d5 is threatened
    assert(Validator::isUnderThreat(board, f5, false));  // f5 is threatened
    assert(Validator::isUnderThreat(board, d3, false));  // d3 is threatened
    assert(Validator::isUnderThreat(board, f3, false));  // f3 is threatened
    assert(!Validator::isUnderThreat(board, f4, false)); // f4 is not threatened
    
    // Test blocked bishop
    board.setWhitePawns(1ULL << d5); // White pawn at d5
    assert(!Validator::isUnderThreat(board, c6, false)); // c6 is not threatened (blocked)
    
    board.clearBoard();

    // Test rook threats
    board.setWhiteRooks(1ULL << e4);
    assert(Validator::isUnderThreat(board, e5, true));  // e5 is threatened
    assert(Validator::isUnderThreat(board, d4, true));  // d4 is threatened
    assert(Validator::isUnderThreat(board, f4, true));  // f4 is threatened
    assert(Validator::isUnderThreat(board, e3, true));  // e3 is threatened
    assert(Validator::isUnderThreat(board, e7, true));  // e7 is threatened
    assert(!Validator::isUnderThreat(board, f5, true)); // f5 is not threatened
    
    // Test blocked rook
    board.setBlackPawns(1ULL << f4);
    assert(!Validator::isUnderThreat(board, h4, true)); // h4 is not threatened (blocked)
    
    board.clearBoard();

    // Test queen threats
    board.setBlackQueens(1ULL << e4);
    assert(Validator::isUnderThreat(board, d4, false)); // d4 is threatened (horizontal)
    assert(Validator::isUnderThreat(board, f4, false)); // f4 is threatened (horizontal)
    assert(Validator::isUnderThreat(board, g4, false)); // g4 is threatened (horizontal)
    assert(Validator::isUnderThreat(board, d5, false)); // d5 is threatened (diagonal)
    assert(Validator::isUnderThreat(board, e5, false)); // e5 is threatened (vertical)
    assert(Validator::isUnderThreat(board, f5, false)); // f5 is threatened (diagonal)
    assert(Validator::isUnderThreat(board, d3, false)); // d3 is threatened (diagonal)
    assert(Validator::isUnderThreat(board, e3, false)); // e3 is threatened (vertical)
    assert(Validator::isUnderThreat(board, f3, false)); // f3 is threatened (diagonal)
    
    // Test blocked queen
    board.setWhitePawns(1ULL << f4);
    assert(!Validator::isUnderThreat(board, h4, false)); // h4 is not threatened (blocked)
    
    board.clearBoard();

    // Test king threats
    board.setWhiteKing(1ULL << e4);
    assert(Validator::isUnderThreat(board, d4, true));  // d4 is threatened
    assert(Validator::isUnderThreat(board, f4, true));  // f4 is threatened
    assert(Validator::isUnderThreat(board, d5, true));  // d5 is threatened
    assert(Validator::isUnderThreat(board, e5, true));  // e5 is threatened
    assert(Validator::isUnderThreat(board, f5, true));  // f5 is threatened
    assert(Validator::isUnderThreat(board, d3, true));  // d3 is threatened
    assert(Validator::isUnderThreat(board, e3, true));  // e3 is threatened
    assert(Validator::isUnderThreat(board, f3, true));  // f3 is threatened
    assert(!Validator::isUnderThreat(board, e6, true)); // e6 is not threatened (too far)
    
    // Test multiple threats
    board.clearBoard();
    board.setWhiteQueens(1ULL << d4);  // White queen at d4
    board.setWhiteKnights(1ULL << e3);  // White knight at e3
    assert(Validator::isUnderThreat(board, e5, true));  // e5 is threatened by both pieces
    
    // Test through check
    board.clearBoard();
    board.setBlackRooks(1ULL << d4);  // Black rook at d4
    board.setBlackPawns(1ULL << e4);  // Black pawn at e4
    assert(Validator::isUnderThreat(board, d3, false));  // d3 is threatened
    assert(!Validator::isUnderThreat(board, g4, false));  // g4 is not threatened (blocked)
    
    std::cout << "Threat detection tests passed!" << std::endl;
}

void movePieceTest() {
    Board board;
    board.clearBoard();
    
    // Test regular piece movement
    board.setWhitePawns(1ULL << e2);
    board.movePiece(e2, e3);
    assert((board.getWhitePawns() & (1ULL << e2)) == 0);
    assert(board.getWhitePawns() == (1ULL << e3));
    assert(board.getTurn() == Color::BLACK);
    std::cout << "PASS: Basic pawn movement and turn switch\n";
    
    // Test capture
    board.setBlackPawns(1ULL << f4);
    board.setTurn(Color::WHITE);
    board.movePiece(e3, f4);  // Capture at f4
    assert(board.getWhitePawns() == (1ULL << f4));
    assert(board.getBlackPawns() == 0);  // Black pawn should be captured
    assert(board.getTurn() == Color::BLACK);
    std::cout << "PASS: Capture and piece removal\n";
    
    // Test white kingside castling
    board.clearBoard();
    board.setWhiteKing(1ULL << e1);
    board.setWhiteRooks(1ULL << h1);
    board.setTurn(Color::WHITE);
    board.movePiece(e1, g1);       // Castle kingside
    assert(board.getWhiteKing() == (1ULL << g1));   // King should be on g1
    assert(board.getWhiteRooks() == (1ULL << f1));  // Rook should be on f1
    assert(board.hasWhiteKingMoved());
    assert(board.hasWhiteKingSideRookMoved());
    std::cout << "PASS: White kingside castling\n";
    
    // Test white queenside castling
    board.clearBoard();
    board.setWhiteKing(1ULL << e1);
    board.setWhiteRooks(1ULL << a1);
    board.setTurn(Color::WHITE);
    board.movePiece(4, 2);         // Castle queenside
    assert(board.getWhiteKing() == (1ULL << c1));   // King should be on c1
    assert(board.getWhiteRooks() == (1ULL << d1));  // Rook should be on d1
    assert(board.hasWhiteKingMoved());
    assert(board.hasWhiteQueenSideRookMoved());
    std::cout << "PASS: White queenside castling\n";
    
    // Test black kingside castling
    board.clearBoard();
    board.setBlackKing(1ULL << e8);
    board.setBlackRooks(1ULL << h8);
    board.setTurn(Color::BLACK);
    board.movePiece(e8, g8);       // Castle kingside
    assert(board.getBlackKing() == (1ULL << g8));   // King should be on g8
    assert(board.getBlackRooks() == (1ULL << f8));  // Rook should be on f8
    assert(board.hasBlackKingMoved());
    assert(board.hasBlackKingSideRookMoved());
    std::cout << "PASS: Black kingside castling\n";
    
    // Test black queenside castling
    board.clearBoard();
    board.setBlackKing(1ULL << e8);
    board.setBlackRooks(1ULL << a8);
    board.setTurn(Color::BLACK);
    board.movePiece(e8, c8);       // Castle queenside
    assert(board.getBlackKing() == (1ULL << c8));   // King should be on c8
    assert(board.getBlackRooks() == (1ULL << d8));  // Rook should be on d8
    assert(board.hasBlackKingMoved());
    assert(board.hasBlackQueenSideRookMoved());
    std::cout << "PASS: Black queenside castling\n";
    
    // Test rook movement and castling flag updates
    board.clearBoard();
    board.setWhiteRooks(1ULL << a1);
    board.setTurn(Color::WHITE);
    board.movePiece(0, a2);
    assert(board.hasWhiteQueenSideRookMoved());
    assert(board.getWhiteRooks() == (1ULL << a2));
    std::cout << "PASS: Rook movement and castling flag update\n";
    
    // Ensure moving a piece doesn't move other pieces
    board.clearBoard();
    board.setWhitePawns(1ULL << a1);
    board.setWhiteKnights(1ULL << b1);
    board.setWhiteBishops(1ULL << c1);
    board.setWhiteQueens(1ULL << d1);
    board.setWhiteKing(1ULL << e1);
    board.setTurn(Color::WHITE);
    
    board.movePiece(d1, d2);  // Move queen to d2
    assert(board.getWhitePawns() == (1ULL << a1));
    assert(board.getWhiteKnights() == (1ULL << b1));
    assert(board.getWhiteBishops() == (1ULL << c1));
    assert(board.getWhiteQueens() == (1ULL << d2));
    assert(board.getWhiteKing() == (1ULL << e1));
}

void checkDetectionTest() {
    Board board;
    board.clearBoard();
    
    // Test white king in check
    board.setWhiteKing(1ULL << e1);
    board.setBlackRooks(1ULL << e2);
    assert(Validator::isInCheck(board, true));  // White king should be in check
    std::cout << "PASS: White king in check from rook\n";
    
    // Test white king not in check
    board.setBlackRooks(1ULL << f2);  // Move rook to f2
    // std::bitset<64> x(board.getBlackRooks());
    // std::cout << x << std::endl;
    assert(!Validator::isInCheck(board, true));  // White king should not be in check
    std::cout << "PASS: White king not in check\n";
    
    board.clearBoard();

    // Test black king in check
    board.setBlackKing(1ULL << e8);
    board.setWhiteRooks(1ULL << e7);
    assert(Validator::isInCheck(board, false));  // Black king should be in check
    std::cout << "PASS: Black king in check from rook\n";
    
    // Test black king not in check
    board.setWhiteRooks(1ULL << f7);  // Move rook to f7
    assert(!Validator::isInCheck(board, false));  // Black king should not be in check
    std::cout << "PASS: Black king not in check\n";
    
    // Test check from multiple pieces
    board.clearBoard();
    board.setWhiteKing(1ULL << e1);
    board.setBlackRooks(1ULL << e2);
    board.setBlackQueens(1ULL << f2);
    assert(Validator::isInCheck(board, true));  // White king should be in check
    std::cout << "PASS: King in check from multiple pieces\n";
    
    std::cout << "Check detection tests passed!" << std::endl << std::endl;
}

void kingTakeKingTest() {
    Board board;
    board.clearBoard();

    board.setWhiteKing(1ULL << e1);
    board.setBlackKing(1ULL << e3);

    // Black king should not be able to move to e2
    assert(!Validator::isValidMove(board, Move(e3, e2, '\0')));
}

void pawnMovesTest() {
    Board board;
    board.clearBoard();

    board.setWhitePawns(1ULL << e2);
    assert(Validator::isValidMove(board, Move(e2, e4, '\0')));
    board.movePiece(e2, e4);

    // Make sure pawn can't double move again
    assert(!Validator::isValidMove(board, Move(e4, e6, '\0')));
}

void foolsMateTest() {
    Board board;

    board.movePiece(f2, f3);
    board.movePiece(e7, e5);
    board.movePiece(g2, g4);
    board.movePiece(d8, h4);

    // Game::printBoard(board);

    bool turn = board.getTurn() == Color::WHITE;

    assert(Validator::isInCheck(board, turn));
    assert(Validator::isCheckmate(board, turn));
    assert(!Validator::isStalemate(board, turn));
}

void shortestStalemateTest() {
    Board board;
    
    board.movePiece(e2, e3);  // e3
    board.movePiece(a7, a5);  // a5

    board.movePiece(d1, h5);  // Qh5
    board.movePiece(a8, a6);  // Ra6

    board.movePiece(h5, a5);  // Qxa5
    board.movePiece(h7, h5);  // h5

    board.movePiece(a5, c7);  // Qxc7
    board.movePiece(a6, h6);  // Rah6

    board.movePiece(h2, h4);  // h4
    board.movePiece(f7, f6);  // f6

    board.movePiece(c7, d7);  // Qxd7+
    board.movePiece(e8, f7);  // Kf7

    board.movePiece(d7, b7);  // Qxb7
    board.movePiece(d8, d3);  // Qd3

    board.movePiece(b7, b8);  // Qxb8
    board.movePiece(d3, h7);  // Qh7

    board.movePiece(b8, c8);  // Qxc8
    board.movePiece(f7, g6);  // Kg6

    board.movePiece(c8, e6);  // Qe6
    assert(Validator::isStalemate(board, board.getTurn() == Color::WHITE));

    // Game::printBoard(board);
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
    threatDetectionTest();
    movePieceTest();
    checkDetectionTest();
    kingTakeKingTest();
    pawnMovesTest();
    foolsMateTest();
    shortestStalemateTest();
    
    std::cout << "All tests passed successfully!\n";

    return 0;
}