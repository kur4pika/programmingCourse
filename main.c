#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/array/array.h"
#include "libs/algorithms/algorithms.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

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

//упорядочивает строки матрицы m по неубыванию минимальных элементов столбцов
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

// возвращает матрицу m1 * m2
matrix mulMatrices(const matrix m1, const matrix m2) {
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



// task 5

//возвращает значение 'истина', если элементы массива а размера n уникальны, иначе - 'ложь'
bool isUnique(const long long *a, const int n) {
    bool isUnique = true;

    selectionSort(a, n);

    int i = 0;
    while (i < n - 1 && isUnique) {
        if (a[i] == a[i + 1])
            isUnique = 0;
        i++;
    }

    return isUnique;
}

// возвращает сумму элементов массива a размера n
long long getSum(const int *a, const int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

// транспонирует квадратную матрицу m, если среди сумм элементов строк матрицы нет равных
void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sum[m.nRows];

    for (int i = 0; i < m.nRows; i++)
        sum[i] = getSum(m.values[i], m.nCols);

    if (isUnique(sum, m.nRows))
        transposeSquareMatrix(m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_oneElem() {
    matrix m = createMatrixFromArray((int[]) {2}, 1, 1);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    matrix expectation = createMatrixFromArray((int[]) {2}, 1, 1);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSum() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                              1, 8, 1,
                                              3, 1, 3}, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    matrix expectation = createMatrixFromArray((int[]) {7, 1, 2,
                                                        1, 8, 1,
                                                        3, 1, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_hasNotEqualSum() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 1,
                                              1, 8, 1,
                                              3, 1, 3}, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    matrix expectation = createMatrixFromArray((int[]) {7, 1, 3,
                                                        1, 8, 1,
                                                        1, 1, 3}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_oneElem();
    test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSum();
    test_transposeIfMatrixHasNotEqualSumOfRows_hasNotEqualSum();
}


// task 6

//возвращает значение 'истина', если матрицы m1 и m2 являются взаимно обратными
bool isMutuallyInverseMatrices(const matrix m1, const matrix m2) {
    matrix mulMatrix = mulMatrices(m1, m2);
    bool isMutuallyInverse = isEMatrix(mulMatrix);

    free(mulMatrix.values);
    return isMutuallyInverse;

}

void test_isMutuallyInverseMatrices_matrix2x2ProduceIsEMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {3, 4,
                                               5, 7}, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {7, -4,
                                               -5, 3}, 2, 2);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_matrix3x3ProduceIsEMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {2, 5, 7,
                                               6, 3, 4,
                                               5, -2, -3}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, -1, 1,
                                               -38, 41, -34,
                                               27, -29, 24}, 3, 3);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_matrix2x2ProduceIsNotEMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {3, 4,
                                               5, 7}, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {7, 4,
                                               -5, 3}, 2, 2);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_matrix3x3ProduceIsNotEMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {2, 5, 7,
                                               6, 3, 4,
                                               5, -2, -3}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, -1, -1,
                                               -38, 41, -34,
                                               27, -29, 24}, 3, 3);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_matrix2x2ProduceIsEMatrix();
    test_isMutuallyInverseMatrices_matrix3x3ProduceIsEMatrix();
    test_isMutuallyInverseMatrices_matrix2x2ProduceIsNotEMatrix();
    test_isMutuallyInverseMatrices_matrix3x3ProduceIsNotEMatrix();
}



// task 9

//возвращает квадратный корень из суммы квадратов элементов массива а размера n
float getDistance(const int *a, const int n) {
    int squareDistance = 0;
    for (int i = 0; i < n; i++)
        squareDistance += a[i] * a[i];

    return sqrt(squareDistance);
}

