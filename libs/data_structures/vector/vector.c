#include "vector.h"

void check_memory(const int *data) {
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

//возвращает структуру-дескриптор вектор из capacity значений
vector createVector(const size_t capacity) {
    int *data = NULL;

    if (capacity > 0) {
        data = (int *) malloc(capacity * sizeof(int));
        check_memory(data);
    }

    return (vector) {data, 0, capacity};
}

//изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector *v, const size_t newCapacity) {
    v->capacity = newCapacity;
    if (newCapacity < v->size)
        v->size = newCapacity;

    if (v->capacity > 0) {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        check_memory(v->data);
    } else
        v->data = NULL;
}

//удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v) {
    v->size = 0;
}

//освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

//освобождает память, выделенную вектору
void deleteVector(vector *v) {
    reserve(v, 0);
}

