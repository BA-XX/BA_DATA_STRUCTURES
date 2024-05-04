#pragma once

typedef unsigned int size_t;

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
    ~HashEntry()
    {
        if (next != nullptr)
            delete next; // Recursively delete the next entry
    }

    void setNext(HashEntry *next)
    {
        this->next = next;
    }

    void insertToNext(HashEntry *newNext)
    {
        if (next == nullptr)
            next = newNext;
        else
            next->insertToNext(newNext);
    }
    HashEntry *getNext()
    {
        return next;
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
    HashTable(size_t capacity)
    {
        array = new HashEntry *[capacity];

        for (size_t i = 0; i < capacity; i++)
            array[i] = nullptr;
    }

    ~HashTable()
    {
        for (size_t i = 0; i < capacity; i++)
            if (array[i] != nullptr)
                delete array[i];
    }

    void insert(int key, int value)
    {
        HashEntry *newEntry = new HashEntry(key, value);

        size_t index = hashFunction(key);

        if (array[index] == nullptr)
            array[index] = newEntry;
        else
            array[index]->insertToNext(newEntry);
    }
    int get(int key)
    {
    }
    int remove(int key)
    {
    }
    void list()
    {
    }
    void clear()
    {
    }
};