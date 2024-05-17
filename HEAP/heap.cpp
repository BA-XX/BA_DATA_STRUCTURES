#include "heap.hpp"

template <typename T>
Heap<T>::Heap(size_t capacity, int (*comparator)(T &, T &))
{
    this->comparator = comparator;
    this->capacity = capacity;

    heap = new T[capacity];

    size = 0;
}

template <typename T>
Heap<T>::~Heap()
{
}

template <typename T>
size_t Heap<T>::getParent(size_t)
{
}
template <typename T>
size_t Heap<T>::getRightChild(size_t)
{
}
template <typename T>
size_t Heap<T>::getLeftChild(size_t)
{
}

template <typename T>
void Heap<T>::insert(T newElement)
{
    heap[size] = newElement;
    ++size;

    HeapifyUp();
}

template <typename T>
void Heap<T>::HeapifyUp()
{
    size_t parent = getParent(size-1);

    while ()
    {
        /* code */
    }
    
}
template <typename T>
void Heap<T>::HeapifyDown()
{
}

template <typename T>
std::string Heap<T>::toString()
{
    std::string temp;

    for (size_t i = 0; i < size; i++)
        temp += "-" + heap[i];

    return temp;
}