cmake_minimum_required(VERSION 3.8)
project(QuickSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp QuickSort.h QuickSort2.h MergeSort.h SortTestHelper.h InsertionSort.h)
add_executable(QuickSort ${SOURCE_FILES})