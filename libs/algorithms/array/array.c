#include "array.h"
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdlib.h>


#define EXIT_CODE 1
#define throwExceptionEmptyArray() fprintf(stderr, "empty array"); exit(EXIT_CODE);

void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void append_(int *const a, size_t *const n, const int value) {
    a[*n] = value;
    (*n)++;
}

void insert_(int *const a, size_t *const n, const size_t pos,
             const int value) {
    assert(pos < *n);
    if (*n != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;
        (*n)++;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];
        a[pos] = value;
    } else {
        (*n)++;
        a[pos] = value;
    }
}

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos + 1; i < *n; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

size_t linearSearch_(const long long *a, const size_t n, long long x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n;
}

int any_(const int *a, size_t n, int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        if (predicate(a[i]))
            return 1;
    return 0;
}

int all_(const int *a, size_t n, int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        if (!predicate(a[i]))
            return 0;
    return 1;
}

int countIf_(const int *const a, const size_t n, int (*predicate)(int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += predicate(a[i]);
    return count;
}

void deleteIf_(int *const a, size_t *const n, int (*deletePredicate)(int)) {
    size_t iRead = 0;
    while (iRead < *n && !deletePredicate(a[iRead]))
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (!deletePredicate(a[iRead])) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;
}

void forEach_(const int *source, int *dest, const size_t n, const int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        dest[i] = predicate(source[i]);
}

size_t binarySearch_(const int *a, size_t n, int x) {
    size_t left = 0;
    size_t right = n - 1;
    while (left <= right) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return SIZE_MAX;
}

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x) {
    if (a[0] >= x)
        return 0;
    size_t left = 0;
    size_t right = n;
    while (right - left > 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }
    return right;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void universSwap(void *a, void *b, const size_t baseSizeType) {
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


//void selectionSort(const long long *a, const int size) {
//    for (int i = 0; i < size - 1; i++) {
//        long long minPos = i;
//        for (int j = i + 1; j < size; j++)
//            if (a[j] < a[minPos])
//                minPos = j;
//        universSwap(&a[i], &a[minPos], sizeof(long long));
//    }
//}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int countNUnique(long long *a, int *n) {
    if (n == 1)
        return 1;

    qsort(a, n, sizeof(long long), cmp_long_long);

    int counterOfUnique = 1;
    int i = 1;
    while (i < n) {
        if (a[i] != a[i - 1])
            counterOfUnique++;
        i++;
    }
    return counterOfUnique;
}

//???????????????????? ?????????????? ?????????????????????????? ???????????????? ?????????????? ?? ?????????????? n
//int getMax(const int *a, const size_t n) {
//    if (n < 1)
//    throwExceptionEmptyArray();
//
//    int max = a[0];
//    for (int i = 1; i < n; i++)
//        if (a[i] > max)
//            max = a[i];
//
//    return max;
//}

bool isOrdered(const int *a, size_t size) {
    int i = 1;
    while (a[i] >= a[i - 1] && i < size)
        i++;

    return i == size ? true : false;
}
