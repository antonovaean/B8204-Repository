#ifndef PROJECT_MATRIX_LIB_H
#define PROJECT_MATRIX_LIB_H
#include <ctime>
#include <iostream>

namespace MatrixLib
{
    typedef unsigned short int MSIZE_T;
    typedef float MITEM_T;

    struct Matrix{
        MSIZE_T rows, cols;
        MITEM_T **table;

        /* Copy constructor */
        Matrix(const Matrix &m);
        /* Constructor for Matrix with dimensions MxN */
        Matrix(MSIZE_T rows, MSIZE_T cols);
        ~Matrix();

        MITEM_T* operator[](const MSIZE_T &a) const;
        Matrix getInverse() const;
        MITEM_T getDeterminant() const;
        void fill(int a, int b){
            srand(time(NULL));
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->cols; j++)
                    this->table[i][j] = a + rand()%b;
        }
    };

    template<typename T>
    Matrix operator*(const Matrix &a, const T &multiplier);
    template<typename T>
    Matrix operator*(const T &multiplier, const Matrix &a);
    Matrix operator*(const Matrix &a, const Matrix &b);
    Matrix operator+(const Matrix &a, const Matrix &b);
    Matrix operator-(const Matrix &a, const Matrix &b);
    std::ostream& operator<<(std::ostream &out, const Matrix &m);
}

#include "matrix_lib.t.hpp"
#endif //PROJECT_MATRIX_LIB_H
