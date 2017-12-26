#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <stdexcept>


class Matrix
{
    private:
        int rows;
        int columns;

        void setToZero()
        {
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->columns; j++)
                    this->matrix[i][j] = 0;
        }

        Matrix uni()
        {
            Matrix result(this->rows, this->columns);
            for(int i = 0; i < result.getRows(); i++)
                for(int j = 0; j < result.getColumns(); j++)
                    result.matrix[i][j] = this->getMinor(i, j).getDet() * pow(-1, i + j);
            return result;
        }

        Matrix getTransposed()
        {
            Matrix result(this->columns, this->rows);
            for(int i = 0; i < result.getRows(); i++)
                for(int j = 0; j < result.getColumns(); j++)
                    result.matrix[i][j] = this->matrix[j][i];
            return result;
        }

    public:
        float **matrix;

        Matrix(int rows, int columns)
        {
            if (rows <= 0 || columns <= 0) throw std::invalid_argument("Must more 0");
            this->rows = rows;
            this->columns = columns;
            this->matrix = new float*[this->rows];
            for (int i = 0; i < this->rows; i++) this->matrix[i] = new float[this->columns];
            setToZero();
        }

        Matrix(int size)
        {
            if (size <= 0) throw std::invalid_argument("Must more 0");
            this->rows = size;
            this->columns = size;
            this->matrix = new float*[this->rows];
            for (int i = 0; i < this->rows; i++) this->matrix[i] = new float[this->columns];
            setToZero();
        }

        void addition(Matrix matrix)
        {
            if (matrix.getRows() != this->getRows() || matrix.getColumns() != this->getColumns())
                throw std::invalid_argument("Invalid size");

            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->columns; j++)
                    this->matrix[i][j] += matrix.matrix[i][j];
        }

        static Matrix multiplication(Matrix a, Matrix b)
        {
            if (a.getColumns() != b.getRows())
                throw std::invalid_argument("The number of columns of the first matrix should be equal to the number of rows of the second matrix");

            Matrix result(a.getRows(), b.getColumns());
            for(int i = 0; i < result.getRows(); i++)
                for(int j = 0; j < result.getColumns(); j++)
                    for(int k = 0; k < a.getColumns(); k++)
                        result.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];

            return result;
        }

        //Не стал рассматривать случай, когда число не помещается в float
        void multiplication(float a)
        {
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->columns; j++)
                    this->matrix[i][j] *= a;
        }

        Matrix getMinor(int l, int k)
        {
            if((l > this->rows - 1)||(k > this->columns - 1)) throw -1;

            Matrix result(this->rows - 1, this->columns - 1);
            for(int i = 0; i < l; i++)
            {
                for(int j = 0; j < k; j++) result.matrix[i][j] = this->matrix[i][j];
                for(int j = k + 1; j < this->columns; j++) result.matrix[i][j-1] = this->matrix[i][j];
            }

            for(int i = l + 1; i < this->rows; i++)
            {
                for(int j = 0; j < k; j++) result.matrix[i-1][j] = this->matrix[i][j];
                for(int j = k + 1; j < this->columns; j++) result.matrix[i-1][j-1] = this->matrix[i][j];
            }
            return result;
        }

        Matrix getInvert()
        {
            if(getDet() == 0) throw -1;
            Matrix result = uni().getTransposed();
            result.multiplication(1 / getDet());
            return result;
        }

        float getDet()
        {
            if(this->rows != this->columns) throw -1;

            float result(0);
            if(this->columns != 1)
            {
                for(int i = 0; i < this->rows; i+=2) result += this->matrix[0][i] * this->getMinor(0, i).getDet();
                for(int i = 1; i < this->rows; i+=2) result -= this->matrix[0][i] * this->getMinor(0, i).getDet();
            }
            else result = this->matrix[0][0];
            return result;
        }

        int getRows()
        {
            return this->rows;
        }

        int getColumns()
        {
            return this->columns;
        }

        static void print(Matrix matrix)
        {
            for(int i = 0; i < matrix.getRows(); i++)
            {
                for(int j = 0; j < matrix.getColumns(); j++) printf("%+.01f\t", matrix.matrix[i][j]);
                printf("\n");
            }
            printf("\n\n");
        }
};

Matrix operator + (Matrix &a, Matrix &b)
{
    if (a.getRows() != b.getRows() || a.getColumns() != b.getColumns())
        throw std::invalid_argument("Invalid size");

    Matrix result(a.getRows(), a.getColumns());
    for (int i = 0; i < result.getRows(); i++)
        for (int j = 0; j < result.getColumns(); j++)
            result.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];

    return result;
}

Matrix operator * (Matrix &a, Matrix &b)
{
    Matrix result = Matrix::multiplication(a, b);
    return result;
}

Matrix operator * (Matrix &a, float number)
{
    Matrix result(a.getRows(), a.getColumns());

    for(int i = 0; i < result.getRows(); i++)
        for(int j = 0; j < result.getColumns(); j++)
            result.matrix[i][j] = a.matrix[i][j] * number;

    return result;
}

void fillMatrix(Matrix matrix)
{
    srand(time(NULL));
    for(int i = 0; i < matrix.getRows(); i++)
        for(int j = 0; j < matrix.getColumns(); j++)
            matrix.matrix[i][j] = matrix.getRows() + rand() % (2 * matrix.getColumns());
}

int main()
{
    Matrix a(3, 2);
    Matrix b(3, 2);
    Matrix c(2, 4);

    fillMatrix(a);
    fillMatrix(b);
    fillMatrix(c);

    Matrix::print(a);
    Matrix::print(b);
    Matrix::print(c);

    Matrix::print(a + b);
    Matrix::print(a * c);
    Matrix::print(a * 5);

    return 0;
}
