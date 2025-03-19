#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include <string>

class Move {
private:
    int fromTile;
    int toTile;
    char promotion;

public:
    Move(int fromTile, int toTile, char promotion);
    [[nodiscard]] int getFromTile() const;
    [[nodiscard]] int getToTile() const;
    [[nodiscard]] char getPromotion() const;

    static Move moveString(const std::string& move);
};

#endif // CHESS_MOVE_H
