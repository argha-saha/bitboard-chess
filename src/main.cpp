#include "Application.h"
#include "Game.h"
#include "Board.h"
#include <cassert>

void testPrintBoard() {
    Game game;
    game.printBoard();
}

void boardFileRankTests() {
    int file = Board::getFile(4);
    assert(file == 4);

    int rank = Board::getRank(16);
    assert(rank == 2);
}

void boardIndexToTileTest() {
    std::string tile = Board::indexToTile(63);
    assert(tile == "h8");
}

void boardTileToIndexTest() {

}

int main(int argc, char *argv[])
{
//    Application app;
//
//    if (!app.init()) {
//        return 1;
//    }
//
//    app.run();

    testPrintBoard();
    boardFileRankTests();
    boardIndexToTileTest();
    
    return 0;
}