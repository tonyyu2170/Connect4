#include "Board.h"

Board::Board() {
    board.fill(' ');
    nextOpenSpace = {ROWS*COLUMNS-7, ROWS*COLUMNS-6, ROWS*COLUMNS-5, ROWS*COLUMNS-4, ROWS*COLUMNS-3, ROWS*COLUMNS-2, ROWS*COLUMNS-1};
    turn = PLAYER_1;
    numMoves = 0;
}

Board::Board(std::string pos) {
    board.fill(' ');
    nextOpenSpace = {ROWS*COLUMNS-7, ROWS*COLUMNS-6, ROWS*COLUMNS-5, ROWS*COLUMNS-4, ROWS*COLUMNS-3, ROWS*COLUMNS-2, ROWS*COLUMNS-1};
    turn = PLAYER_1;
    numMoves = 0;
    for (int i = 0; i < pos.length(); i++) {
        Board::move(pos[i] - '1', turn);
    }
}

void Board::printBoard() {

    std::cout << "---------------------" << '\n';

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            char currentElement = board.at(i*COLUMNS + j);
            std::cout << "[" << currentElement << "]";
        }
        std::cout << '\n';
    }

    std::cout << "---------------------" << '\n';
}

bool Board::move(int col, char player) {
    if (!canMove(col)) {
        return false;
    }

    board.at(nextOpenSpace.at(col)) = player;
    nextOpenSpace.at(col) -= 7;

    turn == 'r' ? turn = 'y' : turn = 'r';
    numMoves++;

    return true;
}

bool Board::canMove(int col) {
    return nextOpenSpace.at(col) >= 0;
}

bool Board::isWinningMove(int col, char player) {
    bool isWinning = false;

    int savedNext = nextOpenSpace.at(col);
    char savedTurn = turn;
    int savedNumMoves = numMoves;

    if (move(col, player)) {
        isWinning = hasWon(col, player);

        // Undo move exactly
        nextOpenSpace.at(col) = savedNext;
        board.at(savedNext) = ' ';
        turn = savedTurn;
        numMoves = savedNumMoves;
    }

    return isWinning;
}


// Only checking spaces affected by the last move
bool Board::hasWon(int col, char player) {
    int index = nextOpenSpace.at(col) + COLUMNS;

    // Vertical
    if (index < 21 && player == board.at(index + COLUMNS) && player == board.at(index + COLUMNS * 2) && player == board.at(index + COLUMNS * 3)) {
        return true;
    }

    // Horizontal
    int row = index / COLUMNS; 
    int count = 0;
    for (int currentColIndex = 0; currentColIndex < COLUMNS; currentColIndex++) {
        if (board.at(row * COLUMNS + currentColIndex) == player) {
            count++;
            if (count == 4) return true;
        } else{
            count = 0;
        }
    }
    
    // Diagonal '/'
    count = 0;
    int r = row, c = index % COLUMNS;
    while (r < ROWS-1 && c > 0) {
        r++;
        c--;
    }
    while (r >= 0 && c < COLUMNS) {
        if (board.at(r*COLUMNS + c) == player) {
            count++;
            if (count == 4) return true;
        } else {
            count = 0;
        }
        r--;
        c++;
    }

    // Diagonal '\'
    count = 0;
    r = row; c = index % COLUMNS;
    while (r > 0 && c > 0) {
        r--;
        c--;
    }
    while (r < ROWS && c < COLUMNS) {
        if (board.at(r*COLUMNS + c) == player) {
            count++;
            if (count == 4) return true;
        } else {
            count = 0;
        }
        r++;
        c++;
    }
    
    return false;

}

bool Board::isDraw() {
    for (int i = 0; i < COLUMNS; i++ ){
        if (nextOpenSpace.at(i) >= 0) {
            return false;
        }
    }
    return true;
}

char Board::getTurn() {
    return turn;
}

int Board::getNumMoves() {
    return numMoves;
}