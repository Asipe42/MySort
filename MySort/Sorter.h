#pragma once
#include <set>

class sorter
{
public:
    template <typename Container>
    static void selection_sort(Container& arr, const size_t size)
    {
        /*
         * 선택 정렬
         *  - 가장 작은 값을 찾아서 맨 앞에 있는 값과 교환하는 방식으로 정렬
         *  - 시간 복잡도 O(n^2)
         *  - 공간 복잡도 O(1)
         *  - 안정 정렬
         */

        if (size == 0 || size == 1)
        {
            return;
        }
    
        for (size_t i = 0; i < size; i++)
        {
            size_t min_idx = i;
        
            for (size_t j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[min_idx])
                {
                    min_idx = j;
                }
            }

            if (i == min_idx)
            {
                continue;
            }

            std::swap(arr[i], arr[min_idx]);
        }
    }
};
