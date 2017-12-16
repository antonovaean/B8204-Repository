cmake_minimum_required(VERSION 3.9)
project(TaskTest91217)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(libs/googletest)
include_directories(libs/googletest/include)

set(SOURCE_FILES my_lib.cpp tests.cpp)

add_executable(TaskTest91217 ${SOURCE_FILES})

target_link_libraries(TaskTest91217 gtest_main)