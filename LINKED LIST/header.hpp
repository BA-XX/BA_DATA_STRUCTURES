#pragma once

#include <iostream>

typedef int data_type;

class Node
{
private:
    data_type data;
    Node *next;

public:
    Node(data_type );
    ~Node();

    void setData(data_type );
    data_type getData();

    void setNext(Node *);
    Node *getNext();
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty();
    void deleteList();

    data_type getHeadData();
    data_type getTailData();
    data_type getData(size_t index);

    void initialize(size_t size  , data_type defaultData);
    void insertHead(data_type data);
    void insertTail(data_type data);
    void showList();

    size_t getSize();

    Node *getHead();
    Node *getTail();
    Node *searchData(data_type data);

    LinkedList *copyList();
};