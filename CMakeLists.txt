cmake_minimum_required(VERSION 3.21)
project(Sorting)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Sorting
        main.cpp
        Sorting.hpp
        Console.cpp
        BinaryHeap.cpp
        Searching.hpp
        SortManager.hpp
        SortManager.cpp
        Date.cpp
        Date.hpp
        SearchManager.cpp
        SearchManager.hpp
        ConsoleManager.cpp)
