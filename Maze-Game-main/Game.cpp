#include "Game.h"
#include <iostream>
#include <fstream>
#include <climits>
#include <ctime>
#include <vector>

#ifdef _WIN32
    #include <conio.h> // Windows-specific for _getch()
#else
    #include <termios.h>
    #include <unistd.h>
    // Define getch() for Linux
    int getch() {
        termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);           // get current terminal attributes
        newt = oldt;                               // copy to new struct
        newt.c_lflag &= ~(ICANON | ECHO);          // disable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);   // set attributes immediately
        int ch = getchar();                        // read character
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);   // reset to old settings
        return ch;
    }
#endif

using namespace std;

int Game::totalGames = 0;

Game::Game() : currentLevel(1), validMoves(0), invalidMoves(0) {
    cout << "\n";
    cout << "Welcome to the Maze Runner!\n" << endl;
    cout << "______________________________\n" << endl;
    maze = new Maze(Position(1, 1), Position(8, 8), currentLevel);
    loadBestMoves();
    setMaxMoves();
    incrementGames();
    startTime = clock();
}

Game::~Game() {
    delete maze;
}

void Game::setMaxMoves() {
    maxMoves = 30;
}

void Game::loadBestMoves() {
    std::ifstream infile("best_moves_level_" + std::to_string(currentLevel) + ".txt");

    bestMoves = INT_MAX;

    if (infile.is_open()) {
        if (infile >> bestMoves) {
            std::cout << "Best moves loaded: " << bestMoves << " for Level " << currentLevel << "\n";
        } else {
            std::cerr << "Warning: Failed to read best moves for Level " << currentLevel << ". Setting to default.\n";
            bestMoves = INT_MAX;
        }
        infile.close();
    }
}

void Game::saveBestMoves() {
    std::ofstream outfile("best_moves_level_" + std::to_string(currentLevel) + ".txt");

    if (outfile.is_open()) {
        outfile << bestMoves;
        outfile.close();
        std::cout << "Best moves saved: " << bestMoves << " for Level " << currentLevel << "\n";
    }
}

Game& Game::play() {
    resetGame().printLevelInfo();
    maze->display();

    while (!maze->reachedEnd() && validMoves + invalidMoves < maxMoves) {
        char input;
        
#ifdef _WIN32
        input = _getch();  // Windows-specific
#else
        input = getch();   // Linux version
#endif

        moveFunction = &Game::move;
        (this->*moveFunction)(input);
        maze->display();
    }

    if (maze->reachedEnd()) {
        if (validMoves < bestMoves) {
            bestMoves = validMoves;
            saveBestMoves();
        }
        cout << "Congratulations! You reached the end of level " << currentLevel << "\n";

        if (currentLevel == 1) {
            printStats();
            currentLevel = 2;
            play();
        } else {
            printStats();
        }
    } else {
        cout << "You're lost in a maze. Your goal is to reach the exit (marked as 'E')." << endl;
        cout << "Game Over! Max moves reached. Try again.\n";
        play();
    }
    return *this;
}

void Game::move(char direction) {
    Position newPos = maze->getPlayerPosition();
    switch (direction) {
        case 'w': newPos = newPos + Position(-1, 0); break;
        case 's': newPos = newPos + Position(1, 0); break;
        case 'a': newPos = newPos + Position(0, -1); break;
        case 'd': newPos = newPos + Position(0, 1); break;
    }

    if (maze->isPath(newPos)) {
        maze->updatePlayerPosition(newPos);
        validMoves++;
    } else {
        invalidMoves++;
    }
}

Game& Game::resetGame() {
    delete maze;
    maze = new Maze(Position(1, 1), Position(8, 8), currentLevel);
    validMoves = invalidMoves = 0;
    startTime = clock();
    return *this;
}

Game& Game::printLevelInfo() {
    cout << "Level: " << currentLevel << ", Best Moves: " << bestMoves << ", Max Moves: " << maxMoves << endl;
    return *this;
}

void Game::printStats() {
    clock_t endTime = clock();
    double timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "\n--- Game Stats ---\n";
    cout << "Level: " << currentLevel << "\n";
    cout << "Best Moves: " << bestMoves << "\n";
    cout << "Total Moves: " << validMoves + invalidMoves << "\n";
    cout << "Valid Moves: " << validMoves << ", Invalid Moves: " << invalidMoves << "\n";
    cout << "Time Taken: " << timeTaken << " seconds\n";
}
