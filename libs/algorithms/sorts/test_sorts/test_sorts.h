#ifndef MAIN_C_TEST_SORTS_H
#define MAIN_C_TEST_SORTS_H

#include <stdint.h>

void timeExperiment();

typedef struct SortFuncComparisonOperations{
    long long (*sort)(int *a, size_t n);
    char name[64];
} SortFuncComparisonOperations;

void countComparisonOperationsExperiment();

#endif //MAIN_C_TEST_SORTS_H
