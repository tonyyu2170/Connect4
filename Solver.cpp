#include "Solver.h"

int Solver::negamax(Board &board, int alpha, int beta) {
    if (board.isDraw())
        return 0;

    for (int i = 1; i < 8; i++) {
        if (board.isWinningMove(i, board.getTurn())) {
            return (43 - board.getNumMoves())/2;
        }
    }

    int bestScore = (41-board.getNumMoves())/2;
    if (beta > bestScore) {
        beta = bestScore;
        if (alpha >= beta) {
            return beta;
        }
    }

    std::vector<int> moves = sortMoves(board);

    for (auto &col : moves) {
        Board next(board);
        next.move(col, board.getTurn());
        int score = -negamax(next, -beta, -alpha);

        if (score >= beta) {
            return score;
        }

        if (score > alpha) {
            alpha = score;
        }
    }

    return alpha;
}

std::vector<int> Solver::sortMoves(Board& board) {
    int cols[7] = {1,2,3,4,5,6,7};
    int scores[7];

    for (int i = 0; i < 7; i++) {
        scores[i] = scoreMove(board, cols[i]);
    }

    for (int i = 0; i < 6; i++) {
        int maxIdx = i;
        for (int j = i+1; j < 7; j++) {
            if (scores[j] > scores[maxIdx]) {
                maxIdx = j;
            }
        }
        std::swap(scores[i], scores[maxIdx]);
        std::swap(cols[i], cols[maxIdx]);
    }

    std::vector<int> moves;
    for (int i = 0; i < 7; i++) {
        if (scores[i] == -1000) {
            break;
        }
        moves.push_back(cols[i]);
    }

    return moves;
}


/*
Creates weights for moves based on the following system:
Illegal moves: -1000
Winning moves: +1000
Blocking winning moves: +900
After that moves closer to the center are prioritized
*/
int Solver::scoreMove(Board &board, int col) {
    if (!board.canMove(col)) {
        return -1000;
    }

    if (board.isWinningMove(col, board.getTurn())) {
        return 1000;
    }

    char opponent = (board.getTurn() == 'r') ? 'y' : 'r';
    if (board.isWinningMove(col, opponent)) {
        return 900;
    }

    return 100 - abs(4 - col);
}