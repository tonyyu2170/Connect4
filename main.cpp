#include "Board.h"
#include "Solver.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
 
    // test push

    Solver s1;
    int passed = 0;

    std::ifstream inputFile("test1.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << '\n';
        return 1;
    }

    std::string line;
    int testNum = 1;
    while (std::getline(inputFile, line)) {
        if (line.empty()) continue;

        std::istringstream ss(line);
        std::string position;
        int expected;

        if (!(ss >> position >> expected)) {
            std::cerr << "Error parsing line: " << line << '\n';
            continue;
        }

        Board b1(position);
        int result = s1.negamax(b1);

        if (result == expected) {
            std::cout << "Test " << testNum << ": PASS\n";
            passed++;
        } else {
            std::cout << "Test " << testNum << ": FAIL (expected " 
                      << expected << ", got " << result << ")\n";
        }

        testNum++;
    }

    std::cout << "Pass rate: " << (double) passed/testNum * 100 << "%\n";

    inputFile.close();
    return 0;
}