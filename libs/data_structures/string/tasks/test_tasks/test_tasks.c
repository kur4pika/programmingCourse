#include "test_tasks.h"

#include "../tasks.h"
#include "../../string.h"
#include <assert.h>
#include <stdio.h>

void test_removeNonLetters_withoutSpace() {
    char s[MAX_STRING_SIZE] = "kurapika";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_removeNonLetters_withSpace() {
    char s[MAX_STRING_SIZE] = "k u\tr a p i\r\tk a";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_removeNonLetters_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_removeNonLetters_allSpaceSymbols() {
    char s[MAX_STRING_SIZE] = "\t \n    \n \t";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_removeNonLetters() {
    test_removeNonLetters_withoutSpace();
    test_removeNonLetters_withSpace();
    test_removeNonLetters_emptyString();
    test_removeNonLetters_allSpaceSymbols();

}



void test_removeExtraSpaces_stringWithSpaces() {
    char s[MAX_STRING_SIZE] = "   k  ura   pi k    a  ";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = " k ura pi k a ";

    assert(strcmp(s, expectation) == 0);
}

void test_removeExtraSpaces_stringWithoutSpaces() {
    char s[MAX_STRING_SIZE] = "kurapika";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_removeExtraSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_removeExtraSpaces_allSpaces() {
    char s[MAX_STRING_SIZE] = "            ";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = " ";

    assert(strcmp(s, expectation) == 0);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_stringWithSpaces();
    test_removeExtraSpaces_stringWithoutSpaces();
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_stringWithSpaces();
    test_removeExtraSpaces_allSpaces();

}

void test_tasks() {
    test_removeNonLetters();
    test_removeExtraSpaces();

}