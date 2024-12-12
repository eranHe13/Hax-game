#ifndef HEX_GAME_H
#define HEX_GAME_H

#include "Square.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // For exception handling

class Game {
public:
    Game(int sizeIn); // Constructor to initialize game board
    ~Game(); // Destructor to clean up memory

    void playGame(); // Main game logic
    void setSquare(int row, int col); // Set square value for current player
    bool isValidInput(const std::string& input); // Validate user input
    bool checkWin(int row, int col); // Check if current player has won
    void printBoard() const; // Print the game board
    char playerTurn() const; // Determine current player

private:
    Square** board; // 2D array representing the board
    int size; // Size of the board
    int counter; // Tracks the number of turns

    enum Player { EMPTY = 'O', R = 'R', B = 'B' }; // Player symbols

    void handleException(const std::exception& e) const; // Handle exceptions
};

#endif // HEX_GAME_H