// hashtable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <cstring>
using namespace std;
void customStrcpy(char* dest, char const* src);
int customStrcmp(char const* str1, char const* str2);

// Structure to hold the value pair (counts for forward and reversed strings)
struct Value {
    int forwardCount;
    int reversedCount;

    Value() : forwardCount(0), reversedCount(0) {}
};

// Node structure for each entry in the hash table
struct Node {
    char* key;
    Value value;
    Node* next;

    Node(const char* k, const Value& v) : value(v), next(NULL) {
        key = new char[strlen(k) + 1];
        customStrcpy(key, k);
    }

    ~Node() {
        delete[] key;
    }
};

class HashTable {
private:
    Node** table;
    int size;

    int hashFunction(const char* key) const {
        unsigned long hash = 5381;
        int c;
        while ((c = *key++)) {
            hash = ((hash << 5) + hash) + c; // hash * 33 + c
        }
        return hash % size;
    }

public:
    HashTable(int s);
    ~HashTable();
    Node** getTable();
    void insert(const char* key, const Value& value);
    Value* find(const char* key);
    void clear();
};

#endif
