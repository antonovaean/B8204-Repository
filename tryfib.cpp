#include "stdio.h"  
int main (){
    int a[20];
    int fib=1, i=1, postfib=1, n=20;
    a[i]=1;
    while (i<n) {
        postfib=postfib+fib;
        fib=postfib-fib;
        a[i]=fib;
        printf("%d \n", a[i]);
        i=i+1;
    }
	
}