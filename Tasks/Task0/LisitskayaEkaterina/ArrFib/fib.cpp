#include <stdio.h>

int main() {
    int a[30];
    a[0]=1;
    a[1]=1;
    int i=2;
    while (i < 30) {
        a[i] = a[i-1]+a[i-2];
        i++;
    }
    for (i=0; i<30; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}