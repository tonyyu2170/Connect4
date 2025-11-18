#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"
#include <vector>

class Solver {
    public:
        int negamax(Board &board, int alpha, int beta);
};

#endif