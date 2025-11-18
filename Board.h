#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include <string>
#include <iostream>
#include <bitset>
#include <cassert>
#include <iomanip>

class Board {
    private:
        static constexpr int HEIGHT = 6;
        static constexpr int WIDTH = 7;
        // each column uses HEIGHT+1 bits
        using U64 = uint64_t;

        U64 current;    // bitboard for stones of the player to move (1 = current player's stones)
        U64 mask;       // bitboard for all occupied cells (1 = occupied)
        int numMoves;

        // Helper masks and operations
        static constexpr int COL_BITS = HEIGHT + 1;
        static U64 bottom_mask(int col);
        static U64 top_mask(int col);
        static U64 column_mask(int col);
        static bool alignment(U64 pos);

    public:
        Board();
        Board(std::string pos);
        void printBoard();
        bool canMove(int col) const;
        void play(int col);
        bool isWinningMove(int col) const;
        bool isWinningMoveForOpponent(int col) const;
        bool isDraw() const;
        char getTurn() const;
        int getNumMoves() const;

        uint64_t getCurrent() const;
        uint64_t getMask() const;
        void setState(uint64_t newCurrent, uint64_t newMask, int newNumMoves);
        uint64_t key() const;
};

#endif