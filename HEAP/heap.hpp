#pragma once

/* @BA-XX */

#include <string>

// typedef unsigned int size_t;

template <typename T>
int comparatorNumbersHeapMin(T &a, T &b);

template <typename T>
int comparatorNumbersHeapMax(T &a, T &b);

template <typename T>
void swap(T &, T &);

template <typename T>
class Heap
{

    T *heap;         // HEAP ARRAY
    size_t capacity; // MAX HEAP CAPACITY
    size_t size;     // NUM CURRENT ELEMENT

    bool freeMemory; // indicate if the destructor should free memory or not , useful in case the heap array is provided in the argument of the constructor

    int (*comparator)(T &, T &); // COMPARAISON FUNCTION returns 1 , 0 or -1

    void HeapifyUp();
    void HeapifyDown(size_t);

    size_t getParent(size_t);
    size_t getRightChild(size_t);
    size_t getLeftChild(size_t);

public:

    Heap();
    Heap(size_t , bool = true, int (*comparator)(T &, T &) = comparatorNumbersHeapMax);

    ~Heap();

    void build(T * , size_t , bool = false , int (*comparator)(T &, T &) = comparatorNumbersHeapMax);

    void insert(T);
    T extract();

    bool isEmpty();

    std::string toString();
};
