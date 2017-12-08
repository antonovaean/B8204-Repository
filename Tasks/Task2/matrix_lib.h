#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>

class matrix{
    private:
        int rows, cols;
        int** table;
    public:
        matrix(int n, int m);
        matrix(int n);
        void fill(int a, int b);
        void print();
        friend matrix operator + (matrix m1, matrix m2);
        friend matrix operator * (matrix m1, matrix m2);
        int det();
        matrix minor(int k);
        /*
        matrix inv(matrix m);
        matrix trn();
        */
};

