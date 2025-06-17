/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of least5 cpp file
*/



#include "least5.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

least5::least5(string inputFile, string outputFile){
    inputFilename = inputFile;
    outputFilename = outputFile;
}

void least5::process() {
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Error:" << inputFilename << endl;
        return;
    }

    ofstream outputFile;
    if (!outputFilename.empty()) {
        outputFile.open(outputFilename);
        if (!outputFile.is_open()) {
            cerr << "Error:" << outputFilename << endl;
            return;
        }
    }

    ostream& output = outputFilename.empty() ? cout : outputFile;
    
    string line;
    int numLines = 0;
    if (getline(inputFile, line)) {
        istringstream iss(line);
        iss >> numLines;
        //cout << "line countu " << numLines << endl;
    }
    int it = 0;
    while (getline(inputFile, line) && it <= numLines) {
        istringstream iss(line);
        char charInput;
        iss >> charInput;

        if (charInput == 'a') {
            int value;
            iss >> value;
            heap.addKey(value);

        } else if (charInput == 'r') {
            heap.deleteTop();
        } 
        else if (charInput == 'g') {
            int c = heap.getCurrentSize();
            if( c < 5){
                output << -1;
                output << endl;
            }
            else{
                int* p = heap.getMinFive();
                for (int i = 0; i < 5;i++) {
                    int num = p[i];
                    output << num << endl;
                    cout << num << endl;
                }
            }

            
        }
        it++;
        

    }

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
    if((argc > 2)){
        outputFile = argv[2];
    }

    least5 least5Pro(inputFile, outputFile);
    least5Pro.process();

    return 0;
}