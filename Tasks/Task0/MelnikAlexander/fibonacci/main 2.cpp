#include <iostream>
#include "fib.h"

using namespace std;

int main() {

    for (int i = 1; i <= 10; i++)
        cout << fib(i) << ' ';
    cout << endl;

    return 0;
}
