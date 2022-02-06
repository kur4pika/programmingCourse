#ifndef UNTITLED3_VECTOR_H
#define UNTITLED3_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t capacity);//возвращает структуру-дескриптор вектор из capacity значений

void reserve(vector *v, size_t newCapacity);//изменяет количество памяти, выделенное под хранение элементов вектора

void clear(vector *v);//удаляет элементы из контейнера, но не освобождает выделенную память

void shrinkToFit(vector *v);//освобождает память, выделенную под неиспользуемые элементы

void deleteVector(vector *v);//освобождает память, выделенную вектору

#endif //UNTITLED3_VECTOR_H