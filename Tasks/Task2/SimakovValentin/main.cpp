#include "matrix_lib.h"

using namespace MatrixLib;
using namespace std;

int main(){
    try{
        Matrix A(3, 2);
        Matrix B(2, 3);

        A.fill(1, 10);
        B.fill(1, 10);

        cout << A << endl;
        cout << B << endl;
        cout << A*B << endl;

        Matrix C(3, 3);
        C.fill(1, 10);
        cout << C.getInverse() << endl;
        cout << C.getDeterminant() << endl;
    }
    catch (...){}

    return 0;
}
