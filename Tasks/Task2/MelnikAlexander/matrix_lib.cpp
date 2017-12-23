#include "matrix_lib.h"
#include <vector>
#include <algorithm>

using namespace MatrixLib;

MITEM_T** allocateMemoryForMatrix(MSIZE_T m, MSIZE_T n) {
    MITEM_T **v = new MITEM_T*[m];
    for (MSIZE_T i = 0; i < m; i++) {
        v[i] = new MITEM_T[n];
    }
    return v;
}

Matrix::Matrix(const Matrix &a)  {
    this->m = a.m;
    this->n = a.n;

    v = allocateMemoryForMatrix(m, n);

    for (MSIZE_T i = 0; i < m; i++) {
        for (MSIZE_T j = 0; j < n; j++) {
            v[i][j] = a[i][j];
        }
    }
}

Matrix::Matrix(MSIZE_T m, MSIZE_T n) {
    this->m = m;
    this->n = n;

    v = allocateMemoryForMatrix(m, n);

    for (MSIZE_T i = 0; i < m; i++) {
        for (MSIZE_T j = 0; j < n; j++) {
            v[i][j] = 0;
        }
    }
}

Matrix::~Matrix() {
    for (MSIZE_T i = 0; i < m; i++) {
        delete [] v[i];
    }
    delete [] v;
}

MITEM_T* Matrix::operator[](const MSIZE_T &a) const {
    return v[a];
}

size_t getInversions(std::vector<MSIZE_T> v) {
    size_t res = 0;

    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = i+1; j < v.size(); j++) {
            if (v[i] > v[j])
                res++;
        }
    }

    return res;
}

class MatrixNotSquareException: public std::exception {
    virtual const char* what() const throw() {
        return "Matrix isn't square.";
    }
};

MITEM_T Matrix::getDeterminant() const {
    if (m != n) {
        throw MatrixNotSquareException();
    }

    MITEM_T sum = 0;

    std::vector<MSIZE_T> indices;
    for (MSIZE_T i = 0; i < n; i++) {
        indices.push_back(i);
    }

    do {
        MITEM_T summand = 1;
        for (MSIZE_T i = 0; i < indices.size(); i++) {
            summand *= v[i][ indices[i] ];
        }

        if ( (getInversions(indices) % 2) != 0 ) {
            summand *= -1;
        }

        sum += summand;

    } while (std::next_permutation( indices.begin(), indices.end() ));

    return sum;
}

Matrix MatrixLib::getMultiplicationOfMatrixAndScalar(const Matrix &a, const MITEM_T &multiplier) {

    Matrix res(a);

    for (MSIZE_T i = 0; i < res.m; i++) {
        for (MSIZE_T j = 0; j < res.n; j++) {
            res[i][j] *= multiplier;
        }
    }

    return res;
}

class MatrixMultiplicationFailedException: public std::exception {
    virtual const char* what() const throw() {
        return "Columns quantity of first matrix isn't equal to rows quantity of second matrix.";
    }
};

Matrix MatrixLib::getMultiplicationOfMatrices(const Matrix &a, const Matrix &b) {

    if (a.n != b.m) {
        throw MatrixMultiplicationFailedException();
    }

    Matrix res(a.m, a.n);

    for (MSIZE_T i = 0; i < a.m; i++) {
        for (MSIZE_T j = 0; j < b.n; j++) {
            for (MSIZE_T k = 0; k < a.n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

class MatrixUnequalDimensionsException: public std::exception {
    virtual const char* what() const throw() {
        return "Dimensions of matrices aren't equal.";
    }
};

Matrix MatrixLib::getSumOfMatrices(const Matrix &a, const Matrix &b) {

    if ((a.m != b.m) || (a.n != b.n)) {
        throw MatrixUnequalDimensionsException();
    }

    Matrix res(a);

    for (MSIZE_T i = 0; i < a.m; i++) {
        for (MSIZE_T j = 0; j < a.n; j++) {
            res[i][j] += b[i][j];
        }
    }

    return res;
}

Matrix MatrixLib::getDifferenceOfMatrices(const Matrix &a, const Matrix &b) {

    if ((a.m != b.m) || (a.n != b.n)) {
        throw MatrixUnequalDimensionsException();
    }

    Matrix res(a);

    for (MSIZE_T i = 0; i < a.m; i++) {
        for (MSIZE_T j = 0; j < a.n; j++) {
            res[i][j] -= b[i][j];
        }
    }

    return res;
}

void printMatrix(std::ostream &out, const Matrix &a) {
    for (MSIZE_T i = 0; i < a.m; i++) {
        for (MSIZE_T j = 0; j < a.n; j++) {
            out << a.v[i][j] << ' ';
        }
        out << std::endl;
    }
}

std::ostream& MatrixLib::operator<<(std::ostream &out, const Matrix &a) {
    printMatrix(out, a);
    return out;
}
