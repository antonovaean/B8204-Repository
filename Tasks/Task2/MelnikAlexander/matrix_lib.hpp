#ifndef PROJECT_MATRIX_LIB_H
#define PROJECT_MATRIX_LIB_H

#include <iostream>

namespace MatrixLib {
    typedef unsigned short int MSIZE_T;

    /** @link https://en.wikipedia.org/wiki/Matrix_(mathematics) */
    template <class Type>
    struct Matrix {
        MSIZE_T m, n;
        Type **v;

        /* Copy constructor */
        Matrix(const Matrix &a);
        /* Constructor for Matrix with dimensions MxN */
        Matrix(MSIZE_T m, MSIZE_T n);
        ~Matrix();

        Type* operator[](const MSIZE_T &a) const;
        Type getDeterminant() const;

        Matrix getTranspose() const;
        Type getMinor(const MSIZE_T &i, const MSIZE_T &j) const;
        Type getCofactor(const MSIZE_T &i, const MSIZE_T &j) const;
        Matrix getCofactor() const;
        Matrix getAdjugate() const;
        Matrix getInverse() const;
    };

    template <typename T, class Type>
    Matrix<Type> operator*(const Matrix<Type> &a, const T &multiplier);

    template <typename T, class Type>
    Matrix<Type> operator*(const T &multiplier, const Matrix<Type> &a);

    template <class Type>
    Matrix<Type> operator*(const Matrix<Type> &a, const Matrix<Type> &b);

    template <class Type>
    Matrix<Type> operator+(const Matrix<Type> &a, const Matrix<Type> &b);

    template <class Type>
    Matrix<Type> operator-(const Matrix<Type> &a, const Matrix<Type> &b);

    template <class Type>
    std::ostream& operator<<(std::ostream &out, const Matrix<Type> &a);


    class MatrixNotSquareException: public std::exception {
        virtual const char* what() const throw() {
            return "Matrix isn't square.";
        }
    };

    class MatrixMultiplicationFailedException: public std::exception {
        virtual const char* what() const throw() {
            return "Columns quantity of first matrix isn't equal to rows quantity of second matrix.";
        }
    };

    class MatrixUnequalDimensionsException: public std::exception {
        virtual const char* what() const throw() {
            return "Dimensions of matrices aren't equal.";
        }
    };

    class MatrixOutOfRangeException: public std::exception {
        virtual const char* what() const throw() {
            return "An attempt to read out of range.";
        }
    };

    class MatrixNonInvertibleException: public std::exception {
        virtual const char* what() const throw() {
            return "Determinant of matrix equals zero.";
        }
    };
}

// implementation of template functions
#include "matrix_lib.t.hpp"

#endif //PROJECT_MATRIX_LIB_H
