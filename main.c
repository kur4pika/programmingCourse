#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "libs/data_structures/string/string.h"

void test_strlen_stringEmpty() {
    char *s = "";

    assert(strlen(s) == 0);
}

void test_strlen_stringWithSpace() {
    char *s = "Hello world!";

    assert(strlen(s) == 12);

}

void test_strlen_stringWithoutSpace() {
    char *s = "kurapika";

    assert(strlen(s) == 8);
}

void test_strlen() {
    test_strlen_stringEmpty();
    test_strlen_stringWithSpace();
    test_strlen_stringWithoutSpace();
}

void test_find_stringIsElement() {
    char *s = "kurapika";

    assert(*(find(s, "\0", 'p')) == 'p');
}

void test_find_stringNoElement() {
    char *s = "kurapika";

    assert(*(find(s, "\0", 'w')) == '\0');
}

void test_find() {
    test_find_stringIsElement();
    test_find_stringNoElement();
}

void test_findNonSpace_stringWithoutSpace() {
    char *s = "kurapika";

    assert(*(findNonSpace(s)) == 'k');
}

void test_findNonSpace_stringWithSpace() {
    char *s = "\t \n \r \t \r w";

    assert(*(findNonSpace(s)) == 'w');
}

void test_findNonSpace_stringSpace() {
    char *s = "   ";

    assert(*(findNonSpace(s)) == '\0');
}

void test_findNonSpace_stringEmpty() {
    char *s = "";

    assert(*(findNonSpace(s)) == '\0');
}

void test_findNonSpace() {
    test_findNonSpace_stringWithoutSpace();
    test_findNonSpace_stringWithSpace();
    test_findNonSpace_stringSpace();
    test_findNonSpace_stringEmpty();
}

void test_findSpace_stringWithSpace() {
    char *s = "kurapika space";

    assert(*(findSpace(s)) == *(s + 8));
}

void test_findSpace_stringWithoutSpace() {
    char *s = "kurapikaspace";

    assert(*(findSpace(s)) == '\0');
}

void test_findSpace_stringEmpty() {
    char *s = "";

    assert(*(findSpace(s)) == '\0');
}

void test_findSpace() {
    test_findSpace_stringWithSpace();
    test_findSpace_stringWithoutSpace();
    test_findSpace_stringEmpty();
}

void test_findNonSpaceReverse_stringWithoutSpace() {
    char *s = "kurapika";

    assert(*(findNonSpaceReverse(s + 7, s - 1)) == 'a');
}

void test_findNonSpaceReverse_stringWithSpace() {
    char *s = "  \t    \t k u r a p i k a\t     \r   \t";

    assert(*(findNonSpaceReverse(s + 34, s - 1)) == 'a');
}

void test_findNonSpaceReverse_stringEmpty() {
    char *s = "";

    assert(*(findNonSpaceReverse(s, s - 1)) == '\0');
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_stringWithoutSpace();
    test_findNonSpaceReverse_stringWithSpace();
    test_findNonSpaceReverse_stringEmpty();
}

void test_findSpaceReverse_stringWithoutSpace() {
    char *s = "kurapika";

    assert(*(findSpaceReverse(s + 7, s - 1)) == *(s - 1));
}

void test_findSpaceReverse_stringWithSpace() {
    char *s = "  \t    \t k u r a p i k a\t     \r   \t";

    assert(*(findSpaceReverse(s + 34, s - 1)) == '\t');
}

void test_findSpaceReverse_stringSpace() {
    char *s = "";

    assert(*(findSpaceReverse(s, s - 1)) == '\0');
}

void test_findSpaceReverse() {
    test_findSpaceReverse_stringWithoutSpace();
    test_findSpaceReverse_stringWithoutSpace();
    test_findSpaceReverse_stringSpace();
}

void test_strcmp_stringEqual() {
    char *s1 = "kurapika";
    char *s2 = "kurapika";

    assert(strcmp(s1, s2) == 0);
}

void test_strcmp_stringNonEqual_firstGreaterSecond() {
    char *s1 = "death";
    char *s2 = "life";

    assert(strcmp(s1, s2) == 'd' - 'l');
}

void test_strcmp_stringNonEqual_secondGreaterFirst() {
    char *s1 = "kurapika";
    char *s2 = "BEST BOY";

    assert(strcmp(s1, s2) == 'k' - 'B');
}

void test_strcmp() {
    test_strcmp_stringEqual();
    test_strcmp_stringNonEqual_firstGreaterSecond();
    test_strcmp_stringNonEqual_secondGreaterFirst();
}

void test_copy_fullString() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = "        ";

    char *dst = copy(s1, s1 + 8, s2);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s2, expectation) == 0 && dst == &s2[strlen(s2)]);
}

void test_copy_partString() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = "    pico";

    char *dst = copy(s1 + 4, s1 + 8, s2);

    char expectation[MAX_STRING_SIZE] = "pikapico";

    assert(strcmp(s2, expectation) == 0 && dst == &s2[strlen(s2) - 4]);
}

void test_copy() {
    test_copy_fullString();
    test_copy_partString();
}

void test_copyIf_digit() {
    char s1[MAX_STRING_SIZE] = "k2r8p1k3";
    char s2[MAX_STRING_SIZE] = "  pico";

    char *dst = copyIf(s1 + 4, s1 + 8, s2, isdigit);

    char expectation[MAX_STRING_SIZE] = "13pico";

    assert(strcmp(s2, expectation) == 0 && dst == &s2[strlen(s2) - 4]);
}

void test_copyIf() {
    test_copyIf_digit();
}

void test_copyIfReverse_digit() {
    char s1[MAX_STRING_SIZE] = "k2r8p1k3";
    char s2[MAX_STRING_SIZE] = "    pico";

    char *dst = copyIfReverse(s1 + 8, s1, s2, isdigit);

    char expectation[MAX_STRING_SIZE] = "3182pico";

    assert(strcmp(s2, expectation) == 0 && dst == &s2[strlen(s2) - 4]);
}

void test_copyIfReverse() {
    test_copyIfReverse_digit();
}

void test() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}

int main() {
    test();

    return 0;
}