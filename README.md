# Hex Game - C++ Implementation

## Overview

This repository contains a C++ implementation of the Hex board game. Hex is a two-player strategy game played on a hexagonal grid. The objective is for a player to connect their respective sides of the board with a continuous chain of their pieces.

This implementation includes features such as:

- Interactive gameplay for two players.
- A customizable board size.
- Robust input validation and error handling.
- Efficient algorithms for determining win conditions.

## Features

- **Dynamic Board Size**: The board size can be configured at initialization.
- **Exception Handling**: Ensures stability and graceful recovery from runtime errors.
- **Readable and Modular Code**: Clean design with clear separation of responsibilities across files.

## Requirements

To build and run the project, you need:

- A C++ compiler supporting C++11 or later.
- CMake (optional for simplified build management).

## How to Compile and Run

### Using a Compiler (e.g., g++):

1. Clone this repository:
    ```bash
    git clone https://github.com/eranHe13/Hax-game.git
    
    ```

2. Compile the code:
    ```bash
    g++ -std=c++11 main.cpp Game.cpp Square.cpp -o hex_game
    ```

3. Run the executable:
    ```bash
    ./hex_game
    ```

### Using CMake:

1. Create a build directory and navigate to it:
    ```bash
    mkdir build && cd build
    ```

2. Run CMake and build:
    ```bash
    cmake ..
    make
    ```

3. Execute the program:
    ```bash
    ./hex_game
    ```

## How to Play

- The game starts with **Player R**.
- Enter moves in the format `<Row><Column>` (e.g., `A1` for the top-left corner).
- The goal is to connect your respective sides:
  - **Player R** connects the top and bottom sides.
  - **Player B** connects the left and right sides.
- To quit the game, type `QUIT`.
- The game announces the winner once a player successfully forms a connected path.

## File Structure

- **`main.cpp`**: Entry point of the program.
- **`Game.h` / `Game.cpp`**: Contains the core game logic and board management.
- **`Square.h` / `Square.cpp`**: Handles individual board squares and their states.


## Contributing

Contributions are welcome! Please fork the repository, make your changes, and submit a pull request.

## Acknowledgements

Developed as a learning project for understanding C++ and game development concepts.
