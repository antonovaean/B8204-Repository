cmake_minimum_required(VERSION 3.8)
project(Fib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Fib.cpp Fib.h)
add_executable(Fib ${SOURCE_FILES})