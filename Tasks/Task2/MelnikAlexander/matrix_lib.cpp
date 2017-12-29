#include "matrix_lib.hpp"

#include <cstring> // memcpy
#include <vector> // vector
#include <algorithm> // next_permutation

using namespace MatrixLib;

Matrix::Matrix(const Matrix &a)  {
    this->m = a.m;
    this->n = a.n;

    v = (MITEM_T**)malloc(m * sizeof(MITEM_T*));

    for (MSIZE_T i = 0; i < m; ++i) {
        v[i] = (MITEM_T*)malloc(n * sizeof(MITEM_T));
        memcpy(v[i], a[i], n * sizeof(MITEM_T));
    }
}

Matrix::Matrix(MSIZE_T m, MSIZE_T n) {
    this->m = m;
    this->n = n;

    v = (MITEM_T**)malloc(m * sizeof(MITEM_T*));

    for (MSIZE_T i = 0; i < m; ++i) {
        v[i] = (MITEM_T*)calloc(n, sizeof(MITEM_T));
    }
}

Matrix::~Matrix() {
    for (MSIZE_T i = 0; i < m; ++i) {
        free(v[i]);
    }
    free(v);
}

MITEM_T* Matrix::operator[](const MSIZE_T &a) const {
    return v[a];
}

size_t getInversions(std::vector<MSIZE_T> v) {
    size_t res = 0;

    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[i] > v[j]) {
                ++res;
            }
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
    for (MSIZE_T i = 0; i < n; ++i) {
        indices.push_back(i);
    }

    do {
        MITEM_T summand = 1;
        for (MSIZE_T i = 0; i < indices.size(); ++i) {
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

    for (MSIZE_T i = 0; i < res.m; ++i) {
        for (MSIZE_T j = 0; j < res.n; ++j) {
            res[i][j] = v[j][i];
        }
    }

    return res;
}

MITEM_T Matrix::getMinor(const MSIZE_T &_i, const MSIZE_T &_j) const {
    if ((_i < 0) || (_i >= m) || (_j < 0) || (_j >= n)) {
        throw MatrixOutOfRangeException();
    }

    if (m != n) {
        throw MatrixNotSquareException();
    }

    if (m == 1) {
        return v[0][0];
    }

    Matrix res(m - 1, n - 1);

    for (MSIZE_T i = 0; i < m; ++i) {
        for (MSIZE_T j = 0; j < n; ++j) {

            if ((i == _i) || (j == _j)) {
                continue;
            }

            if ((i > _i) && (j > _j))
                res[i - 1][j - 1] = v[i][j];
            else if (i > _i)
                res[i - 1][j] = v[i][j];
            else if (j > _j)
                res[i][j - 1] = v[i][j];
            else
                res[i][j] = v[i][j];
        }
    }

    return res.getDeterminant();
}

MITEM_T Matrix::getCofactor(const MSIZE_T &i, const MSIZE_T &j) const {

    MITEM_T multiplier = ((i + j) % 2) ? -1 : 1;

    return multiplier * getMinor(i, j);
}

Matrix Matrix::getCofactor() const {

    Matrix res(m, n);

    for (MSIZE_T i = 0; i < res.m; ++i) {
        for (MSIZE_T j = 0; j < res.n; ++j) {
            res[i][j] = getCofactor(i, j);
        }
    }

    return res;
}

Matrix Matrix::getAdjugate() const {
    return getCofactor().getTranspose();
}

Matrix Matrix::getInverse() const {
    if (m != n) {
        throw MatrixNotSquareException();
    }

    MITEM_T det;
    if ( (det = getDeterminant()) == 0 ) {
        throw MatrixNonInvertibleException();
    }

    return getAdjugate() * (1 / det);
}

Matrix MatrixLib::operator*(const Matrix &a, const Matrix &b) {

    if (a.n != b.m) {
        throw MatrixMultiplicationFailedException();
    }

    Matrix res(a.m, a.n);

    for (MSIZE_T i = 0; i < a.m; ++i) {
        for (MSIZE_T j = 0; j < b.n; ++j) {
            for (MSIZE_T k = 0; k < a.n; ++k) {
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

    for (MSIZE_T i = 0; i < a.m; ++i) {
        for (MSIZE_T j = 0; j < a.n; ++j) {
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

    for (MSIZE_T i = 0; i < a.m; ++i) {
        for (MSIZE_T j = 0; j < a.n; ++j) {
            res[i][j] -= b[i][j];
        }
    }

    return res;
}

std::ostream& MatrixLib::operator<<(std::ostream &out, const Matrix &a) {
    for (MSIZE_T i = 0; i < a.m; ++i) {
        for (MSIZE_T j = 0; j < a.n; ++j) {
            out << a.v[i][j] << ' ';
        }
        out << std::endl;
    }
    return out;
}
