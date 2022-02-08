#include "vector.h"

#define EXIT_CODE 1

#define throwExceptionBadAlloc() fprintf(stderr, "bad alloc"); exit(EXIT_CODE)
#define throwExceptionEmptyVector() fprintf(stderr, "vector is empty"); exit(EXIT_CODE)
#define throwExceptionIndexError(...) fprintf(stderr, "IndexError: a[%zu] is not exists", index); exit(EXIT_CODE)

// выводит сообщение об ошибке, если ОП не может предоставить
// нужный объем памяти под размещение динамического массива
void check_memory(const int *data) {
    if (data == NULL) {
        throwExceptionBadAlloc();
    }
}

// возвращает структуру-дескриптор вектор из n значений
vector createVector(const size_t n) {
    int *data = NULL;

    if (n > 0) {
        data = (int *) malloc(n * sizeof(int));

        check_memory(data);
    }

    return (vector) {data, 0, n};
}

// изменяет количество памяти, выделенное под хранение элементов вектора v на newCapacity
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

// удаляет элементы из вектора v, но не освобождает выделенную память
void clear(vector *v) {
    v->size = 0;
}

// освобождает память вектора v, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

// освобождает память, выделенную вектору v
void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

// возвращает "истина", если вектор является пустым, иначе - "ложь"
bool isEmpty(const vector v) {
    return v.size == 0;
}

// возвращает "истина", если вектор является полным, иначе - "ложь"
bool isFull(vector v) {
    return v.size == v.capacity;
}

// возвращает "истина", если вектор является нулевым, иначе - "ложь"
bool isZero(const vector v) {
    return v.capacity == 0;
}

// возвращает i-ый элемент вектора v
int getVectorValue(const vector v, const size_t i) {
    return v.data[i];
}

// добавляет элемент x в конец вектора v
void pushBack(vector *v, const int x) {
    if (isFull(*v) && !isZero(*v))
        reserve(v, v->size * 2);
    else if (isZero(*v))
        reserve(v, 1);

    v->data[v->size++] = x;
}

// удаляет последний элемент из вектора v
void popBack(vector *v) {
    if (isEmpty(*v)) {
        throwExceptionEmptyVector();
    }

    v->size--;
}

//возвращает указатель на index-ый элемент вектора v
int *atVector(vector v, size_t index) {
    if (index >= v.size) {
        throwExceptionIndexError(index);
    }

    return &v.data[index];
}

//возвращает указатель на последний элемент вектора v
int *back(vector v) {
    if (isEmpty(v)) {
        throwExceptionEmptyVector();
    }

    return &v.data[v.size - 1];
}

// возвращает указатель на нулевой элемент вектора v
int *front(vector v) {
    if (isEmpty(v)) {
        throwExceptionEmptyVector();
    }

    return &v.data[0];
}
