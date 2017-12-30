#include "matrix_lib.h"

int main()
{
    try
    {
        MatrixLib::Matrix matrix1(3, 5);
        MatrixLib::Matrix matrix2(5, 3);
        MatrixLib::Matrix matrix3 = matrix1 * matrix2;
        MatrixLib::Matrix matrix4(3, 5);
        MatrixLib::Matrix matrix5 = matrix1 + matrix4;
        MatrixLib::Matrix matrix6(2, 2);

        std::cout << matrix1 << std::endl;
        std::cout << matrix2 << std::endl;
        std::cout << matrix3 << std::endl;
        std::cout << matrix4 << std::endl;
        std::cout << matrix5 << std::endl;
        std::cout << matrix6 << std::endl;
        std::cout << matrix6.getInverse() << std::endl;
        std::cout << matrix6.getDeterminant() << std::endl;
        std::cout << matrix6 * 5 << std::endl;
        std::cout << 5 * matrix6 << std::endl;
        std::cout << matrix6 << std::endl;

        matrix6[0][0] = 20;
        std::cout << matrix6 << std::endl;
    }
    catch (...)
    {

    }

    return 0;
}
