#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/array/array.h"
#include <assert.h>
#include <stdbool.h>

void test_swapRows() {
    matrix m1 = createMatrixFromArray((int[]) {1, 4, 5,
                                               3, 6, 7,
                                               4, 7, 2}, 3, 3);


    swapRows(m1, 1, 2);

    matrix m2 = createMatrixFromArray((int[]) {1, 4, 5,
                                               4, 7, 2,
                                               3, 6, 7}, 3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapColumns() {
    matrix m1 = createMatrixFromArray((int[]) {1, 4, 5,
                                               3, 6, 7,
                                               4, 7, 2}, 3, 3);

    swapColumns(m1, 0, 2);

    matrix m2 = createMatrixFromArray((int[]) {5, 4, 1,
                                               7, 6, 3,
                                               2, 7, 4}, 3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 5,
                                              3, 6, 7,
                                              4, 7, 2}, 3, 3);

    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_twoMatricesEqual() {
    matrix m1 = createMatrixFromArray((int[]) {1, 4, 5,
                                               3, 6, 7,
                                               4, 7, 2}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 4, 5,
                                               3, 6, 7,
                                               4, 7, 2}, 3, 3);
    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isEMatrix_matrixIsE() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_matrixIsNotE() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_matrixIsNotSquare() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0}, 2, 3);

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix() {
    test_isEMatrix_matrixIsE();
    test_isEMatrix_matrixIsNotE();
    test_isEMatrix_matrixIsNotSquare();
}

void test_isSymmetricMatrix_matrixIsSymmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 5, 6,
                                              3, 6, 7}, 3, 3);

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_matrixIsNotSymmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_matrixIsNotSquare() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6}, 2, 3);

    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_matrixIsSymmetric();
    test_isSymmetricMatrix_matrixIsNotSymmetric();
    test_isSymmetricMatrix_matrixIsNotSquare();
}

void test_transposeSquareMatrix_matrixIsSquare() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 4, 7,
                                               2, 5, 8,
                                               3, 6, 9}, 3, 3);
    transposeSquareMatrix(m1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_matrixIsSquare();
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray((int[]) {8, 2, 3,
                                              4, 3, 0,
                                              5, 8, 9}, 3, 3);
    position min = getMinValuePos(m);

    position expectation = {1, 2};

    assert(twoPositionIsEqual(min, expectation));

    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray((int[]) {8, 2, 3,
                                              4, 3, 0,
                                              5, 13, 5}, 3, 3);
    position max = getMaxValuePos(m);

    position expectation = {2, 1};

    assert(twoPositionIsEqual(max, expectation));

    freeMemMatrix(m);
}

void test_pt1() {
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

// task 1

// меняет местами строки матрицы m, содержащие максимальный и минимальный элементы
void swapRowsWithMinAndMaxElement(matrix *m) {
    position min = getMinValuePos(*m);
    position max = getMaxValuePos(*m);

    swapRows(*m, min.rowIndex, max.rowIndex);
}

void test_swapRowsWithMinAndMaxElement_maxAndMinInDifferentRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);

    swapRowsWithMinAndMaxElement(&m);

    matrix expectation = createMatrixFromArray((int[]) {7, 8, 9,
                                                        4, 5, 6,
                                                        1, 2, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_swapRowsWithMaxAndMinValues_maxAndMinInSameRow() {
    matrix m = createMatrixFromArray((int[]) {1, 10, 9,
                                              4, 5, 6,
                                              7, 8, 2}, 3, 3);

    swapRowsWithMinAndMaxElement(&m);

    matrix expectation = createMatrixFromArray((int[]) {1, 10, 9,
                                                        4, 5, 6,
                                                        7, 8, 2}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_swapRowsWithMinAndMaxElement() {
    test_swapRowsWithMaxAndMinValues_maxAndMinInSameRow();
    test_swapRowsWithMinAndMaxElement_maxAndMinInDifferentRows();
}

// task 2

//возвращает индекст максимального элемента массива а размера n
int getMax(const int *a, const size_t n) {
    if (n < 1) {
        fprintf(stderr, "empty array");
        exit(1);
    }
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

//упорядочивает строки матрицы m по неубыванию наибольших элементов строк
void sortRowsByMinElement(matrix m) {
    insertionSortMatrixByCriteria(&m, getMax, ROWS);
}

void test_sortRowsByMinElement_squareMatrix() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                              1, 8, 1,
                                              3, 2, 3}, 3, 3);

    sortRowsByMinElement(m);

    matrix expectation = createMatrixFromArray((int[]) {3, 2, 3,
                                                        7, 1, 2,
                                                        1, 8, 1}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortRowsByMinElement_notSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2, 3,
                                              1, 8, 1, 6,
                                              3, 2, 3, 8}, 3, 4);

    sortRowsByMinElement(m);

    matrix expectation = createMatrixFromArray((int[]) {7, 1, 2, 3,
                                                        3, 2, 3, 8,
                                                        1, 8, 1, 6}, 3, 4);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortRowsByMinElement_oneElem() {
    matrix m = createMatrixFromArray((int[]) {7}, 1, 1);

    sortRowsByMinElement(m);

    matrix expectation = createMatrixFromArray((int[]) {7}, 1, 1);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortRowsByMinElement_oneRow() {
    matrix m = createMatrixFromArray((int[]) {7, 2, 4, 6}, 1, 4);

    sortRowsByMinElement(m);

    matrix expectation = createMatrixFromArray((int[]) {7, 2, 4, 6}, 1, 4);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortRowsByMinElement_oneCol() {
    matrix m = createMatrixFromArray((int[]) {7,
                                              2,
                                              4,
                                              6}, 4, 1);

    sortRowsByMinElement(m);

    matrix expectation = createMatrixFromArray((int[]) {2,
                                                        4,
                                                        6,
                                                        7}, 4, 1);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortRowsByMinElement() {
    test_sortRowsByMinElement_squareMatrix();
    test_sortRowsByMinElement_notSquareMatrix();
    test_sortRowsByMinElement_oneElem();
    test_sortRowsByMinElement_oneRow();
    test_sortRowsByMinElement_oneCol();
}

void test_pt2() {
    test_swapRowsWithMinAndMaxElement();
    test_sortRowsByMinElement();
}

int main() {
    test_pt1();
    test_pt2();

    return 0;
}