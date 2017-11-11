#include <iostream>
#include "fib_arr.h"

using namespace std;

int main() {

    for (int i = 1; i <= FIB_MAX_N; i++)
        cout << fib(i) << endl;

    return 0;
}
