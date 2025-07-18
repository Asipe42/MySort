#include "NumberCollector.h"
#include <iostream>
#include <sstream>
#include <string>

std::vector<int> NumberCollector::CollectNumbers()
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
