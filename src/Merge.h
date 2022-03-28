#ifndef ALGORITHM_THINGS_MERGE_H
#define ALGORITHM_THINGS_MERGE_H

#include "Type.h"
#include <concepts>

namespace algo
{
    template <std::totally_ordered T>
    Array<T> merge(const ArrayPair<T>& pair)
    {
        const auto& [first, last] { pair };
        const auto firstSize{ first.size() };
        const auto lastSize{ last.size() };
        using size_type = typename Array<T>::size_type;
        size_type i{ 0 };
        size_type j{ 0 };
        Array<T> result{};
        while (i < firstSize && j < lastSize)
        {
            if (first.at(i) <= last.at(j))
            {
                result.push_back(first.at(i++));
            }
            else
            {
                result.push_back(last.at(j++));
            }
        }
        const auto& remain{ i < firstSize ? first : last };
        for (auto k = i < firstSize ? i : j; k < remain.size(); k++)
        {
            result.push_back(remain.at(k));
        }
        return result;
    }
}

#endif // ALGORITHM_THINGS_MERGE_H
