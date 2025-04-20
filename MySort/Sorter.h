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
         *  - 전수조사하여 가장 우선순위가 높은 값을 찾고, 그 값을 정렬되지 않은 부분의 맨 앞에 위치시키는 방식
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

    template <typename Container>
    static void bubble_sort(Container& arr, const size_t size)
    {
        /*
         * 버블 정렬
         *  - 인접한 두 값을 비교(버블링)하여 정렬하는 방식
         *  - 시간 복잡도 O(n^2)
         *  - 공간 복잡도 O(1)
         *  - 안정 정렬
         */

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    template <typename Container>
    static void insertion_sort(Container& arr, const size_t size)
    {
        /*
         * 삽입 정렬
         *  - 기준 값을 정렬되지 않은 부분의 맨 앞부터 차례대로 삽입하되, 기준 값 앞쪽에 있는 값들 중 기준 값보다 우선순위가 큰 값은 뒤쪽으로 밀어내는 방식
         *  - 시간 복잡도 O(n^2)
         *  - 공간 복잡도 O(1)
         *  - 안정 정렬
         */

        for (int i = 1; i < size; i++)
        {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }
};
