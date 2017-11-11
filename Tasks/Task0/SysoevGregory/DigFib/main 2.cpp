// main.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "DigFib.h"

using namespace std;

int main() {
	int n;
	setlocale(LC_ALL, "rus");
	cout << "Введите порядковый номер числа фибоначи, которое вы хотите найти" << endl;
	cin >> n;
	cout << "Число фибоначи под номером " << n << " = " << DigFib(n);
	return 0;
}

