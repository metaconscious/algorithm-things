//
// Created by user on 3/27/22.
//

#ifndef ALGORITHM_THINGS_BUBBLESORT_H
#define ALGORITHM_THINGS_BUBBLESORT_H
#include "Type.h"
#include <concepts>
#include <utility>

namespace algo
{
    template <std::totally_ordered T>
    Array<T> bubbleSort(const Array<T>& array)
    {
        auto result{ array };

        for (auto i{ result.size() - 1 }; i > 0; --i)
        {
            for (decltype(i) j{ 0 }; j < i; ++j)
            {
                if (result.at(j) > result.at(j + 1))
                {
                    std::swap(result[j], result[j + 1]);
                }
            }
        }

        return result;
    }

    namespace inp
    {
        template <std::totally_ordered T>
        void bubbleSort(Array<T>& array)
        {
            for (auto i{ array.size() - 1 }; i > 0; --i)
            {
                for (decltype(i) j{ 0 }; j < i; ++j)
                {
                    if (array.at(j) > array.at(j + 1))
                    {
                        std::swap(array[j], array[j + 1]);
                    }
                }
            }
        }
    }
}

#endif //ALGORITHM_THINGS_BUBBLESORT_H
