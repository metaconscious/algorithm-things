//
// Created by user on 3/27/22.
//

#ifndef ALGORITHM_THINGS_DIVIDEANDCONQUER_H
#define ALGORITHM_THINGS_DIVIDEANDCONQUER_H

#include "Type.h"
#include <functional>

namespace algo
{
    template <typename T>
    Array<T> divideAndConquer(const Array<T>& vector,
        std::function<ArrayPair<T>(const Array<T>&)> divide,
        std::function<Array<T>(const ArrayPair<T>&)> conquer)
    {
        const auto size{ vector.size() };
        if (size > 1)
        {
            auto&& [first, last] { divide(vector) };
            return conquer({
                divideAndConquer(first, divide, conquer),
                divideAndConquer(last, divide, conquer)
                });
        }
        else
        {
            return vector;
        }
    }
}


#endif // ALGORITHM_THINGS_DIVIDEANDCONQUER_H
