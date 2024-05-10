#include "header.hpp"

/* Class Node */

Node::Node(data_type data, Node *leftChild, Node *rightChild)
{
    setData(data);
    setLeftChild(leftChild);
    setRightChild(rightChild);
}

void Node::setData(data_type data)
{
    this->data = data;
}
data_type Node::getData()
{
    return data;
}

void Node::setLeftChild(Node *leftChild)
{
    this->leftChild = leftChild;
}
Node *Node::getLeftChild()
{
    return leftChild;
}

void Node::setRightChild(Node *rightChild)
{
    this->rightChild = rightChild;
}
Node *Node::getRightChild()
{
    return rightChild;
}

/* End Node*/

/* Class Tree */
/* End Tree*/