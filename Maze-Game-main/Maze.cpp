#include "Maze.h"
using namespace std; 
Maze::Maze(Position start, Position end, int level) 
    : playerPos(new Position(start)), endPos(new Position(end)) {
    grid = new std::vector<std::vector<char>>;

    if (level == 1) {
        *grid = {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', 'P', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
            {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
            {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', 'E', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
        };
    } else {
        *grid = {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', 'P', ' ', '#', '#', ' ', '#', '#', ' ', '#'},
            {'#', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', '#', ' ', '#', ' ', '#', '#', '#'},
            {'#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', '#', ' ', ' ', '#', 'E', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
        };
    }

    (*grid)[playerPos->x][playerPos->y] = 'P';
    (*grid)[endPos->x][endPos->y] = 'E';
}

Maze::~Maze() {
    delete grid;
    delete playerPos;
    delete endPos;
}

bool Maze::isWithinBounds(const Position& pos) const {
    return pos.x >= 0 && pos.x < grid->size() && pos.y >= 0 && pos.y < (*grid)[0].size();
}

bool Maze::isPath(const Position& pos) const {
    return isWithinBounds(pos) && ((*grid)[pos.x][pos.y] == ' ' || (*grid)[pos.x][pos.y] == 'E');
}

void Maze::display() const {
    // system("CLS");
    for (const auto& row : *grid) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << std::endl;
    }
    cout<<"- - - - - - - - - - - - - - - - - "<<endl;
}

Maze& Maze::updatePlayerPosition(const Position& newPos) {
    if (isPath(newPos)) {
        (*grid)[playerPos->x][playerPos->y] = ' ';
        *playerPos = newPos;
        (*grid)[playerPos->x][playerPos->y] = 'P';
    }
    return *this;
}

bool Maze::reachedEnd() const {
    return *playerPos == *endPos;
}

Position Maze::getPlayerPosition() const {
    return *playerPos;
}
