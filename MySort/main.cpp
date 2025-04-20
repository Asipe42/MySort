#include <iostream>
#include <vector>
#include "Sorter.h"

int main()
{
    std::vector<int> arr = { 5, 2, 9, 1, 5, 6 };
    sorter::bubble_sort(arr, arr.size());

    for (auto each : arr)
    {
        std::cout << each << " ";
    }
    
    return 0;
}
