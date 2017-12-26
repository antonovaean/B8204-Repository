#ifndef PROJECT_MATRIX_LIB_T_H
#define PROJECT_MATRIX_LIB_T_H

#include <vector> // vector
#include <algorithm> // next_permutation

using namespace MatrixLib;

template <typename T>
T** allocateMemoryForMatrix(MSIZE_T m, MSIZE_T n) {
    T **v = new T*[m];
    for (MSIZE_T i = 0; i < m; i++) {
        v[i] = new T[n];
    }
    return v;
}

template <class Type>
Matrix<Type>::Matrix(const Matrix<Type> &a)  {
    this->m = a.m;
    this->n = a.n;

    v = allocateMemoryForMatrix<Type>(m, n);

    for (MSIZE_T i = 0; i < m; i++) {
        for (MSIZE_T j = 0; j < n; j++) {
            v[i][j] = a[i][j];
        }
    }
}

template <class Type>
Matrix<Type>::Matrix(MSIZE_T m, MSIZE_T n) {
    this->m = m;
    this->n = n;

    v = allocateMemoryForMatrix<Type>(m, n);

    for (MSIZE_T i = 0; i < m; i++) {
        for (MSIZE_T j = 0; j < n; j++) {
            v[i][j] = 0;
        }
    }
}

template <class Type>
Matrix<Type>::~Matrix() {
    for (MSIZE_T i = 0; i < m; i++) {
        delete [] v[i];
    }
    delete [] v;
}

template <class Type>
Type* Matrix<Type>::operator[](const MSIZE_T &a) const {
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

template <class Type>
Type Matrix<Type>::getDeterminant() const {
    if (m != n) {
        throw MatrixNotSquareException();
    }

    Type sum = 0;

    std::vector<MSIZE_T> indices;
    for (MSIZE_T i = 0; i < n; i++) {
        indices.push_back(i);
    }

    do {
        Type summand = 1;
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

template <class Type>
Matrix<Type> Matrix<Type>::getTranspose() const {

    Matrix<Type> res(n, m);

    for (MSIZE_T i = 0; i < res.m; i++) {
        for (MSIZE_T j = 0; j < res.n; j++) {
            res[i][j] = v[j][i];
        }
    }

    return res;
}

template <class Type>
Type Matrix<Type>::getMinor(const MSIZE_T &i, const MSIZE_T &j) const {
    if ((i < 0) || (i >= m) || (j < 0) || (j >= n)) {
        throw MatrixOutOfRangeException();
    }

    if (m != n) {
        throw MatrixNotSquareException();
    }

    if (m == 1) {
        return v[0][0];
    }

    Matrix<Type> res(m - 1, n - 1);

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

template <class Type>
Type Matrix<Type>::getCofactor(const MSIZE_T &i, const MSIZE_T &j) const {

    Type multiplier = 1;

    if ((i + j) % 2 != 0) {
        multiplier = -1;
    }

    return multiplier * getMinor(i, j);
}

template <class Type>
Matrix<Type> Matrix<Type>::getCofactor() const {

    Matrix<Type> res(m, n);

    for (MSIZE_T i = 0; i < res.m; i++) {
        for (MSIZE_T j = 0; j < res.n; j++) {
            res[i][j] = getCofactor(i, j);
        }
    }

    return res;
}

template <class Type>
Matrix<Type> Matrix<Type>::getAdjugate() const {
    return this->getCofactor().getTranspose();
}

template <class Type>
Matrix<Type> Matrix<Type>::getInverse() const {
    if (m != n) {
        throw MatrixNotSquareException();
    }

    Type det;
    if ( (det = this->getDeterminant()) == 0 ) {
        throw MatrixNonInvertibleException();
    }

    return this->getAdjugate() * (1 / det);
}

template <typename T, class Type>
Matrix<Type> MatrixLib::operator*(const Matrix<Type> &a, const T &multiplier) {

    Matrix<Type> res(a);

    for (MSIZE_T i = 0; i < res.m; i++) {
        for (MSIZE_T j = 0; j < res.n; j++) {
            res[i][j] *= multiplier;
        }
    }

    return res;
}

template <typename T, class Type>
Matrix<Type> MatrixLib::operator*(const T &multiplier, const Matrix<Type> &a) {
    return a * multiplier;
}

template <class Type>
Matrix<Type> MatrixLib::operator*(const Matrix<Type> &a, const Matrix<Type> &b) {

    if (a.n != b.m) {
        throw MatrixMultiplicationFailedException();
    }

    Matrix<Type> res(a.m, a.n);

    for (MSIZE_T i = 0; i < a.m; i++) {
        for (MSIZE_T j = 0; j < b.n; j++) {
            for (MSIZE_T k = 0; k < a.n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

template <class Type>
Matrix<Type> MatrixLib::operator+(const Matrix<Type> &a, const Matrix<Type> &b) {

    if ((a.m != b.m) || (a.n != b.n)) {
        throw MatrixUnequalDimensionsException();
    }

    Matrix<Type> res(a);

    for (MSIZE_T i = 0; i < a.m; i++) {
        for (MSIZE_T j = 0; j < a.n; j++) {
            res[i][j] += b[i][j];
        }
    }

    return res;
}

template <class Type>
Matrix<Type> MatrixLib::operator-(const Matrix<Type> &a, const Matrix<Type> &b) {

    if ((a.m != b.m) || (a.n != b.n)) {
        throw MatrixUnequalDimensionsException();
    }

    Matrix<Type> res(a);

    for (MSIZE_T i = 0; i < a.m; i++) {
        for (MSIZE_T j = 0; j < a.n; j++) {
            res[i][j] -= b[i][j];
        }
    }

    return res;
}

template <class Type>
std::ostream& MatrixLib::operator<<(std::ostream &out, const Matrix<Type> &a) {
    for (MSIZE_T i = 0; i < a.m; i++) {
        for (MSIZE_T j = 0; j < a.n; j++) {
            out << a.v[i][j] << ' ';
        }
        out << std::endl;
    }
    return out;
}

#endif //PROJECT_MATRIX_LIB_T_H
