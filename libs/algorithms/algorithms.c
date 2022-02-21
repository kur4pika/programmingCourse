#include "algorithms.h"

int min(int a, int b) {
    return a < b ? a : b;
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
