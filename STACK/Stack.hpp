#pragma once

template <typename T>
class Node
{
    T data;
    Node *next;

public:
    Node(T);

    void setNext(Node *);
    Node *getNext();

    void setData(T);
    T getData();
};

template <typename T>
class Stack
{
    Node<T> *head;
    int size;

public:
    Stack();
    ~Stack();

    bool isEmpty();
    void push(T);
    T pop();
    T top();

    int getSize();
};