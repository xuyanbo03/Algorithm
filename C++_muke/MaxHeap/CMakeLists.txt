cmake_minimum_required(VERSION 3.8)
project(MaxHeap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MaxHeap.h InsertionSort.h MergeSort.h QuickSort.h QuickSort2.h SortTestHelper.h HeapSort.h IndexMaxHeap.h)
add_executable(MaxHeap ${SOURCE_FILES})