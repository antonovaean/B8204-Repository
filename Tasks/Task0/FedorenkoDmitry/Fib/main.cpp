#include <iostream>
#include "Fib.h"

using namespace std;

int main() {
    int n;
    setlocale(LC_ALL, "rus");
    cout << "Введите порядковый номер числа фибоначи, которое вы хотите найти" << endl;
    cin >> n;
    cout << "Число фибоначи под номером " << n << " = " << getFib(n);
    return 0;
}