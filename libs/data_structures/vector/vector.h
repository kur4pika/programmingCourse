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

vector createVector(size_t capacity);//возвращает структуру-дескриптор вектор из capacity значений

void reserve(vector *v, size_t newCapacity);//изменяет количество памяти, выделенное под хранение элементов вектора

void clear(vector *v);//удаляет элементы из контейнера, но не освобождает выделенную память

void shrinkToFit(vector *v);//освобождает память, выделенную под неиспользуемые элементы

void deleteVector(vector *v);//освобождает память, выделенную вектору

bool isEmpty(vector *v);//проверяет является ли вектор пустым

bool isFull(vector *v);//проверяет явялется ли вектор полным

bool isZero(vector *v);////проверяет является ли вектор нулевым

int getVectorValue(vector *v, size_t i);//возвращает i-ый элемент вектора v

void pushBack(vector *v, int x);//добавляет элемент x в конец вектора v

void popBack(vector *v);//удаляет последний элемент из вектора

#endif //UNTITLED3_VECTOR_H