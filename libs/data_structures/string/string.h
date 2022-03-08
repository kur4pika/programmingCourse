#ifndef MAIN_C_STRING_H
#define MAIN_C_STRING_H

#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

static char _stringBuffer[MAX_STRING_SIZE];
static char *_stringSpaces = "                                ";

size_t strlen(const char *begin);// возвращает количество символов в строке

char *find(char *begin, char *end, int ch);// возвращает указатель на первый элемент с кодом ch,
// расположенным на ленте памяти между адресами begin и end не включая end
// Если символ не найден, возвращается значение end

char *findNonSpace(char *begin);// возвращает указатель на первый символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа

char *findSpace(char *begin);// возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ

char *findNonSpaceReverse(char *rbegin, const char *rend);// возвращает указатель на первый справа символ,
// отличный от пробельных, расположенный на ленте памяти,
// начиная с rbegin (последний символ строки, за которым
// следует ноль-символ) и заканчивая rend (адрес символа
// перед началом строки).
// Если символ не найден, возвращается адрес rend

char *findSpaceReverse(char *rbegin, const char *rend);// возвращает указатель на первый пробельный символ справа,
// расположенный на ленте памяти, начиная с rbegin и
// заканчивая rend.
// Если символ не найден, возвращается адрес rend

char *
copy(const char *beginSource, const char *endSource, char *beginDestination);// записывает по адресу beginDestination
// фрагмент памяти, начиная с адреса beginSource до endSource
// Возвращает указатель на следующий свободный фрагмент памяти в destination

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination);
// записывает по адресу beginDestination
// фрагмент памяти, начиная с адреса rbeginSource до rendSource
// Возвращает указатель на следующий слева свободный фрагмент памяти в destination

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));// записывает по адресу
// beginDestination элементы из фрагмента памяти начиная с beginSource
// заканчивая endSource, удовлетворяющие функции-предикату f.
// возвращает указатель на следующий свободный для записи фрагмент в памяти

char *
copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)); //записывает по адресу
// beginDestination элементы из фрагмента памяти начиная с rbeginSource заканчивая
// rendSource, удовлетворяющие функции-предикату f.
// возвращает значение beginDestination по окончанию работы функции

int strcmp(const char *lhs, const char *rhs);// возвращает отрицательное значение, если lhs располагается до rhs
// в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs равны,
// иначе – положительное значение.

typedef struct wordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} wordDescriptor;

char *getEndOfString(char *s);// возвращает указатель на конец строки s

bool getWord(char *beginSearch, wordDescriptor *word);// возвращает 'истина' и записывает в word.begin адрес начала слова,
                                                    // а в word.end адрес конца слова, если слово найдено, иначе - 'ложь'

bool getWordReverse(char *rbegin, char *rend, wordDescriptor *word);// возвращает 'истина' и записывает в word.begin адрес
                                        // конца слова, а в word.end адрес начала слова, если слово найдено, иначе - 'ложь'

#endif //MAIN_C_STRING_H
