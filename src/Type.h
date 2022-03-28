#ifndef ALGORITHM_THINGS_TYPE_H
#define ALGORITHM_THINGS_TYPE_H

#include <tuple>
#include <vector>

namespace algo
{
    template <typename T>
    using Array = std::vector<T>;

    template <typename T>
    using ArrayPair = std::pair<Array<T>, Array<T>>;
}

#endif // ALGORITHM_THINGS_TYPE_H
