cmake_minimum_required(VERSION 3.20)
project(untitled3 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled3 main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h libs/algorithms/array/array.c libs/algorithms/array/array.h libs/algorithms/algorithms.c libs/algorithms/algorithms.h)

add_subdirectory(libs)
target_link_libraries(untitled3 data_structures)
target_link_libraries(untitled3 algorithms)