#include "Board.h"

Board::U64 Board::bottom_mask(int col) {
    return (UINT64_C(1) << (col * COL_BITS));
}

Board::U64 Board::top_mask(int col) {
    return (UINT64_C(1) << ((HEIGHT - 1) + col * COL_BITS));
}

Board::U64 Board::column_mask(int col) {
    return (((UINT64_C(1) << COL_BITS) - 1) << (col * COL_BITS));
}

bool Board::alignment(U64 pos) {
    // horizontal
    U64 m = pos & (pos >> COL_BITS);
    if (m & (m >> (2 * COL_BITS))) return true;

    // diagonal 1 (down-left / up-right)
    m = pos & (pos >> HEIGHT);
    if (m & (m >> (2 * HEIGHT))) return true;

    // diagonal 2 (down-right / up-left)
    m = pos & (pos >> (HEIGHT + 2));
    if (m & (m >> (2 * (HEIGHT + 2)))) return true;

    // vertical
    m = pos & (pos >> 1);
    if (m & (m >> 2)) return true;

    return false;
}

Board::Board() {
    current = 0;
    mask = 0;
    numMoves = 0;
}

Board::Board(std::string pos) {
    current = 0;
    mask = 0;
    numMoves = 0;
    for (char c : pos) {
        int col = c - '1';
        if (col >= 0 && col < WIDTH && canMove(col)) {
            play(col);
        }
    }
}

void Board::printBoard() {

    std::cout << "---------------------" << '\n';

    U64 red, yellow;
    if (getTurn() == 'r') {
        red = current;
        yellow = mask ^ current;
    } else {
        yellow = current;
        red = mask ^ current;
    }

    for (int row = HEIGHT - 1; row >= 0; --row) {
        std::cout << "|";
        for (int col = 0; col < WIDTH; ++col) {
            int bitIndex = col * COL_BITS + row;
            U64 bit = (UINT64_C(1) << bitIndex);
            if (red & bit) {
                std::cout << "R|";
            } else if (yellow & bit) {
                std::cout << "Y|";
            } else {
                std::cout << " |";
            }
        }
        std::cout << '\n';
    }

    std::cout << "---------------------" << '\n';
    std::cout << " 1 2 3 4 5 6 7" << '\n';
}

bool Board::canMove(int col) const {
    return ((mask & top_mask(col)) == 0);
}

void Board::play(int col) {
    assert(col >= 0 && col < WIDTH);
    U64 move = (mask + bottom_mask(col)) & column_mask(col);
    assert(move != 0);
    current = mask ^ current;
    mask |= move;
    numMoves++;
}

bool Board::isWinningMove(int col) const {
    if (!canMove(col)) return false;
    U64 move = (mask + bottom_mask(col)) & column_mask(col);
    U64 pos = current | move;
    return alignment(pos);
}

bool Board::isWinningMoveForOpponent(int col) const {
    if (!canMove(col)) return false;
    U64 move = (mask + bottom_mask(col)) & column_mask(col);
    U64 opponent = mask ^ current;
    U64 pos = opponent | move;
    return alignment(pos);
}

bool Board::isDraw() const {
    return numMoves >= HEIGHT * WIDTH;
}

char Board::getTurn() const {
    // Player 1 (red) moves first. If numMoves is even -> red to move.
    return (numMoves % 2 == 0) ? 'r' : 'y';
}

int Board::getNumMoves() const {
    return numMoves;
}

uint64_t Board::getCurrent() const {
    return static_cast<uint64_t>(current);
}

uint64_t Board::getMask() const {
    return static_cast<uint64_t>(mask);
}

void Board::setState(uint64_t newCurrent, uint64_t newMask, int newNumMoves) {
    current = static_cast<U64>(newCurrent);
    mask = static_cast<U64>(newMask);
    numMoves = newNumMoves;
}

uint64_t Board::key() const {
    return current + mask;
}