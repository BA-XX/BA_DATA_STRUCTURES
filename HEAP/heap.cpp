#include "heap.hpp"

/* Comparators example for min and max heap*/
template <typename T>
int comparatorNumbersHeapMin(T &a, T &b)
{
    if (a > b)
        return 1;
    if (a == b)
        return 0;
    return -1;
}
template <typename T>
int comparatorNumbersHeapMax(T &a, T &b)
{
    if (a < b)
        return 1;
    if (a == b)
        return 0;
    return -1;
}

/* swap */
template <typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

/* Heap class*/

template <typename T>
void Heap<T>::HeapifyUp()
{
    size_t bottom = size - 1;
    size_t parent = getParent(bottom);

    while (bottom > 0 && (comparator(heap[parent], heap[bottom]) == 1))
    {
        swap(heap[parent], heap[bottom]);

        bottom = parent;
        parent = getParent(bottom);
    }
}

template <typename T>
void Heap<T>::HeapifyDown(size_t parent)
{
    size_t left = getLeftChild(parent);
    size_t right = getRightChild(parent);

    while (parent < size / 2)
    {
        size_t min = parent;

        if (left < size && comparator(heap[min], heap[left]) == 1)
            min = left;

        if (right < size && comparator(heap[min], heap[right]) == 1)
            min = right;

        if (min != parent)
        {
            swap(heap[parent], heap[min]);
            parent = min;
            left = getLeftChild(min);
            right = getRightChild(min);
        }
        else
            break;
    }
}

template <typename T>
Heap<T>::Heap()
{
    heap = nullptr;
    capacity = 0;
    size = 0;
    comparator = nullptr;
    freeMemory = false;
}

template <typename T>
Heap<T>::Heap(size_t capacity, bool freeMemory, int (*comparator)(T &, T &))
{
    this->comparator = comparator;
    this->capacity = capacity;
    this->freeMemory = freeMemory;

    heap = new T[capacity];

    size = 0;
}

template <typename T>
Heap<T>::~Heap()
{
    if (!isEmpty() && freeMemory)
        delete[] heap;
}


template <typename T>
void Heap<T>::build(T *arr, size_t size, bool freeMemory, int (*comparator)(T &, T &))
{
    this->heap = arr;

    this->capacity = size;
    this->size = size;
    this->freeMemory = freeMemory;

        this->comparator = comparator;

    // heapify the arr
    for (int i = (size / 2) - 1; i >= 0; i--)
        HeapifyDown(i);
}

template <typename T>
size_t Heap<T>::getParent(size_t index)
{
    return (index - 1) / 2;
}

template <typename T>
size_t Heap<T>::getRightChild(size_t index)
{
    return 2 * index + 2;
}

template <typename T>
size_t Heap<T>::getLeftChild(size_t index)
{
    return 2 * index + 1;
}

template <typename T>
void Heap<T>::insert(T newElement)
{
    if (size == capacity) // throw an error if the is full
        throw "Heap is Full";

    heap[size] = newElement;
    ++size;

    HeapifyUp();
}

template <typename T>
T Heap<T>::extract()
{
    if (isEmpty()) // throw an error if the heap is empty
        throw "Heap is Empty";

    T temp = heap[0];

    heap[0] = heap[size - 1];
    --size;

    HeapifyDown(0);

    return temp;
}

template <typename T>
bool Heap<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
std::string Heap<T>::toString()
{
    std::string temp;

    for (size_t i = 0; i < size; i++)
        temp += " - " + std::to_string(heap[i]);

    return temp;
}