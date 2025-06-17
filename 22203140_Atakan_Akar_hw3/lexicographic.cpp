#include <iostream>
#include <fstream>

using namespace std;



int compareLexicographical(int num1, int num2) {

    if (num1 < num2) {
        return -1; // num1 is lexicographically smaller
    } else if (num1 > num2) {
        return 1; // num1 is lexicographically larger
    } else {
        return 0; // num1 and num2 are lexicographically equal
    }
}
void print2DArray(int** array, int size) {
    cout << "2D Array (data):" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void printArray(int* array, int size, const char* name) {
    cout << name << ":" << endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    // Argüman kontrolü
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // Dosyayı aç
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << argv[1] << endl;
        return 1;
    }
    ofstream outputFile(argv[2]);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open file " << argv[2] << endl;
        inputFile.close();
        return 1;
    }
    int tableSize;
    int* hashTable = nullptr; // Dinamik dizi için gösterici

    // İlk satırdan tablo boyutunu oku
    inputFile >> tableSize;
    if (tableSize <= 0 || inputFile.fail()) {
        cerr << "Error: Invalid input format (table size not found or invalid)." << endl;
        inputFile.close();
        return 1;
    }

    // Dinamik dizi oluştur
    hashTable = new int[tableSize];

    // Hash tablosu değerlerini oku
    for (int i = 0; i < tableSize; ++i) {
        inputFile >> hashTable[i];
        if (inputFile.fail()) {
            cerr << "Error: Invalid input format (table values not complete)." << endl;
            delete[] hashTable; // Belleği serbest bırak
            inputFile.close();
            return 1;
        }
    }
    int** data = new int*[tableSize];
    for(int i = 0; i < tableSize;i++){
        data[i] = new int[tableSize];
    }
    for(int i = 0; i < tableSize;i++){
        for(int j = 0; j < tableSize;j++){
            data[i][j] = 0;
        }
    }
    
    int* counter = new int[tableSize];
    for(int i = 0; i < tableSize;i++){
        counter[i] = 0;
    }

    for(int i = 0; i < tableSize;i++){
        if(hashTable[i] != -1){
            int where = hashTable[i] % tableSize;
            
            
            if(where != i){
                if(where < i){
                    for(int j = where ; j < i;j++){
                        data[i][j] = 1;
                        counter[i] += 1;
                    }
                }
                else{
                    int it2 = 0;
                    while(it2 < tableSize){
                        if(it2 < i || it2 >= where){
                            data[i][it2] = 1;
                            counter[i] += 1;
                        }
                        it2++;
                    }
                }
                
            }

        }
        else{
            counter[i] = -1;
        }
    }

    

    // Counter array yazdır
    
    int* result = new int[tableSize];
    int resultLength = 0;
    int nonEmpty = 0;
    for(int i = 0; i < tableSize;i++){
        if(counter[i] != -1){
            nonEmpty++;
        }
    }
    bool is = true;
    
    while(is){
        int it = 0;
        bool isFirst = true;
        int minLegi = 0;
        is = false;
        int index = 0;
        while(it < tableSize){
            if(counter[it] == 0){
                
                if(isFirst){
                    minLegi = hashTable[it];
                    isFirst = false;
                    index = it;
                    //result[resultLength] = minLegi;
                    //resultLength++;
                }
                else{
                    int compareResult = compareLexicographical(minLegi,hashTable[it]);
                    if(compareResult != -1){
                        minLegi = hashTable[it];
                        index = it;
                        //result[resultLength] = minLegi;
                        //resultLength++;
                    }
                }
                is = true;
            }
            it++;
        }
        if(is){
            counter[index] = -2;
            result[resultLength] = hashTable[index];
            resultLength++;
            for(int i = 0; i < tableSize;i++){
                if(data[i][index] == 1){
                    data[i][index] = 0;
                    counter[i] = counter[i] -1;
                }
            }
        }
        
    }

if (nonEmpty == resultLength) {
        for (int i = 0; i < resultLength; i++) {
            if(i != resultLength-1){
                outputFile << result[i] << " ";
            }
            else{
                outputFile << result[i];
            }  
        }
    } else {
        outputFile << "Impossible" << endl;
    }

    
    delete[] hashTable;
    delete[] counter;
    for (int i = 0; i < tableSize; i++) {
        delete[] data[i];
    }
    delete[] data;
    delete[] result;

    inputFile.close();
    outputFile.close();

    return 0;
}

