#include <stdio.h>
#include <math.h>
#include <ctime>
#include "matrix_lib.h"

using namespace MatrixLib;

MatrixLib::Matrix::Matrix(const Matrix &m){
    this->rows = m.rows;
    this->cols = m.cols;
    this->table = new float*[this->rows];
    for (int i = 0; i < this->rows; i++) this->table[i] = new float[this->cols];

    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->cols; j++)
            this->table[i][j] = m.table[i][j];
}

MatrixLib::Matrix::Matrix(MSIZE_T rows, MSIZE_T cols){
    if (rows <= 0 || cols <= 0) throw "Invalid matrix size";
    this->rows = rows;
    this->cols = cols;
    this->table = new float*[this->rows];
    for (int i = 0; i < this->rows; i++) this->table[i] = new float[this->cols];

    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->cols; j++)
            this->table[i][j] = 0;
}

MatrixLib::Matrix::~Matrix(){
    for(int i = 0; i < this->rows; i++)
            delete(table[i]);
    delete[] table;

}

MITEM_T* MatrixLib::Matrix::operator[](const MSIZE_T &a) const{
    return this->table[a];
}

Matrix minor(const Matrix &m, int l, int k){
    if((l > m.rows - 1)||(k > m.cols - 1)) throw "The minor doesn't exist";

    Matrix result(m.rows - 1, m.cols - 1);
    for(int i = 0; i < l; i++){
        for(int j = 0; j < k; j++) result.table[i][j] = m.table[i][j];
        for(int j = k + 1; j < m.cols; j++) result.table[i][j-1] = m.table[i][j];
    }

    for(int i = l + 1; i < m.rows; i++){
        for(int j = 0; j < k; j++) result.table[i-1][j] = m.table[i][j];
        for(int j = k + 1; j < m.cols; j++) result.table[i-1][j-1] = m.table[i][j];
    }
    return result;
}

Matrix uni(const Matrix &m){
    Matrix result(m.rows, m.cols);
    for(int i = 0; i < result.rows; i++)
        for(int j = 0; j < result.cols; j++)
            result.table[i][j] = minor(m, i, j).getDeterminant() * pow(-1, i + j);
    return result;
}

Matrix transposed(const Matrix &m){
    Matrix result(m.cols, m.rows);
    for(int i = 0; i < result.rows; i++)
        for(int j = 0; j < result.cols; j++)
            result.table[i][j] = m.table[j][i];
    return result;
}

MITEM_T MatrixLib::Matrix::getDeterminant() const{
    if(this->rows != this->cols) throw "Wrong matrix for determinant";

    MITEM_T result(0);
    if(this->cols == 1) result = this->table[0][0];
    else{
        for(int i = 0; i < this->rows; i+=2) result += this->table[0][i] * minor(*this, 0, i).getDeterminant();
        for(int i = 1; i < this->rows; i+=2) result -= this->table[0][i] * minor(*this, 0, i).getDeterminant();
    }
    return result;
}

Matrix MatrixLib::Matrix::getInverse() const{
    MITEM_T determinant = getDeterminant();
    if (determinant == 0) throw "The determinant mustn't be zero";

    Matrix transposed = ::transposed(::uni(*this));
    MITEM_T a = 1 / determinant;
    for(int i = 0; i < transposed.rows; i++)
        for(int j = 0; j < transposed.cols; j++)
            transposed.table[i][j] *= a;

    return transposed;
}

Matrix MatrixLib::operator*(const Matrix &a, const Matrix &b){
    if (a.cols != b.rows)
        throw "Invalid matrix size for multiplication";

    Matrix result(a.rows, b.cols);
    for(int i = 0; i < result.rows; i++)
        for(int j = 0; j < result.cols; j++)
            for(int k = 0; k < a.cols; k++)
                result.table[i][j] += a.table[i][k] * b.table[k][j];

    return result;
}

Matrix MatrixLib::operator+(const Matrix &a, const Matrix &b){
    if (a.rows != b.rows || a.cols != b.cols)
        throw "Invalid size";

    Matrix result(a.rows, a.cols);
    for(int i = 0; i < result.rows; i++)
        for(int j = 0; j < result.cols; j++)
            result.table[i][j] = a.table[i][j] + b.table[i][j];

    return result;
}

Matrix MatrixLib::operator-(const Matrix &a, const Matrix &b){
    if (a.rows != b.rows || a.cols != b.cols)
        throw "Invalid size";

    Matrix result(a.rows, a.cols);
    for(int i = 0; i < result.rows; i++)
        for(int j = 0; j < result.cols; j++)
            result.table[i][j] = a.table[i][j] - b.table[i][j];

    return result;
}

std::ostream& MatrixLib::operator<<(std::ostream &out, const Matrix &m){
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.cols; j++) out << m.table[i][j] << '\t';
        out << '\n';
    }

    return out;
}
