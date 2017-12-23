#include <iostream>
#include <ctime>
#include "matrix_lib.h"

using namespace std;

float getRandomNumber(float a, float b);
void initMatrixWithRandomValues(MatrixLib::Matrix &m, MatrixLib::MITEM_T from, MatrixLib::MITEM_T to);

int main() {

    srand( time(NULL) );

    MatrixLib::Matrix m1(3, 3);
    MatrixLib::Matrix m2(3, 3);

    initMatrixWithRandomValues(m1, 0.001, 9.999);
    initMatrixWithRandomValues(m2, 0.001, 9.999);

    cout << "m1:" << endl << m1 << endl;
    cout << "m2:" << endl << m2 << endl;


    cout << "determinant of m1: ";
    try {
        cout << m1.getDeterminant() << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << endl;


    MatrixLib::MITEM_T lambda = 10;
    cout << MatrixLib::getMultiplicationOfMatrixAndScalar(m1, lambda) << endl;


    cout << "m1 + m2:" << endl;
    try {
        cout << MatrixLib::getSumOfMatrices(m1, m2) << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }


    cout << "m1 - m2:" << endl;
    try {
        cout << MatrixLib::getDifferenceOfMatrices(m1, m2) << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }


    cout << "m1 * m2" << endl;
    try {
        cout << getMultiplicationOfMatrices(m1, m2) << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}

float getRandomNumber(float a, float b) {
    // return random number from a to b inclusive

    return a + static_cast<float>(rand()) / (static_cast<float>( RAND_MAX / (b - a) ));
}

void initMatrixWithRandomValues(MatrixLib::Matrix &m, MatrixLib::MITEM_T from, MatrixLib::MITEM_T to) {
    for (MatrixLib::MSIZE_T i = 0; i < m.m; i++) {
        for (MatrixLib::MSIZE_T j = 0; j < m.n; j++) {
            m[i][j] = getRandomNumber(from, to);
        }
    }
}
