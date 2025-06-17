/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of subarray cpp file
*/


#include "subarray.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


subarray::subarray(string inputFile, string outputFile){
    inputFilename = inputFile;
    outputFilename = outputFile;
}

void subarray::process() {
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Error:" << inputFilename << endl;
        return;
    }
     int N, M, K;
    inputFile >> N >> M >> K;
    int* A = new int[N];
    int* B = new int[N];
        
    for (int i = 0; i < N; ++i) {
        inputFile >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        inputFile >> B[i];
    }

    int left = 0;
    int minLength = N+1;
    while(left < N){
        maxHeap heapB;
        Heap heapA;
        for(int i = left;i <N ;i++){
            if(heapB.getCurrentSize() < K){
                heapB.addKey(B[i]);
            }
            else{
                if(heapB.getTop() > B[i]){
                    heapB.deleteTop();
                    heapB.addKey(B[i]);
                }
            }
            if(heapA.getCurrentSize() < M){
                heapA.addKey(A[i]);
            }
            else{
                if(heapA.getTop() < A[i]){
                    heapA.deleteTop();
                    heapA.addKey(A[i]);
                }
            }
            if(heapA.getCurrentSize() == M && heapB.getCurrentSize() == K){
                if(heapA.getTop() > heapB.getTop()){
                    if((i - left + 1) < minLength){
                        minLength =  i - left + 1;
                    }
                    break;
                }
            }
        }
        left++;
    }


    ofstream outputFile;
    if (!outputFilename.empty()) {
        outputFile.open(outputFilename);
        if (!outputFile.is_open()) {
            cerr << "Error:" << outputFilename << endl;
            return;
        }
    }

    if (outputFile.is_open()) {
        outputFile << minLength << endl;
    } else {
        cout << minLength << endl;
    }

    delete[] A;
    delete[] B;

   

    inputFile.close();
    if (outputFile.is_open()) {
        outputFile.close();
    }
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_filename> [output_filename]" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = "";
    if (argc > 2) {
        outputFile = argv[2];
    }

    subarray subarraysProcessor(inputFile, outputFile);
    subarraysProcessor.process();

    return 0;
}
