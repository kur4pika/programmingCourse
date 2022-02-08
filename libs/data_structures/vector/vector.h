#ifndef UNTITLED3_VECTOR_H
#define UNTITLED3_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);//возвращает структуру-дескриптор вектор из n значений

void reserve(vector *v, size_t newCapacity);//изменяет количество памяти, выделенное под хранение элементов вектора v, на newCapacity

void clear(vector *v);//удаляет элементы из вектора v, но не освобождает выделенную память

void shrinkToFit(vector *v);//освобождает память вектора v, выделенную под неиспользуемые элементы

void deleteVector(vector *v);//освобождает память, выделенную вектору v

bool isEmpty(vector v);//возвращает "истина", если вектор является пустым, иначе - "ложь"

bool isFull(vector v);//возвращает "истина", если вектор является полным, иначе - "ложь"

bool isZero(vector v);//возвращает "истина", если вектор является нулевым, иначе - "ложь"

int getVectorValue(vector v, size_t i);//возвращает i-ый элемент вектора v

void pushBack(vector *v, int x);//добавляет элемент x в конец вектора v

void popBack(vector *v);//удаляет последний элемент из вектора v

int* atVector(vector v, size_t index);//возвращает указатель на index-ый элемент вектора v

int* back(vector v);//возвращает указатель на последний элемент вектора v

int* front(vector v);//возвращает указатель на нулевой элемент вектора v



#endif //UNTITLED3_VECTOR_H