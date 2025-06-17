#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_LENGTH = 100000;
const int MOD = 1000000007;
const int P = 31;

long long modExponent(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long computeHash(const char* pattern, int length) {
    long long hash = 0;
    for (int i = 0; i < length; i++) {
        hash = (hash + ((pattern[i] - 'a' + 1) * modExponent(P, length - 1 - i, MOD)) % MOD) % MOD;
    }
    return hash;
}

int findTotal(long long hedef, long long* aranacak, int length) {
    int low = 0, high = length - 1;
    int firstIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (aranacak[mid] == hedef) {
            firstIndex = mid;
            high = mid - 1;
        } else if (aranacak[mid] < hedef) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (firstIndex == -1) return 0;

    int count = 1;
    int index = firstIndex - 1;
    while (index >= 0 && aranacak[index] == hedef) {
        count++;
        index--;
    }

    index = firstIndex + 1;
    while (index < length && aranacak[index] == hedef) {
        count++;
        index++;
    }

    return count;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error: Could not open input file " << argv[1] << "\n";
        return 1;
    }

    ofstream outputFile(argv[2]);
    if (!outputFile) {
        cerr << "Error: Could not open output file " << argv[2] << "\n";
        return 1;
    }

    char charArray[MAX_LENGTH + 1] = {0};
    int count = 0;

    while (count < MAX_LENGTH && inputFile.peek() != '\n' && inputFile.peek() != EOF) {
        char c = inputFile.get();
        if (inputFile.eof()) break;
        charArray[count++] = c;
    }
    inputFile.ignore();

    int patternCount;
    inputFile >> patternCount;
    inputFile.ignore();

    int* patternLength = new int[patternCount];
    char** patterns = new char*[patternCount];

    for (int i = 0; i < patternCount; i++) {
        patterns[i] = new char[MAX_LENGTH + 1]();
    }

    for (int i = 0; i < patternCount; i++) {
        inputFile.getline(patterns[i], MAX_LENGTH);
        patternLength[i] = strlen(patterns[i]);
    }

    long long** hashArrays = new long long*[6];
    for (int i = 0; i < 6; i++) {
        hashArrays[i] = new long long[MAX_LENGTH]();
    }

    for (int i = 0; i < 6; i++) {
        int currentPatternLength = patternLength[0] + i;
        long long currentHash = 0;

        for (int j = 0; j < currentPatternLength; j++) {
            currentHash = (currentHash + ((charArray[j] - 'a' + 1) * modExponent(P, currentPatternLength - 1 - j, MOD)) % MOD) % MOD;
        }
        hashArrays[i][0] = currentHash;

        for (int j = 1; j <= count - currentPatternLength; j++) {
            currentHash = ((currentHash - ((charArray[j - 1] - 'a' + 1) * modExponent(P, currentPatternLength - 1, MOD)) % MOD + MOD) % MOD) * P % MOD;
            currentHash = (currentHash + (charArray[j + currentPatternLength - 1] - 'a' + 1)) % MOD;
            hashArrays[i][j] = currentHash;
        }

        sort(hashArrays[i], hashArrays[i] + (count - currentPatternLength + 1));
    }

    for (int i = 0; i < patternCount; i++) {
        long long val = computeHash(patterns[i], patternLength[i]);
        int index = patternLength[i] - patternLength[0];

        if (index < 0 || index > 5) {
            outputFile << 0 << endl;
            continue;
        }

        int occurrences = findTotal(val, hashArrays[index], count - patternLength[i] + 1);
        outputFile << occurrences << endl;
    }

    for (int i = 0; i < patternCount; i++) {
        delete[] patterns[i];
    }
    delete[] patterns;
    delete[] patternLength;

    for (int i = 0; i < 6; i++) {
        delete[] hashArrays[i];
    }
    delete[] hashArrays;

    return 0;
}