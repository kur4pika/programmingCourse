#ifndef MAIN_C_MATRIX_H
#define MAIN_C_MATRIX_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct matrix {
    int **values;// элементы матрицы
    int nRows;// количество рядов
    int nCols;// количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);// размещает в динамической памяти матрицу размером nRows на nCols

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);// размещает в динамической памяти массив из nMatrices
                                                                   // матриц размером nRows на nCols

void freeMemMatrix(matrix *m);// освобождает память, выделенную под хранение матрицы m

void freeMemMatrices(matrix *ms, int nMatrices);// освобождает память, выделенную под хранение массива ms из nMatrices матриц

void inputMatrix(matrix *m);// ввод матрицы m

void inputMatrices(matrix *ms, int nMatrices);// ввод массива из nMatrices матриц, хранящейся по адресу ms

void outputMatrix(matrix m);// вывод матрицы m

void outputMatrices(matrix *ms, int nMatrices);// вывод массива из nMatrices матриц, хранящейся по адресу ms

void swapRows(matrix *m, int i1, int i2);// обмен строк с порядковым номерами i1 и i2 в матрице m

void swapColumns(matrix *m, int j1, int j2);// обмен колонок с порядковыми номерами j1 и j2 в матрице m

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));// выполняет сортировку вставками строк
                                                                                 // матрицы m по неубыванию значения функции
                                                                                 // criteria применяемой для строк

//тут еще одна

bool isSquareMatrix(matrix m);// возвращает значение 'истина', если матрица m
                              // является квадратной, 'ложь' – в противном случае

bool twoMatricesEqual(matrix m1, matrix m2);// возвращает значение 'истина', если матрицы m1 и m2 равны,
                                            // 'ложь' – в противном случае

bool isEMatrix(matrix m);// возвращает значение 'истина', если матрица m является единичной, 'ложь' – в противном случае

bool isSymmetricMatrix(matrix m);//возвращает значение 'истина', если матрица m является симметричной, 'ложь' – в противном случае

void transposeSquareMatrix(matrix *m);//транспонирует квадратную матрицу m

#endif //MAIN_C_MATRIX_H
