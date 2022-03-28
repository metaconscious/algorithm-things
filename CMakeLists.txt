cmake_minimum_required(VERSION 3.21)
project(algorithm_things)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS off)

include_directories(src)

add_executable(algorithm_things
        src/DivideAndConquer.h
        src/main.cpp
        src/Merge.h
        src/Partition.h
        src/Timer.h
        src/Type.h src/BubbleSort.h src/InsertionSort.h src/SelectionSort.h)
