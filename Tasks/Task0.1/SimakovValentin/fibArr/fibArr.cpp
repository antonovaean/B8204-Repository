#include <stdio.h>

int main(){
    int a[30];
    int i = 2;
    a[0] = 1;
    a[1] = 1;
    printf("1 1 ");
    while (i < 30){
        a[i] = a[i - 1] + a[i - 2];
        printf("%d ", a[i]);
        i++;    
    }
    return 0;
}