// сортирует n точек m-мерного пространства по неубыванию их расстояния от начала координат
void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void test_sortByDistances_somePoints() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                              10, 11, 5, 1,
                                              7, 12, 3, 4}, 3, 4);

    sortByDistances(m);

    matrix expectation = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                                        7, 12, 3, 4,
                                                        10, 11, 5, 1}, 3, 4);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortByDistances_somePoints2() {
    matrix m = createMatrixFromArray((int[]) {8, 9, 10, 11,
                                              0, 1, 2, 3,
                                              4, 5, 6, 7}, 3, 4);

    sortByDistances(m);

    matrix expectation = createMatrixFromArray((int[]) {0, 1, 2, 3,
                                                        4, 5, 6, 7,
                                                        8, 9, 10, 11,}, 3, 4);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortByDistances_oneRow() {
    matrix m = createMatrixFromArray((int[]) {8, 9, 10, 11,}, 1, 4);

    sortByDistances(m);

    matrix expectation = createMatrixFromArray((int[]) {8, 9, 10, 11}, 1, 4);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortByDistances_oneCols() {
    matrix m = createMatrixFromArray((int[]) {11,
                                              9,
                                              10,
                                              2}, 4, 1);

    sortByDistances(m);

    matrix expectation = createMatrixFromArray((int[]) {2,
                                                        9,
                                                        10,
                                                        11}, 4, 1);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortByDistances_oneElem() {
    matrix m = createMatrixFromArray((int[]) {2}, 1, 1);

    sortByDistances(m);

    matrix expectation = createMatrixFromArray((int[]) {2}, 1, 1);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_sortByDistances() {
    test_sortByDistances_somePoints();
    test_sortByDistances_somePoints2();
    test_sortByDistances_oneRow();
    test_sortByDistances_oneCols();
    test_sortByDistances_oneElem();
}



// task 8

// возращает минимальный элемент матрицы m в области
int getMinInArea(const matrix m) {
    int max = m.values[0][0];
    position maxInArea = {0, 0};
    for (int i = 0; i < m.nCols; ++i)
        if (max < m.values[0][i]) {
            max = m.values[0][i];
            maxInArea.colIndex = i;
        }

    for (int i = 1; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] > max) {
                max = m.values[i][j];
                maxInArea.rowIndex = i;
                maxInArea.colIndex = j;
            }

            if (j == 0 || j == m.nCols - 1) {
                if (m.nCols == 1)
                    m.values[i][j] = min(m.values[i - 1][j], m.values[i][j]);
                else if (j == 0)
                    m.values[i][j] = min(m.values[i][j], min(m.values[i - 1][j], m.values[i - 1][j + 1]));
                else
                    m.values[i][j] = min(m.values[i][j], min(m.values[i - 1][j - 1], m.values[i - 1][j]));
            } else
                m.values[i][j] = min(m.values[i][j],
                                     min3(m.values[i - 1][j - 1], m.values[i - 1][j], m.values[i - 1][j + 1]));
        }

    }
    return m.values[maxInArea.rowIndex][maxInArea.colIndex];
}

void test_getMinInArea_rectangleMatrixMinInBot() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);

    assert(getMinInArea(m) == 5);

    freeMemMatrix(m);
}

void test_getMinInArea_rectangleMatrixMinInMiddle() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                              7, 12, 3, 4,
                                              10, 11, 5, 1}, 3, 4);

    assert(getMinInArea(m) == 6);

    freeMemMatrix(m);
}

void test_getMinInArea_rectangleVerticalMatrix_1() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 4,
                                              7, 12, 3, 6,
                                              10, 11, 5, 15,
                                              11, 14, 13, 1,
                                              16, 17, 18, 19}, 5, 4);

    assert(getMinInArea(m) == 1);

    freeMemMatrix(m);
}

void test_getMinInArea_rectangleVerticalMatrix_2() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 4,
                                              7, 12, 3, 6,
                                              10, 14, 5, 11,
                                              11, 1, 13, 15,
                                              16, 17, 18, 20}, 5, 4);

    assert(getMinInArea(m) == 3);

    freeMemMatrix(m);
}

