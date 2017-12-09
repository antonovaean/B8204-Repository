#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>
#include "matrix_lib.h"

int main(){
    try{
        matrix A(4), B(4);
        A.fill(0, 5);
        B.fill(0, 5);
        A.print();
        A.invert().print();
        (A * A.invert()).print();
        B.print();
        B.invert().print();
        (B * B.invert()).print();
    }
    catch(...){
        printf("Illegal matrix size for these operations!");
    }

    return 0;
}
