#include <iostream>
#include "matrix_lib.hpp"

using namespace std;

int getRandomNumber(int, int);
double getRandomNumber(double a, double b);

template <typename T, class Type>
void initMatrixWithRandomValues(MatrixLib::Matrix<Type> &m, T from, T to);

int main() {

    srand( time(NULL) );

    MatrixLib::Matrix<int> m1(3, 3);
    MatrixLib::Matrix<int> m2(3, 3);

    initMatrixWithRandomValues(m1, -10, 10);
    initMatrixWithRandomValues(m2, -10, 10);

    cout << "m1:" << endl << m1 << endl;
    cout << "m2:" << endl << m2 << endl;


    cout << "determinant of m1: ";
    try {
        cout << m1.getDeterminant() << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << endl;


    int lambda = 10;
    cout << "m1 * lambda: " << endl;
    cout << m1 * lambda << endl;


    cout << "m1 + m2:" << endl;
    try {
        cout << m1 + m2;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << endl;


    cout << "m1 - m2:" << endl;
    try {
        cout << m1 - m2;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << endl;


    cout << "m1 * m2" << endl;
    try {
        cout << m1 * m2;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << endl;


    cout << "inverse of m1:" << endl;
    try {
        cout << m1.getInverse();
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << endl;


    cout << "m1 * m1.getInverse():" << endl;
    try {
        cout << m1 * m1.getInverse();
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << endl;

    return 0;
}

int getRandomNumber(int a, int b) {
    // return random number from a to b inclusive

    return rand() % (b - a + 1) + a;
}

double getRandomNumber(double a, double b) {
    // return random number from a to b inclusive

    return a + static_cast<double>(rand()) / (RAND_MAX / (b - a));
}

template <typename T, class Type>
void initMatrixWithRandomValues(MatrixLib::Matrix<Type> &m, T from, T to) {
    for (MatrixLib::MSIZE_T i = 0; i < m.m; i++) {
        for (MatrixLib::MSIZE_T j = 0; j < m.n; j++) {
            m[i][j] = getRandomNumber(from, to);
        }
    }
}
