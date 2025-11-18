#include "Board.h"
#include "Solver.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

int main() {
    Solver s1;
    int passed = 0;

    std::ifstream inputFile("../Testing_Suite/End_Easy.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << '\n';
        return 1;
    }

    std::string line;
    int testNum = 1;

    auto start = std::chrono::high_resolution_clock::now();

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
        int result = s1.negamax(b1, -10000, 10000);
        
        if (result == expected) {
            std::cout << "Test " << testNum << ": PASS" << '\n';
            passed++;
        } else {
            std::cout << "Test " << testNum << ": FAIL (expected " 
                      << expected << ", got " << result << ")" << '\n';
        }
        
        testNum++;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    int totalTests = testNum - 1;
    std::cout << "Pass rate: " 
              << (double) passed / totalTests * 100 << "%" << '\n';
    std::cout << "Total time: " << elapsed.count() << " seconds" << '\n';
    std::cout << "Average time per test: " 
              << (elapsed.count() / totalTests) << " seconds" << '\n';

    inputFile.close();
    return 0;
}