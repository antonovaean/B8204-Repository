#include "Translit.h"
#include <conio.h>


int main()
{
	// ������������ ������
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	setlocale(0, "Russian");

	char str[255];

	cout << "����:" << endl;

	cin.getline(str, 255);

	cout << "�������:" << endl;

	translit(str);

	_getch();
	return 0;
}