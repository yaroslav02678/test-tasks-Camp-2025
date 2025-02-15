# Game of Life

This project implements Conway's Game of Life in C++. The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970.

## Description

The Game of Life is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves.

## Features

- Initialize the game with a random matrix.
- Initialize the game with a matrix from a file.
- Update the matrix based on the rules of the Game of Life.
- Display the matrix.
- Run the game for a specified number of generations.

## Rules

1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

## Usage

### Initialization

You can initialize the game in two ways:
1. With a random matrix:
    ```cpp
    GameOfLife game;
    ```
2. With a matrix from a file:
    ```cpp
    GameOfLife game("filename.txt");
    ```

### Running the Game

To run the game for a specified number of generations:
```cpp
game.run(generations);
```

### Displaying the Matrix

To display the current state of the matrix:
```cpp
game.display();
```

## Build 

To build game in your pc need:

```
git clone git@github.com:yaroslav02678/winter_2024-2025.git 
mkdir build 
cd build
cmake .
cmake --build .
```

