#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdbool.h>


int main() {
    matrix m = getMemMatrix(3, 3);

    inputMatrix(&m);

    printf("%d", isSymmetricMatrix(m));

    return 0;
}