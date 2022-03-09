#include "tasks.h"

#include "../string.h"
#include <stdio.h>
#include <stdlib.h>

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
        if (*word.begin == 'a' || *word.begin == 'A')
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
bool isWordInString(char *source, char *w1Begin, char *w1End) {
    char *beginSearch = source;
    wordDescriptor wordString;

    while (getWord(beginSearch, &wordString)) {
        size_t wordStringSize = wordString.end - wordString.begin;
        size_t wordSize = w1End - w1Begin;
        if (wordStringSize == wordSize && memcmp(w1Begin, wordString.begin, wordSize) == 0)
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
        if (isWordInString(s2, word.end + 1, word.begin + 1)) {
            char *t = word.begin;
            word.begin = word.end + 1;
            word.end = t + 1;
            return word;
        }

        beginSearch = word.end;
    }

    return (wordDescriptor) {NULL, NULL};
}

// записыавет слово word в строку destination
void wordDescriptorToString(wordDescriptor word, char *destination) {
    for (; word.begin < word.end; word.begin++)
        *(destination++) = *word.begin;

    *destination = '\0';
}



// task 13

// возвращает значение 'истина', если в строке source есть одинаковые слова, иначе - 'ложь'
bool isEqualWordsInString(char *source) {
    char *beginSearch = source;
    wordDescriptor word;

    while (getWord(beginSearch, &word)) {
        beginSearch = word.end;

        if (isWordInString(beginSearch, word.begin, word.end))
            return true;
    }

    return false;
}



// task 14

int compare_char(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;

    return 0;
}

// возвращает значение истина, если в строке source есть пара слов, составленная из одинаковых букв
bool isLettersOfWordsInStringEqual(char *source) {
    memcpy(_stringBuffer, source, strlen(source) + 1);

    char *beginSearch = _stringBuffer;
    wordDescriptor word;

    while (getWord(beginSearch, &word)) {
        qsort(word.begin, word.end - word.begin, sizeof(char), compare_char);
        beginSearch = word.end;
    }

    return isEqualWordsInString(_stringBuffer);
}



// task 15

// возвращает указатель на строку, состоящую из слов строки source, которые отличны от последнего слова
char *getStringFromWordsWhichDifferentFromLastWord(char *source) {
    char *beginSearch = source + strlen(source) - 1;
    wordDescriptor lastWord;

    if (!getWordReverse(beginSearch, source - 1, &lastWord))
        return "\0";
    size_t lastWordSize = lastWord.begin - lastWord.end;

    beginSearch = source;
    wordDescriptor word;

    memcpy(_stringBuffer, _stringSpaces, MAX_STRING_SIZE);
    char *endStringBuffer = _stringBuffer - 1;
    while (getWord(beginSearch, &word)) {
        size_t wordSize = word.end - word.begin;
        if (wordSize != lastWordSize || memcmp(word.begin, lastWord.end + 1, wordSize) != 0)
            endStringBuffer = copy(word.begin, word.end, endStringBuffer + 1);

        beginSearch = word.end;
    }

    *(endStringBuffer + (endStringBuffer == _stringBuffer - 1)) = '\0';

    return _stringBuffer;
}



// task 17

// удаляет из строки source слова-палиндромы
void deleteWordsPalindromesFromString(char *source) {
    memcpy(_stringBuffer, source, strlen(source));
    char *beginSearch = _stringBuffer;
    wordDescriptor word;

    memcpy(source, _stringSpaces, MAX_STRING_SIZE);
    char *endSource = source - 1;

    while (getWord(beginSearch, &word)) {
        if (!isWordPalindrome(word))
            endSource = copy(word.begin, word.end, endSource + 1);

        beginSearch = word.end;
    }

    *(endSource + (endSource == source - 1)) = '\0';
}



// task 18

// возвращает количество слов в строке source
int getCountOfWordsOfString(char *source) {
    char *beginSearch = source;
    wordDescriptor word;

    int counterWords = 0;
    while (getWord(beginSearch, &word)) {
        counterWords++;

        beginSearch = word.end;
    }

    return counterWords;
}

// дополняет строку s1 последними словами строки s2
void addToLowerStringLastWordsOfHigherString_(char *s1, size_t s1Size, size_t s1CountWords, char *s2, size_t s2Size, size_t s2CountWord){
    s1[s1Size] = ' ';
    char *beginSearch = s2 + s2Size;
    wordDescriptor word;

    char *endStr = s1 + s1Size;
    while (getWordReverse(beginSearch, s2 - 1, &word)) {
        endStr = copy(word.end + 1, word.begin + 1, endStr + 1);
        *endStr = ' ';

        if (--s2CountWord == s1CountWords)
            break;

        beginSearch = word.end;
    }

    *(endStr) = '\0';
}

// дополняет строку s1 или s2, содержащую меньшее количество слов, последними
// словами строки, в которой содержится большее количество слов.
void addToLowerStringLastWordsOfHigherString(char *s1, char *s2) {
    size_t s1Size = strlen(s1);
    size_t s2Size = strlen(s2);

    size_t s1CountWords = getCountOfWordsOfString(s1);
    size_t s2CountWords = getCountOfWordsOfString(s2);

    if (s1CountWords < s2CountWords)
        addToLowerStringLastWordsOfHigherString_(s1, s1Size, s1CountWords, s2, s2Size, s2CountWords);
    else if (s2CountWords < s1CountWords)
        addToLowerStringLastWordsOfHigherString_(s2, s2Size, s2CountWords, s1, s1Size, s1CountWords);
}