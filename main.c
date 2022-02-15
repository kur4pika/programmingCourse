#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/array/array.h"
#include <assert.h>
#include <stdbool.h>

#define EXIT_CODE 1
#define throwExceptionEmptyArray() fprintf(stderr, "empty array"); exit(EXIT_CODE);

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

void test_swapRowsWithMaxAndMinValues_oneElem() {
    matrix m = createMatrixFromArray((int[]) {1}, 1, 1);

    swapRowsWithMinAndMaxElement(&m);

    matrix expectation = createMatrixFromArray((int[]) {1}, 1, 1);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_swapRowsWithMinAndMaxElement() {
    test_swapRowsWithMaxAndMinValues_maxAndMinInSameRow();
    test_swapRowsWithMinAndMaxElement_maxAndMinInDifferentRows();
    test_swapRowsWithMaxAndMinValues_oneElem();
}



// task 2

//возвращает максимальный элемент массива а размера n
int getMax(const int *a, const size_t n) {
    if (n < 1) {
        throwExceptionEmptyArray();
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



// task 3

//возвращает минимальный элемент массива а размера n
int getMin(const int *a, const size_t n) {
    if (n < 1) {
        throwExceptionEmptyArray();
    }

    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}

//упорядочивает строки матрицы m по неубыванию наибольших элементов столбцов
void sortColsByMinElement(matrix m) {
    insertionSortMatrixByCriteria(&m, getMin, COLS);
}

void test_sortColsByMinElement_squareMatrix() {
    matrix m = createMatrixFromArray((int[]) {7, -1, 2,
                                              1, 8, -2,
                                              3, 2, 3}, 3, 3);

    sortColsByMinElement(m);

    matrix expectation = createMatrixFromArray((int[]) {2, -1, 7,
                                                        -2, 8, 1,
                                                        3, 2, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortColsByMinElement_notSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1, 0,
                                              -1, -1, -1, -1,
                                              -2, -5, -7, -6}, 3, 4);

    sortColsByMinElement(m);

    matrix expectation = createMatrixFromArray((int[]) {1, 0, 2, 3,
                                                        -1, -1, -1, -1,
                                                        -7, -6, -5, -2}, 3, 4);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortColsByMinElement_oneElem() {
    matrix m = createMatrixFromArray((int[]) {7}, 1, 1);

    sortColsByMinElement(m);

    matrix expectation = createMatrixFromArray((int[]) {7}, 1, 1);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortColsByMinElement_oneRow() {
    matrix m = createMatrixFromArray((int[]) {7, 2, 4, 6}, 1, 4);

    sortColsByMinElement(m);

    matrix expectation = createMatrixFromArray((int[]) {2, 4, 6, 7}, 1, 4);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortColsByMinElement_oneCol() {
    matrix m = createMatrixFromArray((int[]) {7,
                                              2,
                                              4,
                                              6}, 4, 1);

    sortColsByMinElement(m);

    matrix expectation = createMatrixFromArray((int[]) {7,
                                                        2,
                                                        4,
                                                        6}, 4, 1);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_squareMatrix();
    test_sortColsByMinElement_notSquareMatrix();
    test_sortColsByMinElement_oneElem();
    test_sortColsByMinElement_oneRow();
    test_sortColsByMinElement_oneCol();
}



// task 4

//Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом

// возвращает матрицу m1 * m2
matrix mulMatrices(matrix m1, matrix m2) {
    matrix product = getMemMatrix(m1.nRows, m2.nCols);

    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            product.values[i][j] = 0;
            for (int k = 0; k < m2.nRows; k++)
                product.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    }

    return (matrix) product;
}

// возводит матрицу m в квадрат, если она является симметриченой
void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        *m = mulMatrices(*m, *m);
    }
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v1() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                              1, 8, 1,
                                              2, 1, 3}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectation = createMatrixFromArray((int[]) {54, 17, 21,
                                                        17, 66, 13,
                                                        21, 13, 14}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v2() {
    matrix m = createMatrixFromArray((int[]) {0, 11, 7,
                                              11, 0, 4,
                                              7, 4, 22}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectation = createMatrixFromArray((int[]) {170, 28, 198,
                                                        28, 137, 165,
                                                        198, 165, 549}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v3() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectation = createMatrixFromArray((int[]) {1, 0, 0,
                                                        0, 1, 0,
                                                        0, 0, 1}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_getSquareOfMatrixIfSymmetric_oneElem() {
    matrix m = createMatrixFromArray((int[]) {7}, 1, 1);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectation = createMatrixFromArray((int[]) {49}, 1, 1);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_getSquareOfMatrixIfSymmetric_NotSymmetricSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                              1, 8, 1,
                                              3, 1, 3}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    matrix expectation = createMatrixFromArray((int[]) {7, 1, 2,
                                                        1, 8, 1,
                                                        3, 1, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v1();
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v2();
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v3();
    test_getSquareOfMatrixIfSymmetric_oneElem();
    test_getSquareOfMatrixIfSymmetric_NotSymmetricSquareMatrix();
}

void test_pt2() {
    test_swapRowsWithMinAndMaxElement();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
}

int main() {
    test_pt1();
    test_pt2();

    return 0;
}