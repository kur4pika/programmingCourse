#include "test_tasks.h"

#include "../tasks.h"
#include "../../string.h"
#include <assert.h>


void test_removeNonLetters() {
    char s[MAX_STRING_SIZE] = "k u\tr a p\r\ti k a";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_tasks() {
    test_removeNonLetters();
}