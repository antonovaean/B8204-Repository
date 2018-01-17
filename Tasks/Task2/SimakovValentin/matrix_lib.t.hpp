#ifndef PROJECT_MATRIX_LIB_T_H
#define PROJECT_MATRIX_LIB_T_H
template<typename T>
MatrixLib::Matrix MatrixLib::operator*(const MatrixLib::Matrix &a, const T &multiplier){
    for(int i = 0; i < a.rows; i++)
        for(int j = 0; j < a.cols; j++)
            a.table[i][j] *= multiplier;
    return a;
}

template<typename T>
MatrixLib::Matrix MatrixLib::operator*(const T &multiplier, const MatrixLib::Matrix &a){
    for(int i = 0; i < a.rows; i++)
        for(int j = 0; j < a.cols; j++)
            a.table[i][j] *= multiplier;
    return a;
}
#endif //PROJECT_MATRIX_LIB_T_H
