#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdbool.h>

void test_swapRows() {
    matrix m = createMatrixFromArray((int []) {1, 4, 5,
                                                  3, 6, 7,
                                                  4, 7, 2}, 3, 3);


    swapRows(&m, 1, 2);

    matrix n = createMatrixFromArray((int []) {1, 4, 5,
                                               4, 7, 2,
                                               3, 6, 7}, 3, 3);

    assert(areTwoMatricesEqual(m, n));
}

void test_swapColumns() {
    matrix m = createMatrixFromArray((int []) {1, 4, 5,
                                                  3, 6, 7,
                                                  4, 7, 2}, 3, 3);

    swapColumns(&m, 0, 2);

    matrix n = createMatrixFromArray((int []) {5, 4, 1,
                                                  7, 6, 3,
                                                  2, 7, 4}, 3, 3);

    assert(areTwoMatricesEqual(m, n));
}

void test_isSquareMatrix() {
    matrix m = createMatrixFromArray((int []) {1, 4, 5,
                                                  3, 6, 7,
                                                  4, 7, 2}, 3, 3);

    assert(isSquareMatrix(m));
}

void test_twoMatricesEqual() {
    matrix m = createMatrixFromArray((int []) {1, 4, 5,
                                               3, 6, 7,
                                               4, 7, 2}, 3, 3);
    matrix n = createMatrixFromArray((int []) {1, 4, 5,
                                               3, 6, 7,
                                               4, 7, 2}, 3, 3);
    assert(areTwoMatricesEqual(m, n));
}

void test_isEMatrix_matrixIsE() {
    matrix m = createMatrixFromArray((int []) {1, 0, 0,
                                               0, 1, 0,
                                               0, 0, 1}, 3, 3);

    assert(isEMatrix(m));
}

void test_isEMatrix_matrixIsNotE() {
    matrix m = createMatrixFromArray((int []) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    assert(!isEMatrix(m));
}

void test_isEMatrix_matrixIsNotSquare() {
    matrix m = createMatrixFromArray((int []) {1, 0, 0,
                                               0, 1, 0}, 2, 3);

    assert(!isEMatrix(m));
}

void test_isEMatrix() {
    test_isEMatrix_matrixIsE();
    test_isEMatrix_matrixIsNotE();
    test_isEMatrix_matrixIsNotSquare();
}

void test_isSymmetricMatrix_matrixIsSymmetric() {
    matrix m = createMatrixFromArray((int []) {1, 2, 3,
                                               2, 5, 6,
                                               3, 6, 7}, 3, 3);

    assert(isSymmetricMatrix(m));
}

void test_isSymmetricMatrix_matrixIsNotSymmetric() {
    matrix m = createMatrixFromArray((int []) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    assert(!isSymmetricMatrix(m));
}

void test_isSymmetricMatrix_matrixIsNotSquare() {
    matrix m = createMatrixFromArray((int []) {1, 2, 3,
                                               4, 5, 6}, 2, 3);

    assert(!isSymmetricMatrix(m));
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_matrixIsSymmetric();
    test_isSymmetricMatrix_matrixIsNotSymmetric();
    test_isSymmetricMatrix_matrixIsNotSquare();
}

void test_transposeSquareMatrix_matrixIsSquare() {
    matrix m = createMatrixFromArray((int []) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix n = createMatrixFromArray((int []) {1, 4, 7,
                                                  2, 5, 8,
                                                  3, 6, 9}, 3, 3);
    transposeSquareMatrix(&m);

    assert(areTwoMatricesEqual(m, n));
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_matrixIsSquare();
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray((int []) {8, 2, 3,
                                               4, 3, 0,
                                               5, 8, 9}, 3, 3);
    position min = getMinValuePos(m);

    position expectation = {1, 2};

    assert(twoPositionIsEqual(min, expectation));
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray((int []) {8, 2, 3,
                                               4, 3, 0,
                                               5, 13, 5}, 3, 3);
    position max = getMaxValuePos(m);

    position expectation = {2, 1};

    assert(twoPositionIsEqual(max, expectation));
}

void test_firstPart() {
    test_swapRows();
    test_swapColumns();
    test_isSquareMatrix();
    test_twoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}


//1
//Дана квадратная матрица, все элементы которой различны. Поменять местами
//строки, в которых находятся максимальный и минимальный элементы
void swapRowsWithMinAndMaxElement(matrix *m) {
    position min = getMinValuePos(*m);
    position max = getMaxValuePos(*m);

    swapRows(m, min.rowIndex, max.rowIndex);
}

void test_secondPart_firstTask() {
    matrix m = createMatrixFromArray((int []) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);

    swapRowsWithMinAndMaxElement(&m);

    matrix expectation = createMatrixFromArray((int []) {7, 8, 9,
                                               4, 5, 6,
                                               1, 2, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));
}

void test_secondPart() {
    test_secondPart_firstTask();
}

int main() {
    test_firstPart();
    test_secondPart();

    return 0;
}