#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Custom minimum function
int customMin(int a, int b) {
    return (a < b) ? a : b;
}

// Custom string comparison function


// Custom string concatenation function
void customStrcat(char* dest, const char* src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// Function to find lexicographically smallest rotation using Booth's algorithm
void smallestRotation(const char* s, char* result) {
    int n = strlen(s);
    int* f = new int[n * 2];
    for (int i = 0; i < n * 2; i++) f[i] = -1;

    int k = 0;
    for (int j = 1; j < n * 2; j++) {
        char c = s[j % n];
        int i = f[j - k - 1];
        while (i != -1 && c != s[(k + i + 1) % n]) {
            if (c < s[(k + i + 1) % n]) k = j - i - 1;
            i = f[i];
        }
        if (c != s[(k + i + 1) % n]) {
            if (c < s[k % n]) k = j;
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        result[i] = s[(k + i) % n];
    }
    result[n] = '\0';
    delete[] f;
}

// Function to reverse a string manually



void reverseString(const char* input, char* reversed) {
    int n = strlen(input);
    for (int i = 0; i < n; i++) {
        reversed[i] = input[n - i - 1];
    }
    reversed[n] = '\0';
}

int main(int argc, char* argv[]) {
    // Check for correct command-line arguments
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    ofstream outputFile(argv[2]);
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    if (n > 100000) {
        cerr << "Error: Number of strings exceeds 100,000." << endl;
        return 1;
    }

    long long totalChars = 0;
    char** strings = new char*[n];

    for (int i = 0; i < n; i++) {
        strings[i] = new char[1000000]; // Assuming max length per string is 10,000
        inputFile >> strings[i];
        totalChars += strlen(strings[i]);

        if (totalChars > 10000000) {
            cerr << "Error: Total number of characters exceeds 10,000,000." << endl;
            return 1;
        }
    }

    const int hashTableSize = 131072; // Optimized for large inputs
    HashTable canonicalCounts(hashTableSize);

    // Process each string and compute canonical forms
    char* forwardCanon = new char[100001];
    char* reversedCanon = new char[100001];
    char* reversed = new char[100001];

    for (int i = 0; i < n; i++) {
        smallestRotation(strings[i], forwardCanon);
        reverseString(strings[i], reversed);
        smallestRotation(reversed, reversedCanon);

        Value* existingValue;
        if (customStrcmp(forwardCanon, reversedCanon) < 0) {
            existingValue = canonicalCounts.find(forwardCanon);
            if (existingValue) {
                existingValue->forwardCount++;
            } else {
                Value newValue;
                newValue.forwardCount = 1;
                newValue.reversedCount = 0;
                canonicalCounts.insert(forwardCanon, newValue);
            }
        } else {
            existingValue = canonicalCounts.find(reversedCanon);
            if (existingValue) {
                existingValue->reversedCount++;
            } else {
                Value newValue;
                newValue.forwardCount = 0;
                newValue.reversedCount = 1;
                canonicalCounts.insert(reversedCanon, newValue);
            }
        }
    }

    delete[] forwardCanon;
    delete[] reversedCanon;
    delete[] reversed;
    inputFile.close();

    // Calculate minimal subset and reverse operations
    int reverseOps = 0;
    int minimalSubset = 0;
    Node** table = canonicalCounts.getTable();
    for (int i = 0; i < hashTableSize; i++) {
        Node* current = table[i];
        while (current) {
            int forwardCount = current->value.forwardCount;
            int reversedCount = current->value.reversedCount;
            minimalSubset++;
            reverseOps += customMin(forwardCount, reversedCount);
            current = current->next;
        }
    }

    outputFile << reverseOps << endl;
    outputFile << minimalSubset << endl;

    for (int i = 0; i < n; i++) {
        delete[] strings[i];
    }
    delete[] strings;

    outputFile.close();
    return 0;
}



