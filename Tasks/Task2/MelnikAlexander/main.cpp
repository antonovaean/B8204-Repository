#include <iostream>
#include "matrix_lib.h"

using namespace std;
using MatrixLib::operator*;
using MatrixLib::operator+;
using MatrixLib::operator-;


float getRandomNumber(float a, float b);
void initMatrixWithRandomValues(MatrixLib::Matrix &m, MatrixLib::MITEM_T from, MatrixLib::MITEM_T to);

int main() {

    srand( time(NULL) );

    MatrixLib::Matrix m(2, 3);

    initMatrixWithRandomValues(m, 0.001, 9.999);

    cout << m << endl;

    try {
        cout << m.getDeterminant() << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    cout << 0.0001 * m << endl;

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
