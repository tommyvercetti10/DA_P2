cmake_minimum_required(VERSION 3.26.4)
project(da_proj2)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(da_proj2
        DataLoader.cpp
        DataLoader.h
        graph/Vertex.h
        Coordinates.h
        Coordinates.cpp
        graph/Vertex.cpp
        graph/Edge.h
        graph/Edge.cpp
        graph/Graph.h
        graph/Graph.cpp
        main.cpp
        graph/MutablePriorityQueue.h
        DataManager.h
        DataManager.cpp
        Menu.cpp)
