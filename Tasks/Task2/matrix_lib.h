#ifndef PROJECT_MATRIX_LIB_H
#define PROJECT_MATRIX_LIB_H

#include <iostream>
#include <string>
namespace MatrixLib {
    typedef unsigned short int MSIZE_T;
    typedef float MITEM_T;

    /** @link https://en.wikipedia.org/wiki/Matrix_(mathematics) */
    struct Matrix {
        MSIZE_T m, n;
        MITEM_T **v;

        /* Copy constructor */
        Matrix(Matrix &a);
        /* Constructor for Matrix with dimensions MxN */
        Matrix(MSIZE_T m, MSIZE_T n);
        ~Matrix();

        MITEM_T* operator[](const MSIZE_T &a);
        Matrix& getInverse();
        MITEM_T getDeterminant();
    };

    template<typename T>
    Matrix& operator*(const Matrix &a, const T &multiplier);
    template<typename T>
    Matrix& operator*(const T &multiplier, const Matrix &a);
    Matrix& operator*(const Matrix &a, const Matrix &b);
    Matrix& operator+(const Matrix &a, const Matrix &b);
    Matrix& operator-(const Matrix &a, const Matrix &b);
    std::ostream& operator<<(std::ostream& out, const Matrix &a);
}

#endif //PROJECT_MATRIX_LIB_H
