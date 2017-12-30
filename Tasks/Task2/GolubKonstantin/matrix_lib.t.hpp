#ifndef PROJECT_MATRIX_LIB_T_H
#define PROJECT_MATRIX_LIB_T_H

template<typename T> MatrixLib::Matrix multiplication(MatrixLib::Matrix a, const T &multiplier)
{
    for(int i = 0; i < a.rows; i++)
        for(int j = 0; j < a.columns; j++)
            a.matrix[i][j] *= multiplier;
    return a;
}

template<typename T> MatrixLib::Matrix MatrixLib::operator*(const MatrixLib::Matrix &a, const T &multiplier)
{
    return multiplication(a, multiplier);
}

template<typename T> MatrixLib::Matrix MatrixLib::operator*(const T &multiplier, const MatrixLib::Matrix &a)
{
    return multiplication(a, multiplier);
}
#endif //PROJECT_MATRIX_LIB_T_H