#include "string.h"

// возвращает количество символов в строке
size_t strlen(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

// возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end не включая end
// Если символ не найден, возвращается значение end
char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

// возвращает указатель на первый символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа
char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

// возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ
char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}


// возвращает указатель на первый справа символ, отличный от пробельных, расположенный на ленте памяти,
// начиная с rbegin (последний символ строки, за которым следует ноль-символ) и заканчивая
// rend (адрес символа перед началом строки).
// Если символ не найден, возвращается адрес rend
char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

// возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти, начиная с rbegin
// и заканчивая rend.
// Если символ не найден, возвращается адрес rend
char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

// возвращает отрицательное значение, если lhs118 располагается до rhs
// в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs равны,
// иначе – положительное значение.
int strcmp(const char *lhs, const char *rhs) {
    if (*lhs != '\0' && *lhs == *rhs)
        return strcmp(++lhs, ++rhs);

    return *lhs - *rhs;
}

// записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource
// Возвращает указатель на следующий свободный фрагмент памяти в destination
char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    long long distance = endSource - beginSource;
    memcpy(beginDestination, beginSource, distance);

    return beginDestination + distance;
}

// записывает по адресу beginDestination
// фрагмент памяти, начиная с адреса rbeginSource до rendSource
// Возвращает указатель на следующий слева свободный фрагмент памяти в destination
char* copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination){
    while (rbeginSource-- > rendSource)
        *(beginDestination++) = *(rbeginSource + 1);

    return beginDestination;
}

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource
// заканчивая endSource, удовлетворяющие функции-предикату f
// возвращает указатель на следующий свободный для записи фрагмент в памяти
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (*beginSource != '\0' && beginSource != endSource)
        if (f(*(beginSource++)))
            *(beginDestination++) = *(beginSource - 1);

    return beginDestination;
}

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f
// возвращает значение beginDestination по окончанию работы функции
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource)
        if (f(*(rbeginSource--)))
            *(beginDestination++) = *(rbeginSource + 1);

    return beginDestination;
}

// возвращает указатель на конец строки s
char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

// возвращает 'истина' и записывает в word.begin адрес начала слова, а в word.end адрес конца слова, если слово найдено, иначе - 'ложь'
bool getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    return true;
}

// возвращает 'истина' и записывает в rbegin адрес конца слова, а в rend адрес начала слова, если слово найдено, иначе - 'ложь'
bool getWordReverse(char *rbegin, char *rend, wordDescriptor *word) {
    word->begin = findNonSpaceReverse(rbegin, rend);
    if (word->begin <= rend)
        return false;

    word->end = findSpaceReverse(word->begin, rend);

    return true;
}
