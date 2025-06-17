/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of maxheap cpp file
*/
#include "maxHeap.h"
#include <iostream>

maxHeap::maxHeap(){
    current = 0;
    maxSize = 1000000;
    arr = new int[maxSize];
}
int maxHeap::getTop(){
    return arr[0];
}
bool maxHeap::isEmpty(){
    if(current == 0)
        return true;
    return false;
}
void maxHeap::addKey(int key){
    if(current < maxSize){
        arr[current] = key;
        int placed = current;
        int parent = (current-1)/2;
        while((placed > 0) && arr[placed] > arr[parent]){
            int temp = arr[placed];
            arr[placed] =  arr[parent];
            arr[parent] = temp;
            placed = parent;
            parent = (parent-1)/2;

        }
        current ++;
    }
}
void maxHeap::deleteTop(){
    if(current > 0){
        arr[0] = arr[current-1];
        current--;
        rebuild(0);
    }
}
void maxHeap::rebuild(int iterator){
    int max = iterator;
    if((2*iterator+1 < current) && arr[iterator*2+1] > arr[max]){
        max = 2*iterator+1;
    }
    if((2*iterator+2 < current) && arr[iterator*2+2] > arr[max]){
        max = 2*iterator+2;
    }
    if(max != iterator){
        int temp = arr[max];
        arr[max] = arr[iterator];
        arr[iterator] = temp;
        rebuild(max);
    }
} 
int maxHeap::getCurrentSize(){
    return current;
}
void maxHeap::printHeap(){
    for(int i = 0; i < current;i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
maxHeap::~maxHeap() {
    delete[] arr; 
}


