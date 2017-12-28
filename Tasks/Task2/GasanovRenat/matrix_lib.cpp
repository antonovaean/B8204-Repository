#include "stdafx.h"
#include "matrix_lib.h"
#include <iostream>
using namespace std;

Matrix Create(int n, int m) {
	Matrix Matr;
	Matr.Mass = new double *[n];

	for (int i = 0; i < n; i++)
		Matr.Mass[i] = new double[m];

	Matr.n = n;
	Matr.m = m;

	return (Matr);
}

Matrix Create_rand(int n, int m) { //заполнение матрицы случайными числами
	Matrix Matr = Create(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Matr.Mass[i][j] = ((rand() % 51 - 10));

	return (Matr);
}

Matrix minor(Matrix matr, int l, int k) { //нахождение минора
	if ((l > matr.n - 1) || (k > matr.m - 1)) throw - 1;
	else {
		Matrix result = Create(matr.n - 1, matr.m - 1);
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < k; j++)
				result.Mass[i][j] = matr.Mass[i][j];
			for (int j = k + 1; j < matr.m; j++)
				result.Mass[i][j - 1] = matr.Mass[i][j];
		}
		for (int i = l + 1; i < matr.n; i++) {
			for (int j = 0; j < k; j++)
				result.Mass[i - 1][j] = matr.Mass[i][j];
			for (int j = k + 1; j < matr.m; j++)
				result.Mass[i - 1][j - 1] = matr.Mass[i][j];
		}
		return result;
	}
}

long double determ(Matrix matr) { //нахождение определителя матрицы по теореме Лапласа
	if (matr.m != 1) {
		int result(0);
		for (int i = 0; i < matr.n; i += 2)
			result += matr.Mass[0][i] * determ(minor(matr, 0, i));
		for (int i = 1; i < matr.n; i += 2)
			result -= matr.Mass[0][i] * determ(minor(matr, 0, i));
		return result;
	}
	else return matr.Mass[0][0];
}

Matrix Multiple(Matrix Matr1, Matrix Matr2) { //умножение матриц
	Matrix Matr = Create(Matr1.n, Matr2.m);

	for (int i = 0; i < Matr.n; i++) {
		for (int j = 0; j < Matr.m; j++) {

			int summ = 0;
			for (int c = 0; c < Matr.m; c++)
				summ += Matr1.Mass[i][c] * Matr2.Mass[c][j];
			Matr.Mass[i][j] = summ;
		}
	}

	return (Matr);
}

Matrix Summ(Matrix Matr1, Matrix Matr2) { //сумма двух матриц
	Matrix Matr = Create(Matr2.n, Matr2.m);

	for (int i = 0; i < Matr.m; i++)
		for (int j = 0; j < Matr.n; j++)
			Matr.Mass[i][j] = Matr1.Mass[i][j] + Matr2.Mass[i][j];

	return (Matr);
}

Matrix MultipleByANumber(Matrix Matr1, double a) { //умножение матрицы на число
	Matrix Matr = Create(Matr1.n, Matr1.m);

	for (int i = 0; i < Matr.n; i++)
		for (int j = 0; j < Matr.m; j++)

			Matr.Mass[i][j] = Matr1.Mass[i][j] * a;

	return Matr;
}

Matrix Transpose(Matrix Matr1) { //нахождение транспонированной матрицы
	Matrix rez_matr = Create(Matr1.n, Matr1.m);
	for (int i = 0; i < rez_matr.n; i++)
		for (int j = 0; j < rez_matr.m; j++)
			rez_matr.Mass[i][j] = Matr1.Mass[j][i];

	return rez_matr;
}

Matrix ConnectedMatrix(Matrix matr) { //нахождение связной матрицы
	Matrix result = Create(matr.n, matr.m);
	for (int i = 0; i < result.n; i++)
		for (int j = 0; j < result.m; j++)
			result.Mass[i][j] = determ(minor(matr,i, j)) * pow(-1, i + j);
	return result;
}

Matrix Inverse(Matrix Matr1) { //нахождение обратной матрицы
	Matrix matr = Create(Matr1.n, Matr1.n);
	long double det = determ(Matr1);
	matr = MultipleByANumber(Transpose(ConnectedMatrix(Matr1)), abs(1 / det));
	return matr;
}

void Print_Matrix(Matrix matr)
{
	for (int i = 0; i<matr.n; ++i)
	{

		for (int j = 0; j<matr.m; ++j)
		{
			printf("%6.4f  ", matr.Mass[i][j]);
		}
		cout << '\n';
	}
}