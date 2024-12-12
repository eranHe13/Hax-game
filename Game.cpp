
#include "Game.h"
#include <iomanip> // For improved board display
#include <sstream> // For input parsing

Game::Game(int sizeIn): size(sizeIn), counter(0) {
    // Constructor initializing the board
    board = new Square*[size];
    for (int i = 0; i < size; ++i) {
        board[i] = new Square[size];
    }
}

Game::~Game() {
    // Destructor to clean up dynamic memory
    for (int i = 0; i < size; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

bool Game::isValidInput(const std::string& input) {
    // Validate input format (e.g., A1, B10)
    if (input.size() < 2 || input.size() > 3) {
        std::cerr << "Invalid input format. Use format <Letter><Number>, e.g., A1." << std::endl;
        return false;
    }

    char rowChar = input[0];
    if (rowChar < 'A' || rowChar > 'A' + size - 1) {
        std::cerr << "Row must be between A and " << static_cast<char>('A' + size - 1) << "." << std::endl;
        return false;
    }

    int col;
    try {
        col = std::stoi(input.substr(1));
    } catch (...) {
        std::cerr << "Column must be a number." << std::endl;
        return false;
    }

    if (col < 1 || col > size) {
        std::cerr << "Column must be between 1 and " << size << "." << std::endl;
        return false;
    }

    return true;
}

void Game::setSquare(int row, int col) {
    // Set square value for the current player
    char player = playerTurn();
    board[row][col].setValue(&player);
}

bool Game::checkWin(int row, int col) {
    // Recursive function to check if a player has won
    if ((playerTurn() == R && row == size - 1) || (playerTurn() == B && col == size - 1)) {
        return true;
    }

    if (board[row][col].getIsVisited()) return false;
    board[row][col].setIsVisited();

    char player = playerTurn();
    if (board[row][col].getValue() != player) return false;

    // Check neighboring cells
    if (row > 0 && checkWin(row - 1, col)) return true;
    if (row < size - 1 && checkWin(row + 1, col)) return true;
    if (col > 0 && checkWin(row, col - 1)) return true;
    if (col < size - 1 && checkWin(row, col + 1)) return true;

    if (row > 0 && col < size - 1 && checkWin(row - 1, col + 1)) return true;
    if (row < size - 1 && col > 0 && checkWin(row + 1, col - 1)) return true;

    return false;
}

void Game::playGame() {
    // Main game loop
    std::string input;
    std::cout << "Welcome to Hex! Enter your move as <Row><Column> (e.g., A1). Type QUIT to exit.\n";
    printBoard();

    while (true) {
        std::cout << "Player " << playerTurn() << ", enter your move: ";
        std::cin >> input;

        if (input == "QUIT") {
            std::cout << "Player " << playerTurn() << " quits. Game over." << std::endl;
            return;
        }

        if (!isValidInput(input)) continue;

        int row = input[0] - 'A';
        int col = std::stoi(input.substr(1)) - 1;

        if (!board[row][col].isSquareEmpty()) {
            std::cerr << "Square is already occupied. Try again." << std::endl;
            continue;
        }

        setSquare(row, col);
        printBoard();

        if (checkWin(row, col)) {
            std::cout << "Player " << playerTurn() << " wins!" << std::endl;
            return;
        }

        counter++;
    }
}

char Game::playerTurn() const {
    return (counter % 2 == 0) ? R : B;
}

void Game::printBoard() const {
    std::cout << "\n";
    for (int i = 0; i < size; ++i) {
        std::cout << std::string(i, ' '); // Indent rows
        for (int j = 0; j < size; ++j) {
            std::cout << board[i][j];
            if (j < size - 1) std::cout << " - ";
        }
        std::cout << "\n";
        if (i < size - 1) {
            std::cout << std::string(i + 1, ' ');
            for (int j = 0; j < size; ++j) {
                std::cout << "\\ /";
                if (j < size - 1) std::cout << " ";
            }
            std::cout << "\n";
        }
    }
}
