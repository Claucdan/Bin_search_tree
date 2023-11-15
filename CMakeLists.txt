cmake_minimum_required(VERSION 3.26)
project(Bin_search_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bin_search_tree main.cpp
        cmake-build-debug/Binary_tree.cpp
        cmake-build-debug/Binary_tree.h)
