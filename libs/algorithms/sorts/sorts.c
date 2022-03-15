#include "sorts.h"
#include "../array/array.h"
#include <malloc.h>

// пузырьковая сортировка
void bubbleSort(int *a, size_t n) {
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
}

// сортировка выбором
void selectionSort(int *a, size_t n) {
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min])
                min = j;
        }
        swap(&a[min], &a[i]);
    }
}

// сортировка втсавками
void insertionSort(int *a, size_t n) {
    for (int i = 1; i < n; ++i) {
        int k = i;
        while (k > 0 && a[k] < a[k - 1]) {
            swap(&a[k], &a[k - 1]);

            k--;
        }
    }
}

// сортировка расческой
void combSort(int *a, const size_t n) {
    size_t step = n;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (int i = 0, j = i + step; j < n; ++i, j++) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
        }
    }
}

// сортировка Шелла
void shellSort(int *a, size_t n) {
    int i, j, step;
    int temp;
    for (step = n / 2; step > 0; step /= 2) {
        for (i = step; i < n; i++) {
            temp = a[i];
            for (j = i; j >= step; j -= step) {
                if (temp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = temp;
        }
    }
}

int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}

void radixSort_(int *a, int *n) {
    int bit = 8;
    int k = (32 + bit - 1) / bit;
    int M = 1 << bit;
    int sz = n - a;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;

        for (int *j = a; j < n; j++)
            c[digit(*j, i, bit, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = n - 1; j >= a; j--)
            b[--c[digit(*j, i, bit, M)]] = *j;

        int cur = 0;
        for (int *j = a; j < n; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
}

// цифровая сортировка
void radixSort(int *a, size_t n) {
    radixSort_(a, a + n);
}

long long getBubbleSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (size_t i = 0; ++nComps && i < n - 1; i++)
        for (size_t j = n - 1; ++nComps && j > i; j--)
            if (++nComps && a[j - 1] > a[j]) {
                swap(&a[j - 1], &a[j]);
            }

    return nComps;
}

long long getSelectionSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (size_t i = 0; ++nComps && i < n; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < n; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex]);
    }

    return nComps;
}

long long getInsertionSortNComp(int *a, size_t n) {
    long long nComps = 0;
    for (size_t i = 1; ++nComps && i < n; i++) {
        int t = a[i];
        size_t j = i;
        while (++nComps && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return nComps;
}

long long getCombSortNComp(int *a, size_t n) {
    size_t step = n;
    int swapped = 1;
    long long nComps = 0;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < n; ++i, ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }

    return nComps;
}

long long getShellSortNComp(int *a, size_t n) {
    long long nComps = 0;
    size_t j;
    int tmp;
    for (size_t step = n / 2; ++nComps && step > 0; step /= 2)
        for (size_t i = step; ++nComps && i < n; i++) {
            tmp = a[i];
            for (j = i; ++nComps && j >= step; j -= step) {
                if (++nComps && tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }

    return nComps;
}

long long getRadixSortNComps_(int *a, int *n) {
    long long nComps = 0;
    int bit = 8;
    int k = (32 + bit - 1) / bit;
    int M = 1 << bit;
    int sz = n - a;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; ++nComps && i < k; i++) {
        for (int j = 0; ++nComps && j < M; j++)
            c[j] = 0;

        for (int *j = a; ++nComps && j < n; j++)
            c[digit(*j, i, bit, M)]++;

        for (int j = 1; ++nComps && j < M; j++)
            c[j] += c[j - 1];

        for (int *j = n - 1; ++nComps && j >= a; j--)
            b[--c[digit(*j, i, bit, M)]] = *j;

        int cur = 0;
        for (int *j = a; ++nComps && j < n; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);

    return nComps;
}

long long getRadixSortNComps(int *a, size_t n) {
    return getRadixSortNComps_(a, a + n);
}