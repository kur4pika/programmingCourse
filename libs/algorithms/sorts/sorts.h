#ifndef MAIN_C_SORTS_H
#define MAIN_C_SORTS_H

#include <stdint.h>

// пузырьковая сортировка
void bubbleSort(int *a, size_t n);

// сортировка выбором
void selectionSort(int *a, size_t n);

// сортировка втсавками
void insertionSort(int *a, size_t n);

// сортировка расческой
void combSort(int *a, size_t n);

// сортировка Шелла
void shellSort(int *a, size_t n);

// цифровая сортировка
void radixSort(int *a, size_t n);
//void getRadixSortNComps(int *a, size_t n);

long long getShellSortNComp(int *a, size_t n);

long long getBubbleSortNComp(int *a, size_t n);

long long getSelectionSortNComp(int *a, size_t n);

long long getInsertionSortNComp(int *a, size_t n);

long long getCombSortNComp(int *a, size_t n);


#endif //MAIN_C_SORTS_H