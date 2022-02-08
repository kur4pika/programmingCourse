#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_createVector_capacityEqualsZero(){
    size_t capacity = 0;
    vector v = createVector(capacity);

    assert(v.data == NULL);

    deleteVector(&v);
}

void test_createVector_memoryIsAllocated(){
    size_t capacity = 100;
    vector v = createVector(capacity);

    assert(v.data != NULL);

    deleteVector(&v);
}

void test_createVector(){
    test_createVector_capacityEqualsZero();
    test_createVector_memoryIsAllocated();
}

void test_reserve_newCapacityEqualsZero(){
    vector v = createVector(10);
    size_t newCapacity = 0;
    reserve(&v, newCapacity);

    assert(v.data == NULL);

    deleteVector(&v);
}

void test_reserve_newCapacityLessSize(){
    vector v = createVector(10);
    v.size = 6;
    size_t newCapacity = 4;

    reserve(&v, newCapacity);

    assert(v.size == v.capacity);

    deleteVector(&v);
}

void test_reserve(){
    test_reserve_newCapacityEqualsZero();
    test_reserve_newCapacityLessSize();
}

void test_pushBack_emptyVector(){
    vector v = createVector(0);

    pushBack(&v, 4);

    assert(v.data[0] == 4);
    assert(v.size == 1);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_pushBack_fullVector(){
    vector v = createVector(2);
    v.size = 2;

    pushBack(&v, 6);

    assert(v.data[2] == 6);
    assert(v.size == 3);
    assert(v.capacity == 4);

    deleteVector(&v);
}

void test_pushBack_notFullVector(){
    vector v = createVector(4);
    v.size = 2;

    pushBack(&v, 5);

    assert(v.data[2] == 5);
    assert(v.size == 3);
    assert(v.capacity == 4);

    deleteVector(&v);
}

void test_pushBack(){
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_pushBack_notFullVector();
}

void test_popBack_notEmptyVector(){
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_popBack(){
    test_popBack_notEmptyVector();
}

void test_atVector_notEmptyVector(){
    vector v = {(int []){1, 3, 4}, 3, 5};

    assert(*atVector(v, 1) == 3);
}

void test_atVector_requestToLastElement(){
    vector v = {(int []){1, 3, 4}, 3, 5};

    assert(*atVector(v, v.size - 1) == 4);
}

void test_atVector(){
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
}

void test_back_oneElementInVector(){
    vector v = {(int []){5}, 1, 1};

    assert(*back(v) == 5);
}

void test_back(){
    test_back_oneElementInVector();
}

void test_front_oneElementInVector(){
    vector v = {(int []){5}, 1, 1};

    assert(*front(v) == 5);
}

void test_front(){
    test_front_oneElementInVector();
}

void test(){
    test_createVector();
    test_reserve();
    test_pushBack();
    test_popBack();
    test_atVector();
    test_back();
    test_front();
}

int main() {
    test();

    return 0;
}