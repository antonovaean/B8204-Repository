#include <iostream>
#include "matrix_lib.h"

using namespace std;

int main() {

    MatrixLib::Matrix m(2, 3);

    cout << m;

    return 0;
}

void foo() {
    /*
    srand( time(NULL) );

    Matrix m1(3, 4);
    Matrix m2(2, 3);

    cout << "m1:" << endl;
    m1.print(cout);
    cout << endl;

    cout << "m2:" << endl;
    m2.print(cout);
    cout << endl;

    cout << "m1 + m2:" << endl;
    try {
        m1.add(m2);
        m1.print(cout);
    } catch (exception& e) {
        cout << "sum exception: " << e.what() << endl;
    }
    cout << endl;

    //int a = 0;

    //cout << "m1 * " << a << ':' << endl;
    //m1.multiply(a);
    //m1.print(cout);
    //cout << endl;

    cout << "m1 * m2:" << endl;
    try {
        Matrix m3 = m1.multiply(m2);
        m3.print(cout);
    } catch (exception& e) {
        cout << "matrix multiply exception: " << e.what() << endl;
    }
    cout << endl;

    try {
        cout << "det(m1): " << m1.det() << endl;

    } catch (exception& e) {
        cout << "det exception: " << e.what() << endl;
    }
    */
}
