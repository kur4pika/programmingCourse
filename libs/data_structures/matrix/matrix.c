#include "matrix.h"
#include <malloc.h>
#include <stdio.h>

#define EXIT_CODE 1

#define throwExceptionBadIndex() fprintf(stderr, "bad index"); exit(EXIT_CODE)


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
void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}

// освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, const int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
    free(ms);
}

// ввод матрицы m
void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            scanf("%d", &m->values[i][j]);
}

// ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
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
void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapUniversal(void *a, void *b, const size_t baseSizeType) {
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
void swapRows(matrix *m, int i1, int i2) {
    if (i1 >= m->nRows || i2 >= m->nRows) {
        throwExceptionBadIndex();
    }

    swapUniversal(&m->values[i1], &m->values[i2], sizeof(int));
}

// обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix *m, int j1, int j2) {
    if (j1 >= m->nCols || j2 >= m->nCols) {
        throwExceptionBadIndex();
    }

    for (int i = 0; i < m->nRows; i++) {
        swapUniversal(&m->values[i][j1], &m->values[i][j2], sizeof(int));
    }
}

// выполняет сортировку вставками строк
// матрицы m по неубыванию значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {

}

//и еще одна функция

//возвращает значение 'истина', если матрица m является квадратной, 'ложь' – в противном случае
bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

//возвращает значение 'истина', если два массива равны, иначе - 'ложь'
bool twoArrayEqual(const int *a, const size_t sizeA, const int *b, const size_t sizeB) {
    if (sizeA != sizeB)
        return false;

    int count = 0;
    for (int i = 0; i < sizeA; i++)
        if (a[i] == b[i])
            count++;

    return count == sizeA;
}

//возвращает значение 'истина', если матрицы m1 и m2 равны, 'ложь' – в противном случае
bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    int count = 0;
    for (int i = 0; i < m1.nRows; i++)
        if (twoArrayEqual(m1.values[i], m1.nCols, m2.values[i], m2.nCols))
            count++;

    return count == m1.nRows;
}

//возвращает значение 'истина', если матрица m является единичной, 'ложь' – в противном случае
bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    int countOne = 0;
    int countZero = 0;
    for (int i = 0; i < m.nRows; i++) {
        if (m.values[i][i])
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
void transposeSquareMatrix(matrix *m) {
    if (isSquareMatrix(*m)) {
        for (size_t i = 0; i < m->nRows; i++)
            for (size_t j = i + 1; j < m->nCols; j++)
                swapUniversal(&m->values[i][j], &m->values[j][i], sizeof(int));
    }
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


