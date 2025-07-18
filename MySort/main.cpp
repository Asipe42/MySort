#include <iostream>
#include <vector>

#include "AlgorithmSelector.h"
#include "NumberCollector.h"
#include "Sorter.h"

int main()
{
    AlgorithmSelector algorithmSelector;
    NumberCollector numberCollector;

    while (true)
    {
        AlgorithmSelector::EAlgorithmType algorithmType = algorithmSelector.Select();

        if (static_cast<int>(algorithmType) == 0)
        {
            std::cout << "Exiting program.\n";
            break;
        }

        std::vector<int> numbers = numberCollector.CollectNumbers();

        switch (algorithmType)
        {
        case AlgorithmSelector::EAlgorithmType::Selection:
            Sorter::SelectionSort(numbers, numbers.size());
            break;
        case AlgorithmSelector::EAlgorithmType::Bubble:
            Sorter::BubbleSort(numbers, numbers.size());
            break;
        case AlgorithmSelector::EAlgorithmType::Insertion:
            Sorter::InsertionSort(numbers, numbers.size());
            break;
        case AlgorithmSelector::EAlgorithmType::Quick:
            Sorter::QuickSort(numbers, numbers.size());
            break;
        default:
            std::cout << "Invalid algorithm selection.\n";
            continue;
        }
    }

    return 0;
}
