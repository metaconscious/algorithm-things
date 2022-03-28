//
// Created by user on 3/28/22.
//

#ifndef ALGORITHM_THINGS_SELECTIONSORT_H
#define ALGORITHM_THINGS_SELECTIONSORT_H

#include "Type.h"
#include <concepts>
#include <utility>

namespace algo::inp
{
    template <std::totally_ordered T>
    void selectionSort(Array<T>& array)
    {
        using size_type = typename Array<T>::size_type;
        for (size_type i{ 0 }; i < array.size() - 1; ++i)
        {
            auto smallestIndex{ i };
            for (auto j{ i }; j < array.size(); ++j)
            {
                if (array.at(smallestIndex) > array.at(j))
                {
                    smallestIndex = j;
                }
            }
            std::swap(array[smallestIndex], array[i]);
        }
    }
}

#endif //ALGORITHM_THINGS_SELECTIONSORT_H
