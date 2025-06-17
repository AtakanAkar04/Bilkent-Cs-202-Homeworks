/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of prefixsubarray cpp file
*/
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include "prefixsubarray.h"

using namespace std;

prefixsubarray::prefixsubarray(std::string inputFile, std::string outputFile)
{
    inputFilename = inputFile;
    outputFilename = outputFile;

}

void prefixsubarray::process() {
    ifstream inFile(inputFilename.c_str());
    if (!inFile) {
        cerr << "Error: Cannot open input file." << endl;
        exit(1);
    }
    int M = 0;
    int size = 0;
    inFile >> size >> M;
    int min = size+1;
    int* A = new int[size];
    int* B = new int[size];
    for (int i = 0; i < size; i++) {
        inFile >> A[i];
    }

    for (int i = 0; i < size; i++) {
        inFile >> B[i];
    }
    
    int left = 0;
    int right = size-1;
    while(left <= right){
        int mid = (right+left)/2;
        if(mid+1 < M){
            left = mid+1;
        }
        else{
            Heap heapA; 
            maxHeap heapB;
            int iterator = 0;
            while(iterator < M){
                heapA.addKey(A[iterator]);
                heapB.addKey(B[iterator]);
                iterator ++;
            }
            iterator = M;
            while(iterator <= mid){
                if(A[iterator] > heapA.getTop()){
                    heapA.deleteTop();
                    heapA.addKey(A[iterator]);
                }
                if(B[iterator] < heapB.getTop()){
                    heapB.deleteTop();
                    heapB.addKey(B[iterator]);
                }
                iterator++;
            }

            if(isSatisfied(heapA,heapB,M)){
                min = mid+1;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
            
    }
    
    
    ofstream outFile(outputFilename.c_str());
        if (!outFile) {
            cerr << "Error: Cannot open output file." << endl;
            exit(1);
        }

        outFile << min << endl;
        outFile.close();

    delete[] A;
    delete[] B;
}
bool prefixsubarray::isSatisfied(Heap& heapA,maxHeap& heapB,int required){
    int* A = new int[required];
    int* B = new int[required];
    bool is = true;
    int it1 = required-1;
    while(heapA.getCurrentSize() != 0){
        A[it1] = heapA.getTop();
        heapA.deleteTop();
        it1 --;
    }
    it1 = 0;
    while(heapB.getCurrentSize() != 0){
        B[it1] = heapB.getTop();
        heapB.deleteTop();
        it1 ++;
    }
    for(int i = 0;i < required;i++){
        if(A[i] <= B[i]){

            is = false;
            break;
        }
    }
    delete[] A;
    delete[] B;
    return is;
}




int main(int argc, char* argv[]) {
    // Check for at least an input file argument
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_filename> [output_filename]" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = "";
    if (argc > 2) {
        outputFile = argv[2];
    }

    
    prefixsubarray prefixSubArrayInstance(inputFile, outputFile);


    prefixSubArrayInstance.process();

    return 0;
}