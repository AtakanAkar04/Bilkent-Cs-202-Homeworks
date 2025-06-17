/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of prefixsubarray header file
*/
#ifndef PREFIXSUBARRAY_H
#define PREFIXSUBARRAY_H

#include "maxHeap.h"
#include <string>
#include "Heap.h"
using namespace std;
//#include <string>
class prefixsubarray {
public:
    prefixsubarray(string inputFilename, string outputFilename = "");
    void process();
    bool isSatisfied(Heap& heapA,maxHeap& heapB,int required);

private:
    string inputFilename;
    string outputFilename;
    
};

#endif