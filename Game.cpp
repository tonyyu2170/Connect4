#include "Game.h"

void Game::play() {
    bool running = true;
    char player = board.getTurn();

    printIntroDialogue();
    while (running) {
        board.printBoard();
        player = board.getTurn();
        
        std::cout << "Player " << player << ", enter a column (1-7): ";

        int col;
        while (true) {
            std::cin >> col;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input. Please enter an integer between 1 and 7: ";
            } 
            else if (col < 1 || col > 7) {
                std::cout << "Column must be between 1 and 7. Try again: ";
            }
            else {
                break;
            }
        }

        if (!board.move(col, player)) {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }
        

        // Check win
        if (board.hasWon(col, player)) {
            board.printBoard();
            printWinDialogue(player);
            running = false;
        }
        // Check draw
        else if (board.isDraw()) {
            board.printBoard();
            printTieDialogue();
            running = false;
        } 
    }
}

void Game::printIntroDialogue() {
    std::cout << "---------------------" << '\n';
    std::cout << "Welcome to Connect 4!" << '\n';
    std::cout << "The rules of Connect 4 are as follows:" << '\n';
    std::cout << "The game will end when there is a four-in-a-row or a stalemate" << '\n';
    std::cout << "Players will take turns placing pieces one at a time with an objective to connect 4 of their pieces in a row, whether diagonal, horizontal, or vertical" << '\n';
    std::cout << "Turns will commence as the following: Player 1 (red) will move first followed by Player 2 (yellow). After a player moves, their turn is over" << '\n';
    std::cout << "To place your piece, type in which column you want to place the piece in. The columns are numbered 1-7, from left to right" << '\n';
    std::cout << "Here is the board" << '\n';
}

void Game::printWinDialogue(char player) {
    std::cout << "---------------------" << '\n';
    std::cout << player << " has won the game! Congratulations :)" << '\n';
    std::cout << "---------------------" << '\n';
}

void Game::printTieDialogue() {
    std::cout << "---------------------" << '\n';
    std::cout << "Its a tie! Congratulations to you both" << '\n';
    std::cout << "---------------------" << '\n';
}