#ifndef PROJECT_MATRIX_LIB_H
#define PROJECT_MATRIX_LIB_H

#include <iostream>

namespace MatrixLib
{
    typedef unsigned short int MSIZE_T;
    typedef float MITEM_T;

    struct Matrix
    {
        MSIZE_T rows, columns;
        MITEM_T **matrix;

        /* Copy constructor */
        Matrix(const Matrix &matrix);
        /* Constructor for Matrix with dimensions MxN */
        Matrix(MSIZE_T rows, MSIZE_T columns) throw(std::invalid_argument);
        ~Matrix();

        MITEM_T* operator[](const MSIZE_T &a) const;
        Matrix getInverse() const throw(std::logic_error);
        MITEM_T getDeterminant() const throw(std::logic_error);
    };

    template<typename T> Matrix operator*(const Matrix &a, const T &multiplier);
    template<typename T> Matrix operator*(const T &multiplier, const Matrix &a);
    Matrix operator*(const Matrix &a, const Matrix &b) throw(std::invalid_argument);
    Matrix operator+(const Matrix &a, const Matrix &b) throw(std::invalid_argument);
    Matrix operator-(const Matrix &a, const Matrix &b) throw(std::invalid_argument);
    std::ostream& operator<<(std::ostream &out, const Matrix &matrix);
}

#include "matrix_lib.t.hpp"
#endif //PROJECT_MATRIX_LIB_H