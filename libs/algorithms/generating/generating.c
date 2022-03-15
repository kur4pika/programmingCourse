#include "generating.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void generateRandomArray(int *a, size_t n) {
    for (int i = 0; i < n; ++i)
        a[i] = rand() % INT_MAX;
}

void generateOrderedArray(int *a, size_t n) {
    for (int i = 0; i < n; ++i)
        a[i] = i;
}

void generateOrderedBackwardsArray(int *a, size_t n) {
    int i = (int) n - 1;
    for (int j = 0; i >= 0; --i, j++)
    a[j] = i;
}
