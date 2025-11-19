
# Connect4

Connect 4 is a command-line implementation of the classic Connect Four game, featuring a strong solver based on the negamax algorithm and a transposition table for efficient position evaluation.

## Features
- Play Connect Four in the terminal
- Strong AI solver using negamax with alpha-beta pruning
- Efficient board representation with bitboards
- Transposition table for fast repeated position lookup
- Test suite for solver validation

## Build Instructions
This project uses CMake for building. Make sure you have CMake and a C++17 compiler installed.

```sh
cd build
cmake ..
make
```

## Usage
Run the game from the `build` directory:

```sh
./connect4
```

You will be prompted to enter moves (columns 1-7). The game alternates between two players.

## Solver & Testing
The solver can be tested using provided test suites in the `Testing_Suite/` folder. The main program reads test positions and expected results from these files to validate the solver's accuracy.

## File Overview
- `main.cpp`: Entry point, runs tests and/or game loop
- `Board.*`: Board representation and move logic
- `Game.*`: Handles user interaction and game flow
- `Solver.*`: Negamax solver and search logic
- `TranspositionTable.*`: Caching for board positions
- `Testing_Suite/`: Contains test positions for solver validation