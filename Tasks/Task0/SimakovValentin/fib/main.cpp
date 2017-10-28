#include "mylib.h"
#include <stdio.h>
#include <math.h>

int main() {
    int a  = 0, b = 0;
    for (int i = 1; i < 35; i++){
        a = b = 0;
        fib(i + 1, a), fib(i , b);
        printf("%lf\n", (double)a/b);
    } 
    printf("Phi = %f", (1 + sqrt(5)) / 2);
    return 0;
}