cmake_minimum_required(VERSION 3.10)
project(Connect4)

set(CMAKE_CXX_STANDARD 17)


add_executable(connect4
    main.cpp
    Solver.cpp
    Board.cpp
    Game.cpp
)