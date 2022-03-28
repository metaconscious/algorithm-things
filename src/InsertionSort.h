//
// Created by user on 3/27/22.
//

#ifndef ALGORITHM_THINGS_INSERTIONSORT_H
#define ALGORITHM_THINGS_INSERTIONSORT_H
#include "Type.h"
#include <concepts>
#include <utility>

namespace algo::inp
    {
        template <std::totally_ordered T>
        void insertionSort(Array<T>& array)
        {
            using size_type = typename Array<T>::size_type;
            for (size_type i{ 1 }; i < array.size(); ++i)
            {
                auto j{ i };
                while (j > 0)
                {
                    if (array.at(j) < array.at(j - 1))
                    {
                        std::swap(array[j], array[j - 1]);
                        --j;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

#endif //ALGORITHM_THINGS_INSERTIONSORT_H
