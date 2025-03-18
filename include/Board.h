#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include "Piece.h"

class Board {
private:
    int numRows = 0;
    int numCols = 0;
    std::vector<std::vector<Piece *>> board;
};

#endif // CHESS_BOARD_H