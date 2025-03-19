#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include <string>

class Move {
private:
    int fromTile;
    int toTile;

public:
    Move(int fromTile, int toTile);

    static Move moveString(const std::string& move);

    // TODO: Add promotion logic (reference UCI)
};

#endif // CHESS_MOVE_H
