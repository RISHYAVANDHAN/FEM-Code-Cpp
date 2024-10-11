cmake_minimum_required(VERSION 3.26)
project(FEM_Code)

set(CMAKE_CXX_STANDARD 23)

add_executable(FEM_code main.cpp
        Node/Node.hpp
        Node/Node.cpp)
