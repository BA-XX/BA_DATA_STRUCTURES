#include "header.hpp"

/* Class Node */
Node::Node(data_type data)
{
    setData(data);
    next = nullptr;
}
Node::~Node()
{
}

void Node::setData(data_type data)
{
    this->data = data;
}
data_type Node::getData()
{
    return data;
}

void Node::setNext(Node *next)
{
    this->next = next;
}
Node *Node::getNext()
{
    return next;
}
/* End class Node*/

/* Class LinkedList*/
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList()
{
    deleteList();
}

bool LinkedList::isEmpty()
{
    return (head == nullptr);
}
void LinkedList::deleteList()
{
    if (isEmpty())
        return;

    Node *temp = head;

    while (temp != nullptr)
    {
        Node *temp2 = temp;
        temp = temp->getNext();
        delete (temp2);
    }

    head = tail = nullptr;
}

data_type LinkedList::getHeadData()
{
    return head->getData();
}
data_type LinkedList::getTailData()
{
    return tail->getData();
}
data_type LinkedList::getData(size_t index)
{
    if (isEmpty())
    {
        std::cerr << "Error the list is empty" << std::endl;
        exit(-1);
    }

    size_t tempIndex = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (tempIndex == index)
            return temp->getData();

        ++tempIndex;

        temp = temp->getNext();
    }
    return 0;
}

void LinkedList::initialize(size_t size, data_type defaultData)
{
    if (!isEmpty())
    {
        std::cout << "The list already contains data, try deleting it first!" << std::endl;
        return;
    }

    for (size_t i = 0; i < size; i++)
        insertHead(defaultData);
}
void LinkedList::insertHead(data_type data)
{

    Node *temp = new Node(data);

    if (isEmpty())
    {
        head = temp;
        tail = temp;
        return;
    }

    temp->setNext(head);
    head = temp;
}
void LinkedList::insertTail(data_type data)
{
    Node *temp = new Node(data);

    if (isEmpty())
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->setNext(temp);
    tail = temp;
}
void LinkedList::showList()
{
    if (isEmpty())
        return;

    Node *temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->getData() << std::endl;

        temp = temp->getNext();
    }
}

size_t LinkedList::getSize()
{
    if (isEmpty())
        return 0;

    size_t size = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        ++size;

        temp = temp->getNext();
    }

    return size;
}

Node *LinkedList::getHead()
{
    return head;
}
Node *LinkedList::getTail()
{
    return tail;
}
Node *LinkedList::searchData(data_type data)
{
    if (isEmpty())
        return nullptr;

    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->getData() == data)
            return temp;

        temp = temp->getNext();
    }
    
    return nullptr;
}

LinkedList *LinkedList::copyList()
{
    LinkedList *tempList = new LinkedList();

    Node *temp = head;

    while (temp != nullptr)
    {
        tempList->insertTail(temp->getData());

        temp = temp->getNext();
    }

    return tempList;
}
/* End class LinkedList*/
