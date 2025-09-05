#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <iostream>

class Board {
    private:
        static constexpr int ROWS = 6;
        static constexpr int COLUMNS = 7;

        static constexpr char PLAYER_1 = 'r';
        static constexpr char PLAYER_2 = 'y';
        static constexpr char EMPTY = ' ';

        std::array<char, ROWS * COLUMNS> board{};
        std::array<int, COLUMNS> nextOpenSpace{};
        char turn;
        int numMoves;

    public:
        Board();
        Board(std::string pos);
        void printBoard();
        bool move(int col, char player);
        bool canMove(int col);
        bool isWinningMove(int col, char player);
        bool hasWon(int col, char player);
        bool isDraw();
        char getTurn();
        int getNumMoves();
};

#endif