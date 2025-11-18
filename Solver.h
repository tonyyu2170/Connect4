#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"
#include "TranspositionTable.h"

class Solver {
    private:
        TranspositionTable TT;
        unsigned long long nodeCount;

    public:
        Solver();
        int negamax(Board &board, int alpha, int beta);
        int solve(Board &board);         // ← NEW: full solver (iterative deep + null window)
        unsigned long long getNodeCount();
};

#endif