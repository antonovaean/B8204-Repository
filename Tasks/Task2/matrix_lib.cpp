#include "matrix_lib.h"

using namespace MatrixLib;

MITEM_T** allocateMemoryForMatrix(MSIZE_T m, MSIZE_T n) {
    MITEM_T **v = new MITEM_T*[m];
    for (MSIZE_T i = 0; i < m; i++) {
        v[i] = new MITEM_T[n];
    }
    return v;
}

Matrix::Matrix(Matrix &a) {
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

MITEM_T* Matrix::operator[](const MSIZE_T &a) {
    return v[a];
}

std::ostream& operator<<(std::ostream& out, const Matrix &a) {
    for (MSIZE_T i = 0; i < a.m; i++) {
        for (MSIZE_T j = 0; j < a.n; j++) {
            out << a.v[i][j] << ' ';
        }
        out << std::endl;
    }
}