cmake_minimum_required(VERSION 3.8)
project(ShortestPath)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h IndexMinHeap.h Edge.h ReadGraph.h Dijkstra.h BellmanFord.h)
add_executable(ShortestPath ${SOURCE_FILES})