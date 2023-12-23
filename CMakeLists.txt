cmake_minimum_required(VERSION 3.19)
project(sortingalgos)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
find_package(OpenMP COMPONENTS CXX)

set(GLOBAL_FLAGS -Wall -Wextra -g -Wno-sign-compare -O2)

add_compile_options(${GLOBAL_FLAGS})

add_subdirectory(src)