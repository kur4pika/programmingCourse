#include "test_sorts.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../../array/array.h"
#include "../sorts.h"
#include "../../generating/generating.h"


#define TIME_TEST(testCode, time) { \
    clock_t start_time = clock(); \
    testCode \
    clock_t end_time = clock();\
    clock_t sort_time = end_time - start_time; \
    time = (double) sort_time / CLOCKS_PER_SEC; \
}

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// функция сортировки
typedef struct SortFunc {
    void (*sort )(int *a, size_t n); // указатель на функцию сортировки
    char name[64]; // имя сортировки, используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n); // указатель на функцию генерации последоват.
    char name[64]; // имя генератора, используемое при выводе
} GeneratingFunc;

void
checkTime(void (*sortFunc)(int *, size_t), void (*generateFunc)(int *, size_t), size_t size, char *experimentName) {
    static size_t runCounter = 1;

    // генерация последовательности
    static int innerBuffer[150000];
    generateFunc(innerBuffer, size);
    printf("Run#%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    // замер времени
    double time;
    TIME_TEST ({ sortFunc(innerBuffer, size); }, time);

    // результаты замера
    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time: %.3f s.\n", time);

        // запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");

        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }

        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong!\n");

        // вывод массива, который не смог быть отсортирован
        outputArray_(innerBuffer, size);

        exit(1);
    }
}

void timeExperiment() {
    // описание функций сортировки
    SortFunc sorts[] = {
            {insertionSort, "insertionSort"},
            {combSort, "combSort"},
            {shellSort, "shellSort"},
            {radixSort, "radixSort"}
    };

    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            // генерируется случайный массив
            {generateRandomArray,           "random"},
            // генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,          "ordered"},
            // генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwardsArray, "orderedBackwards"}
    };

    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    // запись статистики в файл
    for (size_t size = 100000; size <= 150000; size += 5000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("Size: %zu\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_time ",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}

void checkCountComparisonOperations(long long (*sortFunc)(int *, size_t), void (*generateFunc)(int *, size_t), size_t size, char *experimentName) {
    static size_t runCounter = 1;
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    long long countComparisonOperations = {
            sortFunc(innerBuffer, size)
    };

    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Count comparison operations: %lld\n", countComparisonOperations);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %lld\n", size, countComparisonOperations);
        fclose(f);
    } else {
        printf("Wrong!\n");

        outputArray_(innerBuffer, size);

        exit(1);
    }
}

void countComparisonOperationsExperiment() {
    SortFuncComparisonOperations sorts[] = {
            {getBubbleSortNComp,    "bubbleSort"},
            {getInsertionSortNComp, "insertionSort"},
            {getSelectionSortNComp, "selectionSort"},
            {getCombSortNComp,      "combsort"},
            {getShellSortNComp,     "shellSort"},
            {getRadixSortNComps,    "radixSort"}
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    GeneratingFunc generatingFuncs[] = {
            {generateRandomArray,      "random"},
            {generateOrderedArray,     "ordered"},
            {generateOrderedBackwardsArray, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("-----------------");
        printf("Size: %zu\n", size);
        for (int i = 0; i < FUNCS_N; ++i) {
            for (int j = 0; j < CASES_N; ++j) {
                static char filename[128];
                sprintf(filename, "%s_%s_comparisonOperations", sorts[i].name, generatingFuncs[j].name);
                checkCountComparisonOperations(sorts[i].sort, generatingFuncs[j].generate, size, filename);
            }
        }
        printf("\n");
    }
}


