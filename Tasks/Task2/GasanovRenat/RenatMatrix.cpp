#include "stdafx.h"
#include "matrix_lib.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	Matrix Matr1, Matr2, matr_rez;

	cout << "Enter the dimension of the first matrix\n";
	cin >> Matr1.n >> Matr1.m;
	Matr1 = Create_rand(Matr1.n, Matr1.m);
	Print_Matrix(Matr1);

	if (Matr1.n == Matr1.m) {
		cout << "Determinant Matr1 = ";
		cout << determ(Matr1) << endl;

		cout << "Inverse Matr1:\n";
		matr_rez = Inverse(Matr1);
		Print_Matrix(matr_rez);
		
		delete[] matr_rez.Mass;
		cout << endl;
	}

	cout << "Enter the dimension of the second matrix\n";
	cin >> Matr2.n >> Matr2.m;
	Matr2 = Create_rand(Matr2.n, Matr2.m);
	Print_Matrix(Matr2);

	if (Matr2.n == Matr2.m) {
		cout << "Determinant Matr2 = ";
		cout << determ(Matr2) << endl;

		cout << "Inverse Matr2:\n";
		matr_rez = Inverse(Matr2);
		Print_Matrix(matr_rez);

		delete[] matr_rez.Mass;
		cout << endl;
		cout << endl;
	}

	if ((Matr1.n == Matr2.n) & (Matr1.m == Matr2.m)) {
		matr_rez = Summ(Matr1, Matr2);
		cout << "Matr1 + Matr2:\n";
		Print_Matrix(matr_rez);
		delete[] matr_rez.Mass;
	}


	if (Matr1.m == Matr2.n) {
		matr_rez = Multiple(Matr1, Matr2);
		cout << "Matr1 * Matr2:\n";
		Print_Matrix(matr_rez);
		delete[] matr_rez.Mass;
	}

	double number;
	cout << "Enter number\n";
	cin >> number;
	cout << number << " * matr1\n";
	Print_Matrix(MultipleByANumber(Matr1, number));

	delete[]  Matr1.Mass; delete[]  Matr2.Mass;

	system("pause");
	return 0;
}