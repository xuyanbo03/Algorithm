cmake_minimum_required(VERSION 3.8)
project(MinimumSpanTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h ReadGraph.h LazyPrimMST.h Edge.h MinHeap.h PrimMST.h IndexMinHeap.h)
add_executable(MinimumSpanTree ${SOURCE_FILES})