void test_getMinInArea_oneElem() {
    matrix m = createMatrixFromArray((int[]) {6}, 1, 1);

    assert(getMinInArea(m) == 6);

    freeMemMatrix(m);
}

void test_getMinInArea_oneRow() {
    matrix m = createMatrixFromArray((int[]) {6,
                                              2,
                                              8,
                                              1,
                                              7}, 5, 1);

    assert(getMinInArea(m) == 2);

    freeMemMatrix(m);
}

void test_getMinInArea_oneCol() {
    matrix m = createMatrixFromArray((int[]) {6, 2, 8, 1, 7}, 1, 5);

    assert(getMinInArea(m) == 8);

    freeMemMatrix(m);
}

void test_getMinInArea() {
    test_getMinInArea_rectangleMatrixMinInBot();
    test_getMinInArea_rectangleMatrixMinInMiddle();
    test_getMinInArea_rectangleVerticalMatrix_1();
    test_getMinInArea_rectangleVerticalMatrix_2();
    test_getMinInArea_oneElem();
    test_getMinInArea_oneRow();
    test_getMinInArea_oneCol();

}



// task 7

// возращает значение максимума псевдодиагонали матрицы m, состоящей из n элементов,
// первый элемент которой имеет позицию [countRows][countCols]
long long findMaxOfPseudoDiagonal(const matrix m, const int countRows, const int countCols, const int n) {
    int maxInDiagonal = m.values[countRows][countCols];
    for (int i = 0; i < n; ++i)
        if (maxInDiagonal < m.values[countRows + i][countCols + i])
            maxInDiagonal = m.values[countRows + i][countCols + i];

    return maxInDiagonal;
}

// возращает сумму максимумов псевдодиагоналей матрицы m
long long findSumOfMaxesOfPseudoDiagonal(const matrix m) {
    long long sumOfMaxesOfPseudoDiagonal = 0;

    int kRows = 1;
    int kCols = 1;
    int countRows = m.nRows - 1;
    int countCols = m.nCols - 1;
    while (countRows || countCols) {
        if (countRows) {
            sumOfMaxesOfPseudoDiagonal += findMaxOfPseudoDiagonal(m, countRows, 0, kRows);
            countRows--;
        }
        if (countCols) {
            sumOfMaxesOfPseudoDiagonal += findMaxOfPseudoDiagonal(m, 0, countCols, kCols);
            countCols--;
        }

        if (kRows + 1 <= m.nCols)
            kRows++;
        if (kCols + 1 <= m.nRows)
            kCols++;
    }

    return sumOfMaxesOfPseudoDiagonal;
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveNotSquareMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                               1, 3, 6, 3,
                                               3, 2, 1, 2}, 3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 20);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeNotSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {-3, -2, -5, -4,
                                              -1, -3, -6, -3,
                                              -3, -2, -1, -2}, 3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == -3 + -1 + -2 + -3 + -4);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {3, 1, 3,
                                              1, 8, 1,
                                              7, 1, 2,}, 3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 7 + 1 + 1 + 3);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {-3, -1, -3,
                                              -1, -8, -1,
                                              -7, -1, -2,}, 3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == -7 + -1 + -1 + -3);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneCol() {
    matrix m = createMatrixFromArray((int[]) {-3,
                                              1,
                                              -7,
                                              4,
                                              -1,
                                              6}, 6, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 1 + -7 + 4 + -1 + 6);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix m = createMatrixFromArray((int[]) {-3, 1, -7, 4, -1, 6}, 1, 6);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 1 + -7 + 4 + -1 + 6);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneElem() {
    matrix m = createMatrixFromArray((int[]) {-3}, 1, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 0);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_positiveNotSquareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeNotSquareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_oneRow();
    test_findSumOfMaxesOfPseudoDiagonal_oneCol();
    test_findSumOfMaxesOfPseudoDiagonal_oneElem();
    test_findSumOfMaxesOfPseudoDiagonal_negativeSquareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_positiveSquareMatrix();

}



