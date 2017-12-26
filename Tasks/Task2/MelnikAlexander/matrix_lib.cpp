#include "matrix_lib.hpp"

#include <vector> // vector
#include <algorithm> // next_permutation
#include <cmath> // pow

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

Matrix Matrix::getTranspose() const {

    Matrix res(n, m);

    for (MSIZE_T i = 0; i < res.m; i++) {
        for (MSIZE_T j = 0; j < res.n; j++) {
            res[i][j] = v[j][i];
        }
    }

    return res;
}

MITEM_T Matrix::getMinor(const MSIZE_T &i, const MSIZE_T &j) const {
    if ((i < 0) || (i >= m) || (j < 0) || (j >= n)) {
        throw MatrixOutOfRangeException();
    }

    if (m != n) {
        throw MatrixNotSquareException();
    }

    if (m == 1) {
        return v[0][0];
    }

    Matrix res(m - 1, n - 1);

    for (MSIZE_T _i = 0; _i < i; _i++) {

        for (MSIZE_T _j = 0; _j < j; _j++) {
            res[_i][_j] = v[_i][_j];
        }

        for (MSIZE_T _j = j + 1; _j < n; _j++) {
            res[_i][_j - 1] = v[_i][_j];
        }
    }

    for (MSIZE_T _i = i + 1; _i < m; _i++) {

        for (MSIZE_T _j = 0; _j < j; _j++) {
            res[_i - 1][_j] = v[_i][_j];
        }

        for (MSIZE_T _j = j + 1; _j < n; _j++) {
            res[_i - 1][_j - 1] = v[_i][_j];
        }
    }

    return res.getDeterminant();
}

MITEM_T Matrix::getCofactor(const MSIZE_T &i, const MSIZE_T &j) const {

    MITEM_T multiplier = 1;

    if ((i + j) % 2 != 0) {
        multiplier = -1;
    }

    return multiplier * getMinor(i, j);
}

Matrix Matrix::getCofactor() const {

    Matrix res(m, n);

    for (MSIZE_T i = 0; i < res.m; i++) {
        for (MSIZE_T j = 0; j < res.n; j++) {
            res[i][j] = getCofactor(i, j);
        }
    }

    return res;
}

Matrix Matrix::getAdjugate() const {
    return this->getCofactor().getTranspose();
}

Matrix Matrix::getInverse() const {
    if (m != n) {
        throw MatrixNotSquareException();
    }

    MITEM_T det;
    if ( (det = this->getDeterminant()) == 0 ) {
        throw MatrixNonInvertibleException();
    }

    return this->getAdjugate() * (1 / det);
}

Matrix MatrixLib::operator*(const Matrix &a, const Matrix &b) {

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

Matrix MatrixLib::operator+(const Matrix &a, const Matrix &b) {

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

Matrix MatrixLib::operator-(const Matrix &a, const Matrix &b) {

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
