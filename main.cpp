#include "Game.h"
#include <exception>

int main() {
    try {
        int boardSize = 11; // Default board size, can be parameterized
        std::cout << "Starting Hex game with board size: " << boardSize << std::endl;

        Game game(boardSize);
        game.playGame();

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}