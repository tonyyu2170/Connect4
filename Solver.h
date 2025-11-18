#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"
#include "TranspositionTable.h"
#include <vector>

class Solver {
    private:
        unsigned long long nodeCount;
        TranspositionTable TT;

    public:
        Solver();
        int negamax(Board &board, int alpha, int beta);
        unsigned long long getNodeCount();
};

#endif