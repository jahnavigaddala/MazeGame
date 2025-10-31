#ifndef MAZE_H
#define MAZE_H

#include "Position.h"
#include <vector>
#include <iostream>

class Maze {
private:
    std::vector<std::vector<char>>* grid;
    Position* playerPos;
    Position* endPos;

public:
    Maze(Position start, Position end, int level);
    ~Maze();
    bool isWithinBounds(const Position& pos) const;
    bool isPath(const Position& pos) const;
    void display() const;
    Maze& updatePlayerPosition(const Position& newPos);
    bool reachedEnd() const;
    Position getPlayerPosition() const;
};

#endif
