#include "Application.h"
#include "Game.h"
#include "Board.h"
#include <cassert>

void printBoardTest() {
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
    int index = Board::tileToIndex("h8");
    assert(index == 63);

    index = Board::tileToIndex("h9");
    assert(index == -1);
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

    printBoardTest();
    boardFileRankTests();
    boardIndexToTileTest();
    boardTileToIndexTest();
    
    return 0;
}