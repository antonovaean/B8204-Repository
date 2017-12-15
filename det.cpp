#include "header.h"


double find(double **x, int m) 
{
	if (m == 2)
	{
		return (x[0][0] * x[1][1] - x[0][1] * x[1][0]);
	}
	else if (m == 1)
	{
		return x[0][0];
	}
	else if (m >= 3) /* сумма первого элемента первой строки умноженного на (-1)* в степени позиции этого элемента и умноженного на определитель минора матрицы,
					 + значение 2 элемента первой строки умноженного на (-1)* в степени позиции этого элемента и умноженного на определитель минора матрицы,
					 + значение 3 элемента первой строки умноженного на (-1)* в степени позиции этого элемента и умноженного на определитель минора матрицы
					 */
	{
		double **t = new double*[m - 1];
		for (int i = 0; i < m - 1; i++)
		{
			t[i] = new double[m - 1]; // Создаем элементы
		}
		double _det = 0;
		int y, b;
		for (int j = 0; j<m; j++) {
			y = 0;
			for (int k = 1; k < m; k++) {
				b = 0;
				for (int s = 0; s<m; s++)
					if (s != j) {
						t[y][b] = x[k][s];
						b++;
					}
				y++;
			}
			_det += pow(-1, (double)j + 2)*x[0][j] * find(t, m - 1);
		}
		return _det;
	}



	return 0;
}
char sumMatr(double**x, int m)
{
	//создадим вторую матрицу
	srand(time(NULL));
	int g = 0;
	cin >> g;
	double **h = new double*[g];
	for (int i = 0; i < g; i++)
	{
		h[i] = new double[g];
	}
	for (int i = 0; i < g; i++)
	{
		for (int j = 0; j < g; j++)
		{
			h[i][j] = rand() % 10;
			cout << h[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	if (g = m) {
		double **_sum = new double*[g];
		for (int i = 0; i < g; i++)
		{
			_sum[i] = new double[g];
		}
		for (int i = 0; i < g; i++)
		{
			for (int j = 0; j < g; j++)
			{
				_sum[i][j] = h[i][j] + x[i][j];
			}
		}
		cout << "Sum Matrix = " << endl;
		for (int i = 0; i < g; i++)
		{
			for (int j = 0; j < g; j++)
			{
			cout << _sum[i][j] << " ";
			}
			cout << endl;
		}


	}
	return 0;
}

int main()
{
	srand(time(NULL)); // Инициализируем генератор случайных чисел. 
	int n = 0;
	cin >> n; // Считываем с клавиатуры n
	double **a = new double*[n]; // Создаем массив указателей
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n]; // Создаем элементы
	}
	// А дальше работа как с обычным массивом. 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10; // Каждый элемент случайному числу от 0 до 9
			cout << a[i][j] << " "; // Вывести элементы на консольку
		}
		cout << endl; // Двумерный массив. Строка кончилась, переводим строку и на консоли
	}
	cout << "Determinant = " << find(a, n);
	cout << "" << sumMatr(a, n);
	_getch();
	return 0;
}