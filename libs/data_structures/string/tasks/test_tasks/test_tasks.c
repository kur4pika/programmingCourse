#include "test_tasks.h"

#include "../tasks.h"
#include "../../string.h"
#include <assert.h>
#include <stdio.h>


#define EMPTY_STRING 0
#define NOT_FOUND_A_WORD_WITH_A 1
#define FIRST_WORD_WITH_A 2
#define WORD_FOUND 3

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


void test_digitToStartInWordsOfString_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    digitToStartInWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_digitToStartInWordsOfString_oneWord() {
    char s[MAX_STRING_SIZE] = "1kur4ap2ik8a2";

    digitToStartInWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "28241kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_digitToStartInWordsOfString_fewWords() {
    char s[MAX_STRING_SIZE] = "k2u4ra1pi8ka3 BE5S2T B1O2Y6";

    digitToStartInWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "38142kurapika 25BEST 621BOY";

    assert(strcmp(s, expectation) == 0);
}

void test_digitToStartInWordsOfString() {
    test_digitToStartInWordsOfString_emptyString();
    test_digitToStartInWordsOfString_oneWord();
    test_digitToStartInWordsOfString_fewWords();
}


void test_reverseLettersOfWordsOfString_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    reverseLettersOfWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_reverseLettersOfWordsOfString_oneWord() {
    char s[MAX_STRING_SIZE] = "kurapika";

    reverseLettersOfWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "akiparuk";

    assert(strcmp(s, expectation) == 0);
}

void test_reverseLettersOfWordsOfString_fewWords() {
    char s[MAX_STRING_SIZE] = "kurapika BEST BOY";

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


void test_reverseWordsOfString_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    reverseWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "";

    assert(strcmp(s, expectation) == 0);
}

void test_reverseWordsOfString_oneWord() {
    char s[MAX_STRING_SIZE] = "kurapika";

    reverseWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_reverseWordsOfString_twoWord() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta";

    reverseWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "kuruta kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_reverseWordsOfString_fewWord() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta zharik";

    reverseWordsOfString(s);

    char expectation[MAX_STRING_SIZE] = "zharik kuruta kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_reverseWordsOfString() {
    test_reverseWordsOfString_emptyString();
    test_reverseWordsOfString_oneWord();
    test_reverseWordsOfString_twoWord();
    test_reverseWordsOfString_fewWord();
}



void test_getWordBeforeFirstWordWithA_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(getWordBeforeFirstWordWithA(s) == EMPTY_STRING);
}

void test_getWordBeforeFirstWordWithA_noWordWithA() {
    char s[MAX_STRING_SIZE] = "kurpik kurut best boy";

    assert(getWordBeforeFirstWordWithA(s) == NOT_FOUND_A_WORD_WITH_A);
}

void test_getWordBeforeFirstWordWithA_firstWordWithA() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    assert(getWordBeforeFirstWordWithA(s) == FIRST_WORD_WITH_A);
}

void test_getWordBeforeFirstWordWithA_wordWithA() {
    char s[MAX_STRING_SIZE] = "kurpik kuruta best boy";

    assert(getWordBeforeFirstWordWithA(s) == WORD_FOUND);
}

void test_getWordBeforeFirstWordWithA() {
    test_getWordBeforeFirstWordWithA_emptyString();
    test_getWordBeforeFirstWordWithA_noWordWithA();
    test_getWordBeforeFirstWordWithA_firstWordWithA();
    test_getWordBeforeFirstWordWithA_wordWithA();
}



void test_getLastWordInFirstStringFromSecondString_emptyString() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    wordDescriptor word = getLastWordInFirstStringFromSecondString(s1, s2);

    assert(word.begin == 0 && word.end == 0);
}

void test_getLastWordInFirstStringFromSecondString_noWords() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "kurapika";

    wordDescriptor word = getLastWordInFirstStringFromSecondString(s1, s2);

    assert(word.begin == 0 && word.end == 0);
}

void test_getLastWordInFirstStringFromSecondString_oneWordsMatches() {
    char s1[MAX_STRING_SIZE] = "kurapika";
    char s2[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    wordDescriptor word = getLastWordInFirstStringFromSecondString(s1, s2);

    char s[MAX_STRING_SIZE];

    wordDescriptorToString(word, s);

    char expectation[MAX_STRING_SIZE] = "kurapika";

    assert(strcmp(s, expectation) == 0);
}

void test_getLastWordInFirstStringFromSecondString_fewWordsMatches() {
    char s1[MAX_STRING_SIZE] = "kurapika kuruta best boy";
    char s2[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    wordDescriptor word = getLastWordInFirstStringFromSecondString(s1, s2);

    char s[MAX_STRING_SIZE];

    wordDescriptorToString(word, s);

    char expectation[MAX_STRING_SIZE] = "boy";

    assert(strcmp(s, expectation) == 0);
}

void test_getLastWordInFirstStringFromSecondString() {
    test_getLastWordInFirstStringFromSecondString_emptyString();
    test_getLastWordInFirstStringFromSecondString_noWords();
    test_getLastWordInFirstStringFromSecondString_oneWordsMatches();
    test_getLastWordInFirstStringFromSecondString_fewWordsMatches();
}



void test_isEqualWordsInString_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    bool isEqualWords = isEqualWordsInString(s);

    assert(isEqualWords == 0);
}

void test_isEqualWordsInString_noEqualWords() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    bool isEqualWords = isEqualWordsInString(s);

    assert(isEqualWords == 0);
}

void test_isEqualWordsInString_equalWords() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta best boy kuruta";

    bool isEqualWords = isEqualWordsInString(s);

    assert(isEqualWords == 1);
}

void test_isEqualWordsInString() {
    test_isEqualWordsInString_emptyString();
    test_isEqualWordsInString_noEqualWords();
    test_isEqualWordsInString_equalWords();
}



void test_isLettersOfWordsInStringEqual_emptyString() {
    char s[MAX_STRING_SIZE] = "";

    assert(isLettersOfWordsInStringEqual(s) == 0);
}

void test_isLettersOfWordsInStringEqual_noLettersOfWordsEqual() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta best boy";

    assert(isLettersOfWordsInStringEqual(s) == 0);
}

void test_isLettersOfWordsInStringEqual_letterOfWordsEqual() {
    char s[MAX_STRING_SIZE] = "kurapika kuruta kuparika";

    assert(isLettersOfWordsInStringEqual(s) == 1);
}

void test_isLettersOfWordsInStringEqual() {
    test_isLettersOfWordsInStringEqual_emptyString();
    test_isLettersOfWordsInStringEqual_noLettersOfWordsEqual();
    test_isLettersOfWordsInStringEqual_letterOfWordsEqual();
}

void test_tasks() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitToStartInWordsOfString();
    test_reverseLettersOfWordsOfString();
    test_replaceDigitsWithSpaces();
    test_replace();
    test_areWordsOfStringLexicographicallyOrdered();
    //test_printWordsOfStringReverse();
    test_getCountOfWordsPalindromes();
    test_getStringWithAlternatingWords();
    test_reverseWordsOfString();
    test_getWordBeforeFirstWordWithA();
    test_getLastWordInFirstStringFromSecondString();
    test_isEqualWordsInString();
    test_isLettersOfWordsInStringEqual();
}