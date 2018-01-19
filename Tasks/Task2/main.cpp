#include <iostream>
#include "matrix_lib.h"

int main() {
    try {
        MatrixLib::Matrix matrix1(2, 2);
        MatrixLib::Matrix matrix2(2, 2);
        MatrixLib::Matrix matrixSum = matrix1 + matrix2;
        MatrixLib::Matrix matrix3(3, 4);
        MatrixLib::Matrix matrix4(5, 4);
        MatrixLib::Matrix matrixMul = matrix3 * matrix4;

        std::cout << matrix1 << std::endl;
        std::cout << matrixSum << std::endl;
        std::cout << matrix3 << std::endl;
        std::cout << matrix4 << std::endl;
        std::cout << matrixMul << std::endl;
        std::cout << matrixMul.getInverse() << std::endl;
        std::cout << matrixSum.getInverse() << std::endl;
        std::cout << 4 * matrix3 << std::endl;
        std::cout << matrix3 << std::endl;

        matrix3[0][0] = 4;
        std::cout << matrix3 << std::endl;

    } catch (std::logic_error) { /*TODO(Achtung: ошибка) */
        std::cout << "Logic error!";
    } catch (std::invalid_argument) {
        std::cout << "Logic error!";
    } catch (...) {

    }
    return 0;
}