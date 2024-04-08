#include "header.hpp"
/* Class Node */

Node::Node(data_type data)
{
    this->data = data;
    next = nullptr;
}

void Node::setNext(Node *next)
{
    this->next = next;
}
Node *Node::getNext()
{
    return next;
}

void Node::setData(data_type data)
{
    this->data = data;
}
data_type Node::getData()
{
    return data;
}
/* End class Node*/

/* Class Stack*/
Stack::Stack()
{
    head = nullptr;
    size = 0;
}
Stack::~Stack()
{
    while (!isEmpty())
        pop();
}

bool Stack::isEmpty()
{
    return (head == nullptr);
}
void Stack::push(data_type data)
{
    Node *temp = new Node(data); // create a new stack element
    temp->setNext(head);
    head = temp; // change the value of the head
    ++size;      // increase the size
}
data_type Stack::pop()
{
    if (isEmpty())
    {
        std::cerr << "Stack is Empty" << std::endl;
        return 0;
    }

    data_type data = head->getData(); // save the head data

    Node *temp = head; // save the head

    head = head->getNext(); // change the head to the next node in the stack

    --size; // decrease the size

    delete temp; // free memory of the old head

    return data;
}
data_type Stack::top()
{
    if (isEmpty())
    {
        std::cerr << "Stack is Empty" << std::endl;
        return 0;
    }

    return head->getData();
}

size_t Stack::getSize()
{
    return size;
}
/* End class Stack*/