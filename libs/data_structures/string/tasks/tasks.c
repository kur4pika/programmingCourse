#include "tasks.h"

#include "../string.h"

// task 1

// удаляет из строки s все пробельные символы
void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}




// task 2

// удаляет пробелы между словами строки s до одного
void removeExtraSpaces(char *s) {
    char *begin = ++s;
    while (*begin != '\0') {
        if (isspace(*begin) && isspace(*(s - 1))) {
            begin++;
            continue;
        }

        *(s++) = *begin;
        begin++;
    }

    *s = '\0';
}



// task 3

void digitToStart(wordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartInWordsOfString(char *s) {
    char *beginSearch = s;
    wordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

void reverseLettersOfWord(wordDescriptor word) {
    char *endStringBuffer = copyReverse(word.begin, word.end, _stringBuffer);
    copyReverse(endStringBuffer - 1, _stringBuffer, word.begin);
}

void reverseLettersOfWordsOfString(char *s) {
    char *beginSearch = &s[strlen(s)];
    wordDescriptor word;
    while (getWordReverse(beginSearch, s - 1, &word)) {
        reverseLettersOfWord(word);
        beginSearch = word.end;
    }
}



// task 4

// заменяет каждую цифру в строке s на соотвутсвующее число пробелов
void replaceDigitsWithSpaces(char *s) {
    memcpy(_stringBuffer, s, strlen(s) + 1);

    int i = 0;
    while (_stringBuffer[i] != '\0') {
        if (isdigit(_stringBuffer[i])) {
            int digit = _stringBuffer[i++] % '0';
            memcpy(s, _stringSpaces, digit);
            s += digit;

            continue;
        }

        *(s++) = _stringBuffer[i++];
    }

    *s = '\0';
}



// task 5

#include <stdio.h>
// заменяет все вхождения слова w1 на слово w2 строки sourse
void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    wordDescriptor word2 = {w2, w2 + w2Size};

    char *beginSearch = source;
    wordDescriptor word;

    if (w1Size >= w2Size)
        while (getWord(beginSearch, &word)) {
            if (strcmp(w1, word.begin) == 0) {
                char *endDst = copy(word2.begin, word2.end, word.begin);
                memcpy(endDst, _stringSpaces, w1Size - w2Size);
            }

            beginSearch = word.end;
        }
    else {
        size_t sourceLen = strlen(source);
        memcpy(_stringBuffer, source, sourceLen);

        while (getWord(beginSearch, &word)) {
            beginSearch = word.end;

            if (strcmp(w1, word.begin) == 0) {
                beginSearch += (w2Size - w1Size);
                memcpy(word.begin, w2, w2Size);
                long long endStringBuffer = word.end - source;
                memcpy(beginSearch, &_stringBuffer[endStringBuffer], sourceLen - endStringBuffer);
            }
        }
    }
}