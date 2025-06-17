/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of Heap header file
*/


#ifndef __HEAP_H
#define __HEAP_H
#include "maxHeap.h"
class Heap{
    public:
    Heap();
    
    void addKey(int key);
    void deleteTop();
    void rebuild(int iterator);
    int getTop();
    int* getMinFive();
    int getCurrentSize();
    ~Heap();
    private:
    int maxSize;
    int* arr;
    int current;
    int* minFive;
    void updateFive(int key);

    


};

#endif