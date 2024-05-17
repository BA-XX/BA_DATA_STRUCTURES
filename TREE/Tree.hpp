#pragma once

#include <iostream>

typedef int data_type;

class Node
{

    data_type data;
    Node *leftChild;
    Node *rightChild;

public:
    Node(data_type, Node * = nullptr, Node * = nullptr);

    void setData(data_type);
    data_type getData();

    void setLeftChild(Node *);
    Node *getLeftChild();

    void setRightChild(Node *);
    Node *getRightChild();
};

class Tree
{
    Node *root;

public:
    Tree();
    
};