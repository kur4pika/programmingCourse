#include "test_tasks.h"

#include "../tasks.h"
#include "../../string.h"
#include <assert.h>
#include <stdio.h>

void test_removeNonLetters_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_removeNonLetters_withoutSpace() {
    char s[MAX_STRING_SIZE] = "kurapika";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_removeNonLetters_allSpaceSymbols() {
    char s[MAX_STRING_SIZE] = "\t \n    \n \t";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_removeNonLetters_withSpace() {
    char s[MAX_STRING_SIZE] = "k u\tr a p i\r\tk a";

    removeNonLetters(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_removeNonLetters() {
    test_removeNonLetters_emptyString();
    test_removeNonLetters_withoutSpace();
    test_removeNonLetters_allSpaceSymbols();
    test_removeNonLetters_withSpace();
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

void test_removeExtraSpaces_stringWithoutSpaces() {
    char s[MAX_STRING_SIZE] = "kurapika";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_removeExtraSpaces_stringWithSpaces() {
    char s[MAX_STRING_SIZE] = "   k  ura   pi k    a  ";

    removeExtraSpaces(s);

    char expectation[MAX_STRING_SIZE] = " k ura pi k a ";

    assert(strcmp(s, expectation) == 0);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_allSpaces();
    test_removeExtraSpaces_stringWithoutSpaces();
    test_removeExtraSpaces_stringWithSpaces();
}



void test_reverseLettersOfWordsOfString_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    reverseLettersOfWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_reverseLettersOfWordsOfString_oneWord() {
    char *s = "kurapika";

    reverseLettersOfWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "akiparuk";

    assert(strcmp(s, expectation) == 0);
}

void test_reverseLettersOfWordsOfString_fewWords() {
    char *s = "kurapika BEST BOY";

    reverseLettersOfWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "akiparuk TSEB YOB";

    assert(strcmp(s, expectation) == 0);
}

void test_reverseLettersOfWordsOfString() {
    test_reverseLettersOfWordsOfString_emptyString();
    test_reverseLettersOfWordsOfString_oneWord();
    test_reverseLettersOfWordsOfString_fewWords();
}




void test_replaceDigitsWithSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    replaceDigitsWithSpaces(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_replaceDigitsWithSpaces_stringWithoutDigit() {
    char s[MAX_STRING_SIZE] = "kurapika";

    replaceDigitsWithSpaces(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_replaceDigitsWithSpaces_stringWithDigits() {
    char s[MAX_STRING_SIZE] = "kur3apik1a";

    replaceDigitsWithSpaces(s);

    char expectation[MAX_STRING_SIZE] = "kur   apik a";

    assert(strcmp(s, expectation) == 0);
}

void test_replaceDigitsWithSpaces_allDigit() {
    char s[MAX_STRING_SIZE] = "42";

    replaceDigitsWithSpaces(s);

    char expectation[MAX_STRING_SIZE] = "      ";

    assert(strcmp(s, expectation) == 0);
}

void test_replaceDigitsWithSpaces() {
    test_replaceDigitsWithSpaces_emptyString();
    test_replaceDigitsWithSpaces_stringWithoutDigit();
    test_replaceDigitsWithSpaces_stringWithDigits();
    test_replaceDigitsWithSpaces_allDigit();
}



void test_replace_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    char w1[MAX_STRING_SIZE] = "kurapika";
    char w2[MAX_STRING_SIZE] = "emo boy";

    replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_replace_w1MoreW2() {
    char s[MAX_STRING_SIZE] = "kurapi ka";
    char w1[MAX_STRING_SIZE] = "ka";
    char w2[MAX_STRING_SIZE] = "a";

    replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "kurapi a ";

    assert(strcmp(s, expectation) == 0);
}

void test_replace_w1EqualsW2() {
    char s[MAX_STRING_SIZE] = "kurapi ka";
    char w1[MAX_STRING_SIZE] = "ka";
    char w2[MAX_STRING_SIZE] = "pa";

    replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "kurapi pa";

    assert(strcmp(s, expectation) == 0);
}

void test_replace_w1LessW2() {
    char s[MAX_STRING_SIZE] = "kur a pik a";
    char w1[MAX_STRING_SIZE] = "a";
    char w2[MAX_STRING_SIZE] = "pico";

    replace(s, w1, w2);

    char expectation[MAX_STRING_SIZE] = "kur pico pik pico";

    assert(strcmp(s, expectation) == 0);
}

void test_replace() {
    test_replace_emptyString();
    test_replace_w1MoreW2();
    test_replace_w1EqualsW2();
    test_replace_w1LessW2();
}



void test_areWordsOfStringLexicographicallyOrdered_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(areWordsOfStringLexicographicallyOrdered(s) == true);
}

void test_areWordsOfStringLexicographicallyOrdered_twoWordsEquals() {
    char s[MAX_STRING_SIZE] = "kurapika kurapika";

    assert(areWordsOfStringLexicographicallyOrdered(s) == true);
}

void test_areWordsOfStringLexicographicallyOrdered_w1LessW2() {
    char s[MAX_STRING_SIZE] = "kurapik kurapika";

    assert(areWordsOfStringLexicographicallyOrdered(s) == true);
}

void test_areWordsOfStringLexicographicallyOrdered_w1MoreW2() {
    char s[MAX_STRING_SIZE] = "kurapika kurapik";

    assert(areWordsOfStringLexicographicallyOrdered(s) == false);
}

void test_areWordsOfStringLexicographicallyOrdered() {
    test_areWordsOfStringLexicographicallyOrdered_emptyString();
    test_areWordsOfStringLexicographicallyOrdered_twoWordsEquals();
    test_areWordsOfStringLexicographicallyOrdered_w1LessW2();
    test_areWordsOfStringLexicographicallyOrdered_w1MoreW2();
}



void test_printWordsOfStringReverse() {
    char s[MAX_STRING_SIZE] = "kurapik kurapika kur";

    printWordsOfStringReverse(s);
}



void test_getCountOfWordsPalindromes_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(getCountOfWordsPalindromes(s) == 0);
}

void test_getCountOfWordsPalindromes_nonPalindrome() {
    char s[MAX_STRING_SIZE] = "kurapik,BES,BOY";

    assert(getCountOfWordsPalindromes(s) == 0);
}

void test_getCountOfWordsPalindromes_onePalindrome() {
    char s[MAX_STRING_SIZE] = "kurapik BESTSEB BOY";

    assert(getCountOfWordsPalindromes(s) == 1);
}

void test_getCountOfWordsPalindromes_allPalindrome() {
    char s[MAX_STRING_SIZE] = "kurapikakiparuk BESTSEB BOYOB";

    assert(getCountOfWordsPalindromes(s) == 3);
}

void test_getCountOfWordsPalindromes() {
    test_getCountOfWordsPalindromes_emptyString();
    test_getCountOfWordsPalindromes_nonPalindrome();
    test_getCountOfWordsPalindromes_onePalindrome();
    test_getCountOfWordsPalindromes_allPalindrome();
}



void test_getStringWithAlternatingWords_emptyStrings() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    char *s = getStringWithAlternatingWords(s1, s2);
    printf("%s", s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_getStringWithAlternatingWords_stringLengthsEquals() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = "zharik";

    char *s = getStringWithAlternatingWords(s1, s2);

    char expectation[MAX_STRING_SIZE] = "kurapika zharik";

    assert(strcmp(s, expectation) == 0);
}

void test_getStringWithAlternatingWords_length1MoreLength2() {
    char s1[MAX_STRING_SIZE] = "kurapika kuruta";
    char s2[MAX_STRING_SIZE] = "zharik";

    char *s = getStringWithAlternatingWords(s1, s2);

    char expectation[MAX_STRING_SIZE] = "kurapika zharik kuruta";

    assert(strcmp(s, expectation) == 0);
}

void test_getStringWithAlternatingWords_length1LessLength2() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = "zharik kuruta";

    char *s = getStringWithAlternatingWords(s1, s2);

    char expectation[MAX_STRING_SIZE] = "kurapika zharik kuruta";

    assert(strcmp(s, expectation) == 0);
}

void test_getStringWithAlternatingWords() {
    test_getStringWithAlternatingWords_emptyStrings();
    test_getStringWithAlternatingWords_stringLengthsEquals();
    test_getStringWithAlternatingWords_length1MoreLength2();
    test_getStringWithAlternatingWords_length1LessLength2();
}

void test_tasks() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    //test_reverseLettersOfWordsOfString();
    test_replaceDigitsWithSpaces();
    test_replace();
    test_areWordsOfStringLexicographicallyOrdered();
    //test_printWordsOfStringReverse();
    test_getCountOfWordsPalindromes();
    test_getStringWithAlternatingWords();
}