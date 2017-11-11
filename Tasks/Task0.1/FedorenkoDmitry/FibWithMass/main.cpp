#include <iostream>
#include "Fib.h"

using namespace std;

int main() {
    const int m = 30;
    int n;
    setlocale(LC_ALL,"rus");
    cout << "Введите порядковый номер числа Фибоначчи (Не больше 30)" << endl;
    cin >> n;
    if (n > m) cout << "Введённый номер больше 30";
    else  cout << "Число Фибоначчи по номером: " << n << " = " << getFib(n);
    return 0;
}