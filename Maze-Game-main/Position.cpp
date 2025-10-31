#include "Position.h"

Position::Position(int x, int y) : x(x), y(y) {}

Position Position::operator+(const Position& other) const {
    return Position(x + other.x, y + other.y);
}

bool Position::operator==(const Position& other) const {
    return x == other.x && y == other.y;
}

std::ostream& operator<<(std::ostream& os, const Position& pos) {
    os << "(" << pos.x << ", " << pos.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Position& pos) {
    is >> pos.x >> pos.y;
    return is;
}
