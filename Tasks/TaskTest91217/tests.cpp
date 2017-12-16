//
// Created by macbook on 09.12.2017.
//
#include "gtest/gtest.h"
#include "my_lib.h"

TEST(SuiteName, Test91217) {
    EXPECT_EQ(1, fib(1));
    EXPECT_EQ(1, fib(2));
    EXPECT_EQ(2, fib(3));
    EXPECT_EQ(3, fib(4));
    EXPECT_EQ(5, fib(5));
    EXPECT_EQ(8, fib(6));
    EXPECT_EQ(13, fib(7));

}

