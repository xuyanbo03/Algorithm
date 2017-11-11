cmake_minimum_required(VERSION 3.8)
project(SelectionSorts)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SortTestHelper.h Student.h SelectionSort.h)
add_executable(SelectionSorts ${SOURCE_FILES})