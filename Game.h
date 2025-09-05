#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <iostream>

class Game {
private:
    Board board;

public:
    void play();
    void printIntroDialogue();
    void printWinDialogue(char player);
    void printTieDialogue();
};

#endif
