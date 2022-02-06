#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 42);

    assert(v.size == 1 && v.capacity == 1);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = (vector) {(int[]) {1}, 1, 5};
    pushBack(&v, 42);

    assert(v.size == 2 && v.capacity == 5);

    deleteVector(&v);
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();

};

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);

    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_popBack() {
    test_popBack_notEmptyVector();
}

void test() {
    test_pushBack;
    test_popBack();
}

int main() {
    test();

    return 0;
}
