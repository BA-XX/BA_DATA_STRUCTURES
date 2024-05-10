#pragma once

#include <iostream>

const unsigned int ERROR_KEY_NOT_FOUND = 10; // utilise si le key n'est pas dans le table de hashage
const int INTEGER_NULL_VALUE = -999999;

class HashEntry
{
    int key;
    int value;

    HashEntry *next; // linked list

public:
    HashEntry(int k, int v) : key(k), value(v)
    {
        next = nullptr;
    }

    int getValue() const
    {
        return value;
    }

    int getKey() const
    {
        return key;
    }

    void setNext(HashEntry *next)
    {
        this->next = next;
    }

    HashEntry *getNext() const
    {
        return next;
    }

    void insertToNext(HashEntry *newNext)
    {
        if (next == nullptr)
            next = newNext;
        else
            next->insertToNext(newNext);
    }

    void removeNext()
    {
        if (next == nullptr)
            return;

        HashEntry *tmpNext = next;

        next = next->getNext();

        delete tmpNext;
    }

    std::string toString() const
    {
        return "[" + std::to_string(key) + "," + std::to_string(value) + "]";
    }

    void clearNextList()
    {
        if (next == nullptr)
            return;
        next->clearNextList();
        delete next;
        next = nullptr;
    }
};

class HashTable
{

    HashEntry **array;
    size_t capacity;
    size_t size;

    size_t hashFunction(int key)
    {
        return key % capacity;
    }

public:
    HashTable(size_t cap) : capacity(cap), size(0)
    {
        array = new HashEntry *[cap];

        for (size_t i = 0; i < cap; i++)
            array[i] = nullptr;
    }

    ~HashTable()
    {
        clear();
    }

    void insert(int key, int value)
    {
        HashEntry *newEntry = new HashEntry(key, value);

        size_t index = hashFunction(key);

        if (array[index] == nullptr)
            array[index] = newEntry;
        else
            array[index]->insertToNext(newEntry);

        size++;
    }
    int get(const int key)
    {
        size_t index = hashFunction(key);

        HashEntry *temp = array[index];

        while (temp != nullptr && temp->getKey() != key)
            if (temp->getNext() != nullptr)
                temp = temp->getNext();

        if (temp->getKey() == key)
            return temp->getValue();
        else
            throw ERROR_KEY_NOT_FOUND;

        return INTEGER_NULL_VALUE;
    }
    void remove(const int key)
    {
        size_t index = hashFunction(key);

        HashEntry *temp = array[index];

        if (temp->getKey() == key)
        {
            array[index] = temp->getNext();

            delete temp;

            return;
        }

        while (temp != nullptr && temp->getKey() != key)
        {
            if (temp->getNext() != nullptr)
            {
                if (temp->getNext()->getKey() == key)
                {                       // verifie le key du suivant
                    temp->removeNext(); // supprimer le suivante
                    --size;
                    break; // sortir de la boucle
                }
            }
            else
                throw ERROR_KEY_NOT_FOUND;

            temp = temp->getNext();
        }
    }
    void list()
    {
        if (size == 0)
        {
            std::cout << "Table is empty " << std::endl;
            return;
        }

        for (size_t i = 0; i < capacity; i++)
            if (array[i] != nullptr)
            {
                HashEntry *tmp = array[i];

                std::cout << tmp->toString();

                while (tmp->getNext() != nullptr)
                {
                    tmp = tmp->getNext();

                    std::cout << " --> " << tmp->toString();
                }

                std::cout << std::endl;
            }
    }
    void clear()
    {
        if (size = 0)
            return;

        for (size_t i = 0; i < capacity; i++)
            if (array[i] != nullptr)
            {
                array[i]->clearNextList();
                delete array[i];
                array[i] = nullptr;
            }

        size = 0;
    }
};