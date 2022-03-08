#ifndef MAIN_C_TASKS_H
#define MAIN_C_TASKS_H

#include <stdbool.h>

void removeNonLetters(char *s);// удаляет из строки s все пробельные символы

void removeExtraSpaces(char *s);// удаляет пробелы между словами строки s до одного

void digitToStartInWordsOfString(char *s);

void reverseLettersOfWordsOfString(char *s);// обращает каждое слово строки s

void replaceDigitsWithSpaces(char *s);// заменяет каждую цифру в строке s на соотвутсвующее число пробелов

void replace(char *source, char *w1, char *w2);// заменяет все вхождения слова w1 на слово w2 строки source

bool areWordsOfStringLexicographicallyOrdered(char *source);// возвращает значение 'истина', если слова строки source
                                                            // упорядочены лексиграфически, иначе - 'ложь'

void printWordsOfStringReverse(char *source);// выводит слова строки source в обратном порядке по одному в строке экрана

int getCountOfWordsPalindromes(char *source);// возвращает количество слов-палиндромов в строке source

char *getStringWithAlternatingWords(char *ch1, char *ch2);//

#endif //MAIN_C_TASKS_H