// task 10

// возвращает количество эквивалентных строк матрицы m
int countEqClassesByRowsSum(const matrix m) {
    long long rowSums[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowSums[i] = getSum(m.values[i], m.nCols);

    return countNUnique(rowSums, m.nRows);
}

void test_countEqClassesByRowsSum_verticalMatrix() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              2, 7,
                                              5, 4,
                                              4, 3,
                                              1, 6,
                                              8, 0}, 6, 2);

    assert(countEqClassesByRowsSum(m) == 3);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_horizontalMatrix() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2, 7,
                                              5, 4, 4, 4,
                                              1, 6, 8, 2}, 3, 4);

    assert(countEqClassesByRowsSum(m) == 1);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_oneRow() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2, 7,}, 1, 4);

    assert(countEqClassesByRowsSum(m) == 1);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_oneCol() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2, 7,}, 1, 4);

    assert(countEqClassesByRowsSum(m) == 1);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_oneElem() {
    matrix m = createMatrixFromArray((int[]) {7}, 1, 1);

    assert(countEqClassesByRowsSum(m) == 1);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_verticalMatrix();
    test_countEqClassesByRowsSum_horizontalMatrix();
    test_countEqClassesByRowsSum_oneRow();
    test_countEqClassesByRowsSum_oneCol();
    test_countEqClassesByRowsSum_oneElem();

}



// task 11

// возвращает количетво элементов матрицы m, которые больше суммы остальных элементов своего столбца
int getNSpecialElement(matrix m) {
    transposeMatrix(&m);
    int counterNSpecialElement = 0;
    for (int i = 0; i < m.nRows; ++i) {
        int maxInRow = getMax(m.values[i], m.nCols);
        if (getSum(m.values[i], m.nCols) - maxInRow < maxInRow)
            counterNSpecialElement++;
    }

    return counterNSpecialElement;
}

void test_getNSpecialElement_rectangleMatrix() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 7,
                                              12, 2, 1, 2}, 3, 4);

    assert(getNSpecialElement(m) == 2);

    freeMemMatrix(m);
}

void test_getNSpecialElement_rectangleMatrixHasNotSpecial() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 4,
                                              1, 2, 1, 2}, 3, 4);

    assert(getNSpecialElement(m) == 0);

    freeMemMatrix(m);
}

void test_getNSpecialElement_allElementsEqual() {
    matrix m = createMatrixFromArray((int[]) {5, 5, 5,
                                              5, 5, 5,
                                              5, 5, 5,
                                              5, 5, 5}, 4, 3);

    assert(getNSpecialElement(m) == 0);

    freeMemMatrix(m);
}

void test_getNSpecialElement_oneRow() {
    matrix m = createMatrixFromArray((int[]) {1,
                                              2,
                                              3,
                                              7}, 4, 1);

    assert(getNSpecialElement(m) == 1);

    freeMemMatrix(m);
}

void test_getNSpecialElement_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {1, 2, 3, 7}, 1, 4);

    assert(getNSpecialElement(m) == 4);

    freeMemMatrix(m);
}

void test_getNSpecialElement() {
    test_getNSpecialElement_rectangleMatrix();
    test_getNSpecialElement_rectangleMatrixHasNotSpecial();
    test_getNSpecialElement_allElementsEqual();
    test_getNSpecialElement_oneRow();
    test_getNSpecialElement_oneCol();
}



// task 12

// возвращает позицию минимального элемента
position getLeftMin(matrix m) {
    position min = {0, 0};
    for (size_t j = 0; j < m.nCols; j++)
        for (size_t i = 0; i < m.nRows; i++)
            if (m.values[i][j] < m.values[min.rowIndex][min.colIndex]) {
                min.rowIndex = i;
                min.colIndex = j;
            }

    return min;
}

