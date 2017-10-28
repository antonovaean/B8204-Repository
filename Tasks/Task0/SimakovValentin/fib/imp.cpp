#include "mylib.h"
#include <stdio.h>

void sayhello() {
    printf("Hello World\n");
}
int aplusb(int a, int b) {
    return a + b;
}
int fib(int n, int& c) {
    return c++, (n < 1) ? 0 : (n <= 2) ? 1 : fib(n - 1, c) + fib(n - 2, c);
}

int sinmcloren(int n){
    
    if ((n + 1) % 4 == 0){
        return 1;
    } else{
        return -1;
    }
}