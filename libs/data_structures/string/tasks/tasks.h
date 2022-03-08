#ifndef MAIN_C_TASKS_H
#define MAIN_C_TASKS_H

#include <stdbool.h>
#include "../string.h"

void removeNonLetters(char *s);// удаляет из строки s все пробельные символы

void removeExtraSpaces(char *s);// удаляет пробелы между словами строки s до одного

void digitToStartInWordsOfString(char *s);// перемещает цифры в начало слов строки s, при этом инвертируя их

void reverseLettersOfWordsOfString(char *s);// обращает каждое слово строки s

void replaceDigitsWithSpaces(char *s);// заменяет каждую цифру в строке s на соотвутсвующее число пробелов

void replace(char *source, char *w1, char *w2);// заменяет все вхождения слова w1 на слово w2 строки source

bool areWordsOfStringLexicographicallyOrdered(char *source);// возвращает значение 'истина', если слова строки source
                                                            // упорядочены лексиграфически, иначе - 'ложь'

void printWordsOfStringReverse(char *source);// выводит слова строки source в обратном порядке по одному в строке экрана

int getCountOfWordsPalindromes(char *source);// возвращает количество слов-палиндромов в строке source

char *getStringWithAlternatingWords(char *ch1, char *ch2);// возвращает указатель на начало строки, в которой чередуются
                                                          // слова первой ch1 и второй ch2 строки

void reverseWordsOfString(char *source);// преобразоввывает строку s, изменяя порядок следования слов в строке на обратный

void printWordBeforeFirstWordWithA(char *s);// выводит слово, предшествующее первому из слов, содержащих букву "а"

int getWordBeforeFirstWordWithA(char *s);

wordDescriptor getLastWordInFirstStringFromSecondString(char *s1, char *s2);// возвращает последнее из слов первой строки s1,
                                            // которое есть во второй строке s2

void wordDescriptorToString(wordDescriptor word, char *destination);

#endif //MAIN_C_TASKS_H
