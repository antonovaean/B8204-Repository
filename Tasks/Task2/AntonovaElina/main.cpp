#include "matrix_lib.h"
#include <conio.h> 
#include <time.h>

int main()
{
	srand(time(NULL)); //��������� 
	setlocale(LC_ALL, "rus"); 

	const int N = 5, M = 4;
	int A[N][M];
	int B[N][M];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}

	
	printMatrix(*A, N, M);// ������
	cout << endl;
	printMatrix(*B, N, M);
	cout << endl;

	int sum[N][M];// �����
	
	if (sumMatrix(*A, N, M, *B, N, M, *sum))
		printMatrix(*sum, N, M);
	else
		cout << "������ ��������������, ������� ���������� �����������!";
	cout << endl;

	int multiply[N][M];// ���������
	
	if (multiMatrix(*A, N, M, *B, N, M, *multiply))
		printMatrix(*multiply, N, M);
	else
		cout << "������ �����������,������� ���������� �����������! ";
	cout << endl;

	int alphaMultiply[N][M];// ��������� �� �����
	int alpha = 7;
	
	alphaMultiMatrix(*A, N, M,alpha, *alphaMultiply);
	printMatrix(*alphaMultiply, N, M);



	_getch();
	return 0;
}