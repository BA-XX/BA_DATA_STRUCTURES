#include "stack.hpp"

/* Class Node */
template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    next = nullptr;
}

template <typename T>
void Node<T>::setNext(Node<T> *next)
{
    this->next = next;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return next;
}

template <typename T>
void Node<T>::setData(T data)
{
    this->data = data;
}
template <typename T>
T Node<T>::getData()
{
    return data;
}
/* End class Node<T>*/

/* Class Stack*/
template <typename T>
Stack<T>::Stack()
{
    head = nullptr;
    size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    while (!isEmpty())
        pop();
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return (head == nullptr);
}

template <typename T>
void Stack<T>::push(T data)
{
    Node<T> *temp = new Node<T>(data); // create a new stack element
    temp->setNext(head);
    head = temp; // change the value of the head
    ++size;      // increase the size
}
template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw "Stack is Empty";
        return 0;
    }

    T data = head->getData(); // save the head data

    Node<T> *temp = head; // save the head

    head = head->getNext(); // change the head to the next node in the stack

    --size; // decrease the size

    delete temp; // free memory of the old head

    return data;
}

template <typename T>
T Stack<T>::top()
{
    if (isEmpty())
    {
        throw "Stack is Empty";
        return 0;
    }

    return head->getData();
}

template <typename T>
int Stack<T>::getSize()
{
    return size;
}
/* End class Stack*/