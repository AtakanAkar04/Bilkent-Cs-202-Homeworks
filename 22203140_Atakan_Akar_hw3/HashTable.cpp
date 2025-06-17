// hashtable.cpp
#include "HashTable.h"
#include <cstring>
#include <iostream>
using namespace std;
HashTable::HashTable(int s) : size(s) {
    table = new Node*[size];
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    
    delete[] table;
}

void HashTable::insert(const char* key, const Value& value) {
    int index = hashFunction(key);
    Node* current = table[index];

    // Check if the key already exists
    while (current) {
        if (customStrcmp(current->key, key) == 0) {
            // Update the value
            current->value.forwardCount += value.forwardCount;
            current->value.reversedCount += value.reversedCount;
            return;
        }
        current = current->next;
    }

    // Insert a new node at the head of the linked list
    Node* newNode = new Node(key, value);
    newNode->next = table[index];
    table[index] = newNode;
}

Value* HashTable::find(const char* key) {
    int index = hashFunction(key);
    Node* current = table[index];

    while (current) {
        if (customStrcmp(current->key, key) == 0) {
            return &current->value;
        }
        current = current->next;
    }
    return nullptr;
}

void HashTable::clear() {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = nullptr;
    }
}
Node** HashTable::getTable()  {
    return table;
}
int customStrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

void customStrcpy(char* dest, const char* src) {
    while ((*dest++ = *src++) != '\0');
}
