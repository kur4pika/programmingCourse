#ifndef MAIN_C_GENERATING_H
#define MAIN_C_GENERATING_H

#include <stdint.h>

void generateRandomArray(int *a, size_t n);// генерируется случайный массив

void generateOrderedArray(int *a, size_t n);// генерируется массив 0, 1, 2, ..., n - 1

void generateOrderedBackwardsArray(int *a, size_t n);// генерируется массив n - 1, n - 2, ..., 0

#endif //MAIN_C_GENERATING_H
