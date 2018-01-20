#include "matrix_lib.h"

void printMatrix(int* matrix, int n, int m)
{
	for (int i = 0; i < n; i++) // по строкам 
	{
		for (int j = 0; j < m; j++) // по столбцам
			cout << *(matrix + i*n + j) << ' '; // указатель на матрицу(записываем каждый эл)
		cout << endl;
	}
	return;
}

bool sumMatrix(int* firstMatrix, int n1, int m1, int* secondMatrix, int n2, int m2,int* resultMatrix)
{
	if ((n1 == n2) && (m1 == m2)) //если они одной размерности
	{
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m1; j++)
				*(resultMatrix + i*n1 + j) = *(firstMatrix + i*n1 + j) + *(secondMatrix + i*n1 + j); //формула для суммы матриц
		return true;
	}
	else
		return false;
}

bool multiMatrix(int* firstMatrix, int n1, int m1, int* secondMatrix, int n2, int m2, int* resultMatrix)
{
	if (m1 == n2)
	{
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m2; j++)
				*(resultMatrix + i*n1 + j) = 0; //обнуляем матрицу
		// умножение
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m2; j++)
				for (int k = 0; k < m1; k++) //цикл для суммы
					*(resultMatrix + i*n1 + j) += *(firstMatrix + i*n1 + k) * *(secondMatrix + k*m1 + j);//формула для перемножения
		return true;
	}
	else
		return false;
}

void alphaMultiMatrix(int* matrix, int n, int m, int number, int *resultMatrix)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			*(resultMatrix + i*n + j) = *(matrix + i*n + j) * number; 
	return;
}
//
//int detMatrix(int* matrix, int n, int m)
//{
//	if (n == m)
//	{
//		int det = 0;
//		int degree = 1; // (-1)^(1+j) из формулы определителя
//
//		if (n == 1)
//			return *matrix;
//		if (n == 2)
//			return *matrix * *(matrix + n + 1) - *(matrix + 1) * *(matrix + n);
//		else
//		{
//			//Матрица без строки и столбца
//			int **newMatrix = new int*[n - 1];
//			for (int i = 0; i < n - 1; i++) 
//				newMatrix[i] = new int[n - 1];
//
//
//		}
//	}
//	else
//	{
//		cout << "Матрица не является квадратной";
//		return -1;
//	}
//}