#include "Translit.h"
#include <conio.h>


int main()
{
	// кодировочные таблиц
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	setlocale(0, "Russian");

	char str[255];

	cout << "¬вод:" << endl;

	cin.getline(str, 255);

	cout << "ѕеревод:" << endl;

	translit(str);

	_getch();
	return 0;
}