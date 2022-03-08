#include "tasks.h"

#include "../string.h"
#include <stdio.h>

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

// заменяет все вхождения слова w1 на слово w2 строки source
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
        memcpy(_stringBuffer, source, sourceLen + 1);

        while (getWord(beginSearch, &word)) {
            beginSearch = word.end;

            if (w1Size == word.end - word.begin && memcmp(w1, word.begin, w1Size) == 0) {
                beginSearch += (w2Size - w1Size);
                memcpy(word.begin, w2, w2Size);
                long long endStringBuffer = word.end - source;
                if (_stringBuffer[endStringBuffer] != '\0')
                    memcpy(beginSearch, &_stringBuffer[endStringBuffer], sourceLen - endStringBuffer);
            }
        }
    }
}


// task 6

// возвращает значение 'истина', если слова w1 и w2 упорядочены лексиграфически
bool areWordsLexicographicallyOrdered(wordDescriptor w1, wordDescriptor w2) {
    size_t w1Size = w1.end - w1.begin;
    size_t w2Size = w2.end - w2.begin;

    if (w1Size < w2Size) {
        while (w1.begin != w1.end)
            if (*(w1.begin++) != *(w2.begin++))
                return false;
    } else if (w1Size == w2Size) {
        while (w1.begin != w1.end)
            if (*(w1.begin++) > *(w2.begin++))
                return false;
    } else
        return false;

    return true;
}

// возвращает значение 'истина', если слова строки source упорядочены лексиграфически, иначе - 'ложь'
bool areWordsOfStringLexicographicallyOrdered(char *source) {
    char *beginSearch = source;
    wordDescriptor word1;
    wordDescriptor word2;

    if (!getWord(beginSearch, &word1))
        return true;
    beginSearch = word1.end;

    while (getWord(beginSearch, &word2)) {
        if (!areWordsLexicographicallyOrdered(word1, word2))
            return false;

        word1 = word2;
        beginSearch = word1.end;
    }

    return true;
}



// task 7

// выводит слова строки source в обратном порядке по одному в строке экрана
void printWordsOfStringReverse(char *source) {
    char *beginSearch = &source[strlen(source)];
    wordDescriptor word;
    while (getWordReverse(beginSearch, source - 1, &word)) {
        beginSearch = word.end;

        for (; ++word.end <= word.begin;)
            printf("%c", *word.end);


        printf("\n");
    }
}



// task 8

// возвращает значение 'истина', если слово является палиндромом, иначе - 'ложь'
bool isWordPalindrome(wordDescriptor word) {
    word.end--;
    for (; word.begin < word.end; word.begin++, word.end--)
        if (*word.begin != *word.end)
            return false;

    return true;
}

// возвращает количество слов-палиндромов в строке source
int getCountOfWordsPalindromes(char *source) {
    char *beginSearch = source;
    wordDescriptor word;

    int counterWordsPalindrome = 0;
    while (getWord(beginSearch, &word)) {
        if (isWordPalindrome(word))
            counterWordsPalindrome++;

        beginSearch = word.end;
    }

    return counterWordsPalindrome;
}



// task 9

// возвращает указатель на начало строки, в которой чередуются слова первой и второй строки
char *getStringWithAlternatingWords(char *ch1, char *ch2) {
    memcpy(_stringBuffer, _stringSpaces, MAX_STRING_SIZE);
    char *beginSearch1 = ch1, *beginSearch2 = ch2;
    char *endStr = _stringBuffer - 1;

    wordDescriptor word1, word2;
    bool isW1Found, isW2Found;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found){
            endStr = copy(word1.begin, word1.end, endStr + 1);
            beginSearch1 = word1.end;
        }
        if (isW2Found){
            endStr = copy(word2.begin, word2.end, endStr + 1);
            beginSearch2 = word2.end;
        }
    }

    *(endStr + (endStr == _stringBuffer - 1)) = '\0';

    return _stringBuffer;
}