#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include <mem.h>

#define EXIT_CODE 1

#define throwExceptionBadIndex() fprintf(stderr, "bad index"); exit(EXIT_CODE)
#define throwExceptionEmptyArray() fprintf(stderr, "empty array"); exit(EXIT_CODE);

// размещает в динамической памяти матрицу размером nRows на nCols
matrix getMemMatrix(const int nRows, const int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

// размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols
matrix *getMemArrayOfMatrices(const int nMatrices, const int nRows, const int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

// освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

// освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, const int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

// ввод матрицы m
void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

// ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, const int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

// вывод матрицы m
void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

// вывод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, const int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapUnivers(void *a, void *b, const size_t baseSizeType) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < baseSizeType; i++) {
        char tmp = *pa;
        *pa = *pb;
        *pb = tmp;
        pa++;
        pb++;
    }
}

// обмен строк с порядковыми номерами i1 и i2 в матрице m
void swapRows(matrix m, const int i1, const int i2) {
    if (i1 >= m.nRows || i2 >= m.nRows || i1 < 0 || i2 < 0) {
        throwExceptionBadIndex();
    }

    swapUnivers(&m.values[i1], &m.values[i2], sizeof(int));
}

// обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, const int j1, const int j2) {
    if (j1 >= m.nCols || j2 >= m.nCols || j1 < 0 || j2 < 0) {
        throwExceptionBadIndex();
    }

    for (int i = 0; i < m.nRows; i++) {
        swapUnivers(&m.values[i][j1], &m.values[i][j2], sizeof(int));
    }
}

// выполняет сортировку вставками строк(столбцов) матрицы m по неубыванию значения функции
// criteria применяемой для строк(столбцов)
void insertionSortMatrix(int a[], matrix *m, void (f)(matrix, int, int), const int rowsOrCols){
    for (int i = 1; i < rowsOrCols; ++i) {
        int k = i;
        while (k > 0 && a[k - 1] >= a[k]){
            swapUnivers(&a[k - 1], &a[k], sizeof(int));
            f(*m, k - 1, k);

            k--;
        }
    }
}

void insertionSortMatrixByCriteria(matrix *m, int (criteria)(int [], int), const bool rowsOrCols){
    if (rowsOrCols == ROWS){
        int rowsArr[m->nRows];
        for (int i = 0; i < m->nRows; ++i)
            rowsArr[i] = criteria(m->values[i], m->nCols);

        insertionSortMatrix(rowsArr, m, swapRows, m->nRows);
    }
    else if (rowsOrCols == COLS){
        int colsArr[m->nCols];
        for (int i = 0; i < m->nCols; ++i) {
            int t[m->nRows];
            for (int j = 0; j < m->nRows; ++j)
                t[j] = m->values[j][i];

            colsArr[i] = criteria(t, m->nRows);
        }

        insertionSortMatrix(colsArr, m, swapColumns, m->nCols);
    }
}

//возвращает значение 'истина', если матрица m является квадратной, 'ложь' – в противном случае
bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

//возвращает значение 'истина', если матрицы m1 и m2 равны, 'ложь' – в противном случае
bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (int i = 0; i < m1.nRows; i++)
        if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols) != 0)
            return false;

    return true;
}

//возвращает значение 'истина', если матрица m является единичной, 'ложь' – в противном случае
bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    int countOne = 0;
    int countZero = 0;
    for (int i = 0; i < m.nRows; i++) {
        if (m.values[i][i] == 1)
            countOne++;
        for (int j = 0; j < m.nRows; j++)
            if (m.values[i][j] == 0)
                countZero++;
    }

    return countOne + countZero == m.nRows * m.nCols;
}

//возвращает значение 'истина', если матрица m является симметричной, 'ложь' – в противном случае
bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    int jStart = 0;
    int i = 0;
    int j = 0;
    while (i < m.nRows && j < m.nCols) {
        if (m.values[i][j] != m.values[j][i])
            return false;

        j++;
        if (j == m.nRows) {
            jStart++;
            j = jStart;
            i++;
        }
    }

    return true;
}

//транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix m) {
    if (isSquareMatrix(m)) {
        for (size_t i = 0; i < m.nRows; i++)
            for (size_t j = i + 1; j < m.nCols; j++)
                swapUnivers(&m.values[i][j], &m.values[j][i], sizeof(int));
    }
}

void transposeMatrix(matrix *m) {
    //TODO: реализовать универсальное транспонирование
}

//возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m) {
    position min = {0, 0};
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (m.values[i][j] < m.values[min.rowIndex][min.colIndex]) {
                min.rowIndex = i;
                min.colIndex = j;
            }

    return min;
}

// выводит позицию p
//void outputPosition(position p) {
//    printf("{%d, ", p.rowIndex);
//    printf("%d}", p.colIndex);
//}

// возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m) {
    position max = {0, 0};
    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = 0; j < m.nCols; ++j)
            if (m.values[i][j] > m.values[max.rowIndex][max.colIndex]) {
                max.rowIndex = i;
                max.colIndex = j;
            }

    return max;
}

// возвращает матрицу, размера nRows на nCols, построенного из элементов массива a, размещенную в динамической памяти
matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

// возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных в динамической памяти,
// построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

// возвращает значение 'истина', если позиции равны, иначе - 'ложь'
bool twoPositionIsEqual(position p1, position p2) {
    if (p1.rowIndex != p2.rowIndex || p1.colIndex != p2.colIndex)
        return false;

    return true;
}


