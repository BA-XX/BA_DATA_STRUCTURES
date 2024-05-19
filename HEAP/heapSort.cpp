#include <iostream>
#include "heap.cpp"

template <typename T>
void heapSort(T *arr, size_t size, bool reverse = false)
{
    Heap<T> heap; // empty heap

    if (reverse) // changer comparator to reverse sort ordre
        heap.build(arr, size, false, comparatorNumbersHeapMin);
    else
        heap.build(arr, size , false , comparatorNumbersHeapMax);

    for (int i = size - 1; i >= 0; i--) // extract all element form the heap
        arr[i] = heap.extract();        // place the extracted element to the back of the array
}

int main()
{

    int ab[] = {23, 323, 22, 1, 2, 4, 5, 55, 33, 4};

    heapSort(ab, 10);
    for (size_t i = 0; i < 10; i++) // extract all element form the heap
        std::cout << ab[i] << "   ";

    std::cout << std::endl;
    heapSort(ab, 10, true);
    for (size_t i = 0; i < 10; i++) // extract all element form the heap
        std::cout << ab[i] << "   ";
}