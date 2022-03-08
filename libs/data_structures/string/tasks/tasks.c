#include "tasks.h"

#include "../string.h"
#include <stdio.h>

#define EMPTY_STRING 0
#define NOT_FOUND_A_WORD_WITH_A 1
#define FIRST_WORD_WITH_A 2
#define WORD_FOUND 3

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

// перемещает в слове word цифры в начало, при этом инвертируя их
void digitToStart(wordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

// перемещает цифры в начало слов строки s, при этом инвертируя их
void digitToStartInWordsOfString(char *s) {
    char *beginSearch = s;
    wordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

// обращает слово word
void reverseLettersOfWords(wordDescriptor word) {
    char *endStringBuffer = copy(word.end + 1, word.begin + 1, _stringBuffer);
    copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.end + 1, isgraph);
}

// обращает каждое слово строки s
void reverseLettersOfWordsOfString(char *s) {
    char *beginSearch = &s[strlen(s) + 1];
    wordDescriptor word;
    while (getWordReverse(beginSearch, s - 1, &word)) {
        reverseLettersOfWords(word);
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

// возвращает значение 'истина', если слово word является палиндромом, иначе - 'ложь'
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

// возвращает указатель на начало строки, в которой чередуются слова первой ch1 и второй ch2 строки
char *getStringWithAlternatingWords(char *ch1, char *ch2) {
    memcpy(_stringBuffer, _stringSpaces, MAX_STRING_SIZE);
    char *beginSearch1 = ch1, *beginSearch2 = ch2;
    char *endStr = _stringBuffer - 1;

    wordDescriptor word1, word2;
    bool isW1Found, isW2Found;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            endStr = copy(word1.begin, word1.end, endStr + 1);
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            endStr = copy(word2.begin, word2.end, endStr + 1);
            beginSearch2 = word2.end;
        }
    }

    *(endStr + (endStr == _stringBuffer - 1)) = '\0';

    return _stringBuffer;
}



// task 10

// преобразоввывает строку s, изменяя порядок следования слов в строке на обратный
void reverseWordsOfString(char *source) {
    size_t sourceLen = strlen(source);
    copyReverse(source + sourceLen - 1, source - 1, _stringBuffer);
    memcpy(source, _stringBuffer, sourceLen);
    reverseLettersOfWordsOfString(source);
}



// task 11

// возвращает значение 'истина', если слова word содержит букву a, иначе - 'ложь'
bool isWordWithA(wordDescriptor word) {
    for (; word.begin < word.end; word.begin++)
        if (*word.begin == 'a')
            return true;

    return false;
}

// выводит слово word
void printWord(wordDescriptor word) {
    for (; word.begin < word.end; word.begin++)
        printf("%c", *word.begin);

    printf("\n");
}

// выводит слово, предшествующее первому из слов, содержащих букву "а"
void printWordBeforeFirstWordWithA(char *s) {
    char *beginSearch = s;
    wordDescriptor word;

    if (!getWord(beginSearch, &word)) {
        printf("there is no words in this string\n");
        return;
    } else if (isWordWithA(word)) {
        printf("first word with 'a' in this string\n");
        return;
    }
    beginSearch = word.end;

    wordDescriptor previousWord = word;

    bool isAinString = false;
    while (getWord(beginSearch, &word)) {
        if (isWordWithA(word)) {
            printWord(previousWord);
            isAinString = true;
            break;
        }

        previousWord = word;
        beginSearch = word.end;
    }

    if (!isAinString)
        printf("there is words with 'a' in this string");
}

// возвращает 0, если строка пуста,
// 1, если строка не содержит слов с "а",
// 2, если первое слово в строке содержит "а",
// 3, если слово с "а" не первое
int getWordBeforeFirstWordWithA(char *s) {
    char *beginSearch = s;
    wordDescriptor word;

    if (!getWord(beginSearch, &word))
        return EMPTY_STRING;
    else if (isWordWithA(word)) {
        return FIRST_WORD_WITH_A;
    }
    beginSearch = word.end;

    while (getWord(beginSearch, &word)) {
        if (isWordWithA(word))
            return WORD_FOUND;
        beginSearch = word.end;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}



// task 12

// возвращает значение 'истина', если слово word есть в строке source
bool isWordInString(char *source, wordDescriptor word) {
    char *beginSearch = source;
    wordDescriptor wordString;

    while (getWord(beginSearch, &wordString)) {
        size_t wordStringSize = wordString.end - wordString.begin;
        size_t wordSize = word.begin - word.end;
        if (wordStringSize == wordSize && memcmp(word.end + 1, wordString.begin, wordSize) == 0)
            return true;

        beginSearch = wordString.end;
    }

    return false;
}

// возвращает последнее из слов первой строки s1, которое есть во второй строке s2
wordDescriptor getLastWordInFirstStringFromSecondString(char *s1, char *s2) {
    char *beginSearch = s1 + strlen(s1) - 1;
    wordDescriptor word;

    while (getWordReverse(beginSearch, s1 - 1, &word)) {
        if (isWordInString(s2, word)){
            char *t = word.begin;
            word.begin = word.end + 1;
            word.end = t + 1;
            return word;
        }

        beginSearch = word.end;
    }

    return (wordDescriptor) {NULL, NULL};
}

void wordDescriptorToString(wordDescriptor word, char *destination){
    for (; word.begin < word.end; word.begin++)
        *(destination++) = *word.begin;

    *destination = '\0';
}