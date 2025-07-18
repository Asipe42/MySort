#include "AlgorithmSelector.h"
#include <iostream>

AlgorithmSelector::EAlgorithmType AlgorithmSelector::Select()
{
    int choice = -1;
    while (true)
    {
        PrintMenu();

        if (!(std::cin >> choice) || choice < 0 || choice > 4)  // 0 허용
        {
            std::cout << "\n>> Invalid choice. Please enter a number between 0 and 4.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
        {
            std::cin.ignore(10000, '\n');
            return static_cast<EAlgorithmType>(choice);
        }
    }
}

void AlgorithmSelector::PrintMenu() const
{
    std::cout << "╔══════════════════════════════╗\n";
    std::cout << "║      Sorting Algorithms      ║\n";
    std::cout << "╠══════════════════════════════╣\n";
    std::cout << "║  0. Exit                     ║\n";
    std::cout << "║  1. Selection Sort           ║\n";
    std::cout << "║  2. Bubble Sort              ║\n";
    std::cout << "║  3. Insertion Sort           ║\n";
    std::cout << "║  4. Quick Sort               ║\n";
    std::cout << "╚══════════════════════════════╝\n";
    std::cout << "Enter your choice (0 - 4): ";
}