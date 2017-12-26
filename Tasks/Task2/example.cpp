#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>
#include "matrix_lib.h"
#include "matrix_imp.cpp"

int main(){
    try{
        matrix A(4), B(4);
        A.fill(0, 5);
        B.fill(0, 5);
        A.print();
        A.invert().print();
        (A * A.invert()).print();
    }
    catch(...){
        printf("Illegal matrix size for these operations!");
    }

    return 0;
}
