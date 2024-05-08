cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)
project(TD07)

add_executable(node src/graph.cpp)
add_executable(main src/main.cpp)