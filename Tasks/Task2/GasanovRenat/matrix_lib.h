#include "stdafx.h"

struct Matrix
{
	int n;
	int m;
	double** Mass;
};

Matrix Create_rand(int n, int m);//метод заполнения матрицы
Matrix Create(int n, int m);//метод заполнения размерности матрицы 
long double determ(Matrix Matr);//метод нахождения определителя
Matrix Summ(Matrix Matr1, Matrix Matr2);//метод нахождения суммы матрицы
Matrix MultipleByANumber(Matrix Matr1, double a);//метод умножения матрицы на число
Matrix Multiple(Matrix Matr1, Matrix Matr2);//метод нахождения умножения матрицы
Matrix Inverse(Matrix Matr1);//метод нахождения обратной матрицы
void Print_Matrix(Matrix matr); //печать матрицы