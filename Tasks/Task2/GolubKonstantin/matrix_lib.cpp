#include <stdio.h>
#include <math.h>
#include <ctime>

#include "matrix_lib.h"

using namespace MatrixLib;

MatrixLib::Matrix::Matrix(const Matrix &matrix)
{
    this->rows = matrix.rows;
    this->columns = matrix.columns;
    this->matrix = new float*[this->rows];
    for (int i = 0; i < this->rows; i++) this->matrix[i] = new float[this->columns];

    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->columns; j++)
            this->matrix[i][j] = matrix.matrix[i][j];
}

MatrixLib::Matrix::Matrix(MSIZE_T rows, MSIZE_T columns) throw(std::invalid_argument)
{
    if (rows <= 0 || columns <= 0) throw std::invalid_argument("The rows and columns must be more 0");
    this->rows = rows;
    this->columns = columns;
    this->matrix = new float*[this->rows];
    for (int i = 0; i < this->rows; i++) this->matrix[i] = new float[this->columns];

    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->columns; j++)
            this->matrix[i][j] = 0;
}

MatrixLib::Matrix::~Matrix()
{
    for(int i = 0; i < this->rows; i++)
            delete(matrix[i]);
    delete[] matrix;

}

MITEM_T* MatrixLib::Matrix::operator[](const MSIZE_T &a) const
{
    return this->matrix[a];
}

Matrix minor(const Matrix &matrix, int l, int k) throw(std::logic_error)
{
    if((l > matrix.rows - 1)||(k > matrix.columns - 1)) throw std::logic_error("The minor doesn't exist");

    Matrix result(matrix.rows - 1, matrix.columns - 1);
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < k; j++) result.matrix[i][j] = matrix.matrix[i][j];
        for(int j = k + 1; j < matrix.columns; j++) result.matrix[i][j-1] = matrix.matrix[i][j];
    }

    for(int i = l + 1; i < matrix.rows; i++)
    {
        for(int j = 0; j < k; j++) result.matrix[i-1][j] = matrix.matrix[i][j];
        for(int j = k + 1; j < matrix.columns; j++) result.matrix[i-1][j-1] = matrix.matrix[i][j];
    }
    return result;
}

Matrix uni(const Matrix &matrix) throw(std::logic_error)
{
    Matrix result(matrix.rows, matrix.columns);
    for(int i = 0; i < result.rows; i++)
        for(int j = 0; j < result.columns; j++)
            result.matrix[i][j] = minor(matrix, i, j).getDeterminant() * pow(-1, i + j);
    return result;
}

Matrix transposed(const Matrix &matrix)
{
    Matrix result(matrix.columns, matrix.rows);
    for(int i = 0; i < result.rows; i++)
        for(int j = 0; j < result.columns; j++)
            result.matrix[i][j] = matrix.matrix[j][i];
    return result;
}

MITEM_T MatrixLib::Matrix::getDeterminant() const throw(std::logic_error)
{
    if(this->rows != this->columns) throw std::logic_error("The rows and columns must match");

    MITEM_T result(0);
    if(this->columns == 1) result = this->matrix[0][0];
    else
    {
        for(int i = 0; i < this->rows; i+=2) result += this->matrix[0][i] * minor(*this, 0, i).getDeterminant();
        for(int i = 1; i < this->rows; i+=2) result -= this->matrix[0][i] * minor(*this, 0, i).getDeterminant();
    }
    return result;
}

Matrix MatrixLib::Matrix::getInverse() const throw(std::logic_error)
{
    MITEM_T determinant = getDeterminant();
    if (determinant == 0) throw std::logic_error("The determinant mustn't be zero");

    Matrix transposed = ::transposed(::uni(*this));
    MITEM_T a = 1 / determinant;
    for(int i = 0; i < transposed.rows; i++)
        for(int j = 0; j < transposed.columns; j++)
            transposed.matrix[i][j] *= a;

    return transposed;
}

Matrix MatrixLib::operator*(const Matrix &a, const Matrix &b) throw(std::invalid_argument)
{
    if (a.columns != b.rows)
        throw std::invalid_argument("The number of columns of the first matrix should be equal to the number of rows of the second matrix");

    Matrix result(a.rows, b.columns);
    for(int i = 0; i < result.rows; i++)
        for(int j = 0; j < result.columns; j++)
            for(int k = 0; k < a.columns; k++)
                result.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];

    return result;
}

Matrix MatrixLib::operator+(const Matrix &a, const Matrix &b) throw(std::invalid_argument)
{
    if (a.rows != b.rows || a.columns != b.columns)
        throw std::invalid_argument("Invalid size");

    Matrix result(a.rows, a.columns);
    for(int i = 0; i < result.rows; i++)
        for(int j = 0; j < result.columns; j++)
            result.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];

    return result;
}

Matrix MatrixLib::operator-(const Matrix &a, const Matrix &b) throw(std::invalid_argument)
{
    if (a.rows != b.rows || a.columns != b.columns)
        throw std::invalid_argument("Invalid size");

    Matrix result(a.rows, a.columns);
    for(int i = 0; i < result.rows; i++)
        for(int j = 0; j < result.columns; j++)
            result.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];

    return result;
}

std::ostream& MatrixLib::operator<<(std::ostream &out, const Matrix &matrix)
{
    for(int i = 0; i < matrix.rows; i++)
    {
        for(int j = 0; j < matrix.columns; j++) out << matrix.matrix[i][j] << ' ';
        out << '\n';
    }

    return out;
}