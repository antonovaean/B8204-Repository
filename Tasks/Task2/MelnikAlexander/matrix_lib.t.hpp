#ifndef PROJECT_MATRIX_LIB_T_H
#define PROJECT_MATRIX_LIB_T_H

template<typename T>
MatrixLib::Matrix MatrixLib::operator*(const MatrixLib::Matrix &a, const T &multiplier) {

    Matrix res(a);

    for (MSIZE_T i = 0; i < res.m; i++) {
        for (MSIZE_T j = 0; j < res.n; j++) {
            res[i][j] *= multiplier;
        }
    }

    return res;
}

template<typename T>
MatrixLib::Matrix MatrixLib::operator*(const T &multiplier, const MatrixLib::Matrix &a) {
    return a * multiplier;
}

#endif //PROJECT_MATRIX_LIB_T_H
