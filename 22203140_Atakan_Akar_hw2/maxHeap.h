/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of max heap header file
*/
#ifndef __MAXHEAP_H
#define __MAXHEAP_H

class maxHeap{
    public:
    maxHeap();
    void addKey(int key);
    void deleteTop();
    void rebuild(int iterator);
    int getCurrentSize();
    int getTop();
    bool isEmpty();
    void printHeap();
    ~maxHeap();
    int* arr;
    private:
    int maxSize;
    int current;

    


};

#endif