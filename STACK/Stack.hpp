#pragma once

#include <iostream>

typedef int data_type;

class Node
{
    data_type data;
    Node *next;

public:
    Node(data_type);

    void setNext(Node *);
    Node *getNext();

    void setData(data_type);
    data_type getData();
};

class Stack
{
    Node *head;
    size_t size;

public:
    Stack();
    ~Stack();

    bool isEmpty();
    void push(data_type);
    data_type pop();
    data_type top();

    size_t getSize();
};