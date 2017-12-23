#ifndef PROJECT_MATRIX_LIB_H
#define PROJECT_MATRIX_LIB_H

#include <iostream>

namespace MatrixLib {
    typedef unsigned short int MSIZE_T;
    typedef float MITEM_T;

    /** @link https://en.wikipedia.org/wiki/Matrix_(mathematics) */
    struct Matrix {
        MSIZE_T m, n;
        MITEM_T **v;

        /* Copy constructor */
        Matrix(const Matrix &a);
        /* Constructor for Matrix with dimensions MxN */
        Matrix(MSIZE_T m, MSIZE_T n);
        ~Matrix();

        MITEM_T* operator[](const MSIZE_T &a) const;
        Matrix getInverse() const;
        MITEM_T getDeterminant() const;
    };

    Matrix getMultiplicationOfMatrixAndScalar(const Matrix &a, const MITEM_T &multiplier);
    Matrix getMultiplicationOfMatrices(const Matrix &a, const Matrix &b);
    Matrix getSumOfMatrices(const Matrix &a, const Matrix &b);
    Matrix getDifferenceOfMatrices(const Matrix &a, const Matrix &b);
    std::ostream& operator<<(std::ostream &out, const Matrix &a);
}

#endif //PROJECT_MATRIX_LIB_H
