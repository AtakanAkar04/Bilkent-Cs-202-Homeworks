/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of least5 header file
*/


#ifndef LEAST5_H
#define LEAST5_H

#include "Heap.h"
#include <string>
using namespace std;
//#include <string>
class least5 {
public:
    least5(string inputFilename, string outputFilename = "");
    void process();

private:
    string inputFilename;
    string outputFilename;
    Heap heap;
};

#endif