#include <iostream>
#include <sstream>
#include <string>

#include "AlgorithmSelector.h"
#include "NumberCollector.h"
#include "Sorter.h"

enum class EAlgorithmType
{
    Exit = 0,
    Selection = 1,
    Bubble = 2,
    Insertion = 3,
    Quick = 4
};

void PrintMenu()
{
    std::cout << "╔══════════════════════════════╗\n";
    std::cout << "║       Sorting Algorithms     ║\n";
    std::cout << "╠══════════════════════════════╣\n";
    std::cout << "║ 0. Exit                      ║\n";
    std::cout << "║ 1. Selection Sort            ║\n";
    std::cout << "║ 2. Bubble Sort               ║\n";
    std::cout << "║ 3. Insertion Sort            ║\n";
    std::cout << "║ 4. Quick Sort                ║\n";
    std::cout << "╚══════════════════════════════╝\n";
    std::cout << "Enter your choice (0 - 4): ";
}

EAlgorithmType SelectAlgorithm()
{
    int choice = -1;
    while (true)
    {
        PrintMenu();

        if (!(std::cin >> choice) || choice < 0 || choice > 4)
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

std::vector<int> CollectNumbers()
{
    std::vector<int> numbers;
    std::string line;

    std::cout << "Enter numbers separated by spaces (e.g. 1 2 4 5 8 3): ";
    std::getline(std::cin, line);

    std::istringstream iss(line);
    int num;
    while (iss >> num)
    {
        numbers.push_back(num);
    }

    return numbers;
}

int main()
{
    while (true)
    {
        EAlgorithmType algorithmType = SelectAlgorithm();

        if (algorithmType == EAlgorithmType::Exit)
        {
            std::cout << "Exiting program.\n";
            break;
        }

        std::vector<int> numbers = CollectNumbers();

        if (numbers.empty())
        {
            std::cout << "No numbers entered. Returning to menu.\n";
            continue;
        }

        size_t size = numbers.size();

        switch (algorithmType)
        {
        case EAlgorithmType::Selection:
            Sorter::SelectionSort(numbers, size);
            break;
        case EAlgorithmType::Bubble:
            Sorter::BubbleSort(numbers, size);
            break;
        case EAlgorithmType::Insertion:
            Sorter::InsertionSort(numbers, size);
            break;
        case EAlgorithmType::Quick:
            Sorter::QuickSort(numbers, size);
            break;
        default:
            std::cout << "Invalid algorithm selection.\n";
            continue;
        }
    }

    return 0;
}
