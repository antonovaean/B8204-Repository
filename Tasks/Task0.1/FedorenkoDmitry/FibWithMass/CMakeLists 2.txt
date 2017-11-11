cmake_minimum_required(VERSION 3.8)
project(FibWithMass)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Fib.h Fib.cpp)
add_executable(FibWithMass ${SOURCE_FILES})