// main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	int num;
	cin >> num;
	cout << Fib(num);
	system("pause");
    return 0;
}

