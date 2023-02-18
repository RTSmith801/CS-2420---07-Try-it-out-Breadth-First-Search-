cmake_minimum_required(VERSION 3.24)
project(07_Learning_Activity_Dijkstras_Algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories("Header Files")
include_directories("Resource Files")
include_directories("Source Files")

add_executable(07_Learning_Activity_Dijkstras_Algorithm
        "Header Files/Graph.h"
        "cmake-build-debug/graph.txt"
        "Source Files/Graph.cpp"
        "Source Files/Main.cpp")
