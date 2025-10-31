#ifndef GAME_H
#define GAME_H

#include "Maze.h"
#include <ctime>

class Game {
private:
    Maze* maze;
    int validMoves, invalidMoves, bestMoves, maxMoves, currentLevel;
    static int totalGames;
    clock_t startTime;
    void (Game::*moveFunction)(char);

public:
    Game();
    ~Game();

    void setMaxMoves();
    void loadBestMoves();
    void saveBestMoves();
    Game& play();
    Game& resetGame();
    Game& printLevelInfo();
    void move(char direction);
    void printStats();
    static void incrementGames() { totalGames++; }
    static int getTotalGames() { return totalGames; }
};

#endif
