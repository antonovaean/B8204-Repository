cmake_minimum_required(VERSION 3.8)
project(MatrixLib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp matrix_lib.cpp)

add_executable(MatrixLib ${SOURCE_FILES})