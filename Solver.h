#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"
#include <vector>

class Solver {
    public:
        int negamax(Board &board, int alpha, int beta);
        std::vector<int> sortMoves(Board &board); 
        int scoreMove(Board &board, int col);
};

#endif