// заменяет предпоследнюю строку матрицы m на первый из столбцов, содержащий минимальный элемент
void swapPenultimateRow(matrix m) {
    position min = getLeftMin(m);

    int colWithMin[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        colWithMin[i] = m.values[i][min.colIndex];

    for (int i = 0; i < m.nCols; i++)
        m.values[m.nRows - 2][i] = colWithMin[i];
}

void test_swapPenultimateRow_squareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 1,}, 3, 3);

    swapPenultimateRow(m);

    matrix expectation = createMatrixFromArray((int[]) {1, 2, 3,
                                                        1, 4, 7,
                                                        7, 8, 1,}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_swapPenultimateRow_twoRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2,
                                              4, 5}, 2, 2);

    swapPenultimateRow(m);

    matrix m2 = createMatrixFromArray((int[]) {1, 4,
                                               4, 5}, 2, 2);

    assert(areTwoMatricesEqual(m, m2));

    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_swapPenultimateRow_someMinimums() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 1,
                                              4, 5, 4,
                                              1, 6, 7}, 3, 3);

    swapPenultimateRow(m);

    matrix expectation = createMatrixFromArray((int[]) {4, 2, 1,
                                                        4, 4, 1,
                                                        1, 6, 7}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_swapPenultimateRow_EMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);

    swapPenultimateRow(m);

    matrix expectation = createMatrixFromArray((int[]) {1, 0, 0,
                                                        1, 0, 0,
                                                        0, 0, 1}, 3, 3);

    assert(areTwoMatricesEqual(m, expectation));

    freeMemMatrix(m);
    freeMemMatrix(expectation);
}

void test_swapPenultimateRow() {
    test_swapPenultimateRow_squareMatrix();
    test_swapPenultimateRow_twoRows();
    test_swapPenultimateRow_someMinimums();
    test_swapPenultimateRow_EMatrix();
}



// task 13

// возвращает значение 'истина', если элементы массива упорядочены по неубыванию, иначе - 'ложь'
bool isNonDescendingSorted(int *a, int n) {
    int i = 1;
    while (i < n) {
        if (a[i] < a[i - 1])
            return false;
        i++;
    }
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    int i = 0;
    while (i < m.nRows) {
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
        i++;
    }
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            count++;

    return count;
}

void test_countNonDescendingRowsMatrices_squareMatrixHasSuitableMatrix() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {7, 1,
                                                       1, 1,

                                                       1, 6,
                                                       2, 2,

                                                       5, 4,
                                                       2, 3,

                                                       1, 3,
                                                       7, 9}, 4, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_notSquareMatrixHasSuitableMatrix() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {0, 0, 1,
                                                       1, 3, 2,

                                                       1, 6, 7,
                                                       2, 2, 2,

                                                       -1, 0, 1,
                                                       2, 1, 2,

                                                       1, 2, 3,
                                                       1, 2, 3}, 4, 2, 3);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneRow() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {0, 0, 1,

                                                       1, 6, 7,

                                                       -1, 0, 1,

                                                       1, 2, 3,}, 4, 1, 3);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneCol() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {0,
                                                       0,
                                                       1,

                                                       1,
                                                       6,
                                                       7,

                                                       -1,
                                                       0,
                                                       1,

                                                       1,
                                                       2,
                                                       3,}, 4, 3, 1);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneElem() {
    matrix *ms = createArrayOfMatrixFromArray((int[]) {0,

                                                       1,

                                                       -1,

                                                       1}, 4, 1, 1);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices_squareMatrixHasSuitableMatrix();
    test_countNonDescendingRowsMatrices_notSquareMatrixHasSuitableMatrix();
    test_countNonDescendingRowsMatrices_oneRow();
    test_countNonDescendingRowsMatrices_oneCol();
    test_countNonDescendingRowsMatrices_oneElem();
}

void test_pt2() {
    test_swapRowsWithMinAndMaxElement();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_sortByDistances();
    test_getMinInArea();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
}

int main() {
    test_pt1();
    test_pt2();

    return 0;
}