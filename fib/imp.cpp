#include "mylib.h"
#include <stdio.h>

int fib(int n) {
    return (n < 1) ? 0 : (n <= 2) ? 1 : fib(n - 1) + fib(n - 2);
}