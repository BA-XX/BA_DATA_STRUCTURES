#include "HashTable.hpp"

int HashEntry::getValue() const {
    return value;
}

int HashEntry::getKey() const {
    return key;
}

void HashEntry::setNext(HashEntry* next) {
    this->next = next;
}

HashEntry* HashEntry::getNext() const {
    return next;
}

void HashEntry::insertToNext(HashEntry* newNext) {
    if (next == nullptr)
        next = newNext;
    else
        next->insertToNext(newNext);
}

void HashEntry::removeNext() {
    if (next == nullptr)
        return;

    HashEntry* tmpNext = next;
    next = next->getNext();
    delete tmpNext;
}

std::string HashEntry::toString() const {
    return "[" + std::to_string(key) + "," + std::to_string(value) + "]";
}

void HashEntry::clearNextList() {
    if (next == nullptr)
        return;
    next->clearNextList();
    delete next;
    next = nullptr;
}

HashTable::HashTable(size_t cap) : capacity(cap), size(0) {
    array = new HashEntry*[cap];
    for (size_t i = 0; i < cap; i++)
        array[i] = nullptr;
}

HashTable::~HashTable() {
    clear();
}

size_t HashTable::hashFunction(int key) {
    return key % capacity;
}

void HashTable::insert(int key, int value) {
    HashEntry* newEntry = new HashEntry(key, value);
    size_t index = hashFunction(key);
    if (array[index] == nullptr)
        array[index] = newEntry;
    else
        array[index]->insertToNext(newEntry);
    size++;
}

int HashTable::get(const int key) {
    size_t index = hashFunction(key);
    HashEntry* temp = array[index];
    while (temp != nullptr && temp->getKey() != key)
        temp = temp->getNext();
    if (temp->getKey() == key)
        return temp->getValue();
    else
        throw ERROR_KEY_NOT_FOUND;
    return INTEGER_NULL_VALUE;
}

void HashTable::remove(const int key) {
    size_t index = hashFunction(key);
    HashEntry* temp = array[index];
    if (temp->getKey() == key) {
        array[index] = temp->getNext();
        delete temp;
        return;
    }
    while (temp != nullptr && temp->getKey() != key) {
        if (temp->getNext() != nullptr) {
            if (temp->getNext()->getKey() == key) {
                temp->removeNext();
                --size;
                break;
            }
        } else
            throw ERROR_KEY_NOT_FOUND;
        temp = temp->getNext();
    }
}

void HashTable::list() {
    if (size == 0) {
        std::cout << "La table est vide." << std::endl;
        return;
    }
    for (size_t i = 0; i < capacity; i++)
        if (array[i] != nullptr) {
            HashEntry* tmp = array[i];
            std::cout << tmp->toString();
            while (tmp->getNext() != nullptr) {
                tmp = tmp->getNext();
                std::cout << " --> " << tmp->toString();
            }
            std::cout << std::endl;
        }
}

void HashTable::clear() {
    if (size == 0)
        return;
    for (size_t i = 0; i < capacity; i++)
        if (array[i] != nullptr) {
            array[i]->clearNextList();
            delete array[i];
            array[i] = nullptr;
        }
    size = 0;
}
