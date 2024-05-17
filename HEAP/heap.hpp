#pragma once

#include <string>

//typedef unsigned int size_t;


template <typename T>
class Heap
{

    T *heap;
    size_t capacity;
    size_t size;



public:
    int (*comparator)(T &, T &);
    Heap(size_t , int (*comparator)(T& , T&));

    ~Heap();

    size_t getParent(size_t);
    size_t getRightChild(size_t);
    size_t getLeftChild(size_t);

    void insert(T);

    void HeapifyUp();
    void HeapifyDown();

    std::string toString();
};