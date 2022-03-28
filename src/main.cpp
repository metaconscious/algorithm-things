//
// Created by user on 3/27/22.
//

#include "BubbleSort.h"
#include "DivideAndConquer.h"
#include "InsertionSort.h"
#include "Merge.h"
#include "Partition.h"
#include "SelectionSort.h"
#include "Timer.h"
#include "Type.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector)
{
    for (auto&& item: vector)
    {
        os << item << ' ';
    }
    return os;
}

template<typename T>
bool equal(const std::vector<T>& v1, const std::vector<T>& v2)
{
    if (v1.size() == v2.size())
    {
        auto size{ v1.size() };
        for (decltype(size) i{ 0 }; i < size; ++i)
        {
            if (v1.at(i) != v2.at(i))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main()
{
    // alias
    using Array = algo::Array<int>;
    using ArrayPair = algo::ArrayPair<int>;
    using DacTimer = algo::Timer<Array,
            Array, std::function<ArrayPair(const Array&)>, std::function<Array(const ArrayPair&)>>;
    using BsTimer = algo::Timer<Array, const Array&>;
    using BsiTimer = algo::Timer<void, Array&>;
    using IsiTimer = algo::Timer<void, Array&>;
    using SsiTimer = algo::Timer<void, Array&>;
    // initial
    Array integers(100000);
    std::iota(integers.begin(), integers.end(), 1);
    // backup
    Array original{ integers };
    // randomize
    std::random_device r{};
    std::seed_seq seeds{ r(), r(), r(), r(), r(), r() };
    std::mt19937 mersenneTwister{ seeds };
    std::ranges::shuffle(integers, mersenneTwister);

    DacTimer dac{ algo::divideAndConquer<int> };
    Array&& mergeSorted{ dac(integers, algo::partition<int>, algo::merge<int>) };

    BsTimer bs{ algo::bubbleSort<int> };
    Array&& bubbleSorted{ bs(integers) };

    Array bubbleInplaceSorted{ integers.cbegin(), integers.cend() };
    BsiTimer bsi{ algo::inp::bubbleSort<int> };
    bsi(bubbleInplaceSorted);

    Array insertionInplaceSorted{ integers.cbegin(), integers.cend() };
    IsiTimer isi{ algo::inp::insertionSort<int> };
    isi(insertionInplaceSorted);

    Array selectionInplaceSorted{ integers.cbegin(), integers.cend() };
    SsiTimer ssi{ algo::inp::selectionSort<int> };
    ssi(selectionInplaceSorted);

    std::cout
            << "Unsorted Array: "
            << integers
            << '\n'
            << "Merge Sort: "
            << "\n - Success: " << std::boolalpha << equal(original, mergeSorted)
            << "\n - Cost: " << dac.getLastTime() << " second(s)"
            << '\n'
            << "Bubble Sort: "
            << "\n - Success: " << std::boolalpha << equal(original, bubbleSorted)
            << "\n - Cost: " << bs.getLastTime() << " second(s)"
            << '\n'
            << "Bubble Sort(in-place): "
            << "\n - Success: " << std::boolalpha << equal(original, bubbleInplaceSorted)
            << "\n - Cost: " << bsi.getLastTime() << " second(s)"
            << '\n'
            << "Insertion Sort(in-place): "
            << "\n - Success: " << std::boolalpha << equal(original, insertionInplaceSorted)
            << "\n - Cost: " << isi.getLastTime() << " second(s)"
            << '\n'
            << "Selection Sort(in-place): "
            << "\n - Success: " << std::boolalpha << equal(original, selectionInplaceSorted)
            << "\n - Cost: " << ssi.getLastTime() << " second(s)"
            << '\n';

    return 0;
}