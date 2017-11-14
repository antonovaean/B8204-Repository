#include "fib_arr.h"

int fib(int n) {
    static bool initialized = false;
    static int arr[FIB_MAX_N] = {};

    if (!initialized) {
        arr[0] = 1;
        arr[1] = 1;
        initialized = true;
    }

    if ((n < 1) || (n > FIB_MAX_N)) return -1; // ошибка

    if (arr[n - 1] == 0)
        arr[n - 1] = fib(n - 1) + fib(n - 2);

    return arr[n - 1];
}
