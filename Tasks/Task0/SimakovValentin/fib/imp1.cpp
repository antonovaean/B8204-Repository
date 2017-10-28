#include "mylib.h"
#include <stdio.h>
#include <math.h>


void sayhello() {
    printf("Hello Test\n");
}
int aplusb(int a, int b) {
    return b + a;
}
int fib(int n, int& c) {
    return (int)((pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n))/sqrt(5));
    /*c++;
    if (n < 1){
        return 0;
    } else if (n <= 2) {
        return 1;
    } else return fib(n - 1, c) + fib(n - 2, c);*/
}