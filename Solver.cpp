#include "Solver.h"

int Solver::negamax(Board board) {
    if (board.isDraw())
        return 0;

    for (int i = 1; i < 8; i++) {
        if (board.isWinningMove(i, board.getTurn())) {
            return (43 - board.getNumMoves())/2;
        }
    }

    int bestScore = -42;

    for (int i = 1; i < 8; i++) {
        if (board.canMove(i)) {
            Board next(board);
            next.move(i, board.getTurn());
            int score = -negamax(next);
            if (score > bestScore) {
                bestScore = score;
            }
        }
    }

    return bestScore;
}