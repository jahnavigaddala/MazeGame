#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position {
public:
    int x, y;
    Position(int x = 0, int y = 0);
    Position operator+(const Position& other) const;
    bool operator==(const Position& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Position& pos);
    friend std::istream& operator>>(std::istream& is, Position& pos);
};

#endif
