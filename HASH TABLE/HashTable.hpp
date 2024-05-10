#pragma once

#include <iostream>

const unsigned int ERROR_KEY_NOT_FOUND = 10; // utilisé si la clé n'est pas dans la table de hachage
const int INTEGER_NULL_VALUE = -999999;

class HashEntry {
    int key;
    int value;
    HashEntry* next; // liste chaînée

public:
    HashEntry(int k, int v) : key(k), value(v), next(nullptr) {}
    
    int getValue() const;
    int getKey() const;
    void setNext(HashEntry* next);
    HashEntry* getNext() const;
    void insertToNext(HashEntry* newNext);
    void removeNext();
    std::string toString() const;
    void clearNextList();
};

class HashTable {
    HashEntry** array;
    size_t capacity;
    size_t size;

    size_t hashFunction(int key);

public:
    HashTable(size_t cap);
    ~HashTable();

    void insert(int key, int value);
    int get(const int key);
    void remove(const int key);
    void list();
    void clear();
};
