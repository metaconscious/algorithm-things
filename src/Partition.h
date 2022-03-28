#ifndef ALGORITHM_THINGS_PARTITION_H
#define ALGORITHM_THINGS_PARTITION_H

#include "Type.h"

namespace algo
{
    template <typename T>
    ArrayPair<T> partition(const Array<T>& vector)
    {
        auto midIt{ vector.begin() + (vector.size() / 2) };
        return { Array<T>{ vector.begin(), midIt }, Array<T>{ midIt, vector.end() }};
    }
}

#endif // ALGORITHM_THINGS_PARTITION_H
