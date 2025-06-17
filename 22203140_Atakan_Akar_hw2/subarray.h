/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of subarray header file
*/


#ifndef __SUBARRAY_H
#define __SUBARRAY_H
#include "maxHeap.h"
#include "Heap.h"
#include <string>
using namespace std;
class subarray{
    public:
    subarray(string inputFilename, string outputFilename = "");
    void process();
    private:
    string inputFilename;
    string outputFilename;

    


};

#endif