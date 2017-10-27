#include <stdio.h>

#include "fib.h"

int main()
{
    for (int i = 0; i < 10; ++i) printf("%d ", getFib(i));
    return 0;
}