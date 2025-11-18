#include "Solver.h"

int Solver::negamax(Board &board, int alpha, int beta) {
    if (board.isDraw())
        return 0;

    for (int c = 0; c < 7; ++c) {
        if (board.canMove(c) && board.isWinningMove(c)) {
            return (43 - board.getNumMoves()) / 2;
        }
    }

    int bestScore = (41 - board.getNumMoves()) / 2;
    if (beta > bestScore) {
        beta = bestScore;
        if (alpha >= beta) {
            return beta;
        }
    }

    static const int order[7] = {3, 2, 4, 1, 5, 0, 6};

    for (int i = 0; i < 7; ++i) {
        int col = order[i];
        if (!board.canMove(col)) continue;

        uint64_t savedCurrent = board.getCurrent();
        uint64_t savedMask = board.getMask();
        int savedNumMoves = board.getNumMoves();

        board.play(col);
        int score = -negamax(board, -beta, -alpha);
        board.setState(savedCurrent, savedMask, savedNumMoves);

        if (score >= beta) {
            return score;
        }
        if (score > alpha) {
            alpha = score;
        }
    }

    return alpha;
}