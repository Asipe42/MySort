#pragma once
#include <algorithm>

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

        if (size == 0 || size == 1)
        {
            return;
        }

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

        if (size == 0 || size == 1)
        {
            return;
        }

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

    template <typename Container>
    static void quick_sort(Container& arr, const size_t size)
    {
        /*
         * 퀵 정렬
         *  - 피벗을 선택해서, 피벗보다 작은 값은 왼쪽, 큰 값은 오른쪽으로 이동시키는 방식
         *  - 이러한 과정을 분할이 불가능할 때까지 반복한다.
         *  - 시간 복잡도 O(n log n)
         *  - 공간 복잡도 O(log n)
         *  - 불안정 정렬
         */

        if (size == 0 || size == 1)
        {
            return;
        }

        quick_sort_internal(arr, 0, size);
    }

private:
    template <typename Container>
    static void quick_sort_internal(Container& arr, int low, int high)
    {
        /*
         * 피벗 결정 방식
         *  1. 첫 번째 값
         *  2. 마지막 값
         *  3. 중간값
         *
         *  1, 2번의 경우 이미 정렬된 배열 또는 역순으로 정렬된 배열에서 O(n^2)의 시간 복잡도를 가지게 된다.
         *  따라서 3번의 중간 값을 피벗으로 선택하는 방식으로 구현한다.
         */

        if (low >= high)
        {
            return;
        }
        
        const int a = arr[low];
        const int b = arr[high - 1];
        const int c = arr[high / 2];
        
        /*
         * 증명
         *  - a, b, c 중 하나는 반드시 중간값이다.
         *  - min(a, b): 중간값이거나 최솟값이다.   
         *  - max(a, b): 중간값이거나 최댓값이다.
         *  - min(max(a, b), c): 중간값이거나 최솟값이다.
         *  - max(min(a, b), min(max(a, b), c)): 중간값이거나 최솟값인 것 중에 큰 값은 당연히 중간값이다.      
         */
        int pivot = std::max(std::min(a, b), std::min(std::max(a, b), c));
        int pivot_index;

        if (pivot == a)
        {
            pivot_index = low;
        }
        else if (pivot == b)
        {
            pivot_index = high - 1;
        }
        else
        {
            pivot_index = high / 2;
        }

        std::swap(arr[pivot_index], arr[high - 1]);
        
        int store_index = low - 1;
        for (int i = low; i < high - 1; i++)
        {
            if (arr[i] < pivot)
            {
                store_index++;
                std::swap(arr[i], arr[store_index]);
            }
        }

        store_index++;
        std::swap(arr[high - 1], arr[store_index]);
        
        quick_sort_internal(arr, low, store_index);
        quick_sort_internal(arr, store_index + 1, high);
    }
};
