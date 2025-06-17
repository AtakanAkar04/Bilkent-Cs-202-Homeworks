/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of Heap cpp file
*/


#include "Heap.h"

Heap::Heap(){
    current = 0;
    maxSize = 1000000;
    arr = new int[maxSize];
    minFive = new int[5];
    arr[0] = 0;
    for(int i = 0; i < 5;i++){
        minFive[i] = 0;
    }
}
Heap::~Heap(){
    delete[] minFive;
    delete[] arr;
}
int Heap::getTop(){
    return arr[0];
}
void Heap::addKey(int key){
    if(current < maxSize){
        arr[current] = key;
        int placed = current;
        int parent = (current-1)/2;
        while((placed > 0) && arr[placed] < arr[parent]){
            int temp = arr[placed];
            arr[placed] =  arr[parent];
            arr[parent] = temp;
            placed = parent;
            parent = (parent-1)/2;

        }
        current ++;
        updateFive(key);
    }
}
void Heap::deleteTop(){
    if(current > 0){
        int key = arr[0];
        arr[0] = arr[current-1];
        current--;
        rebuild(0);
        updateFive(key);
    }
}
void Heap::rebuild(int iterator){
    int minimum = iterator;
    if((2*iterator+1 < current) && arr[iterator*2+1] < arr[minimum]){
        minimum = 2*iterator+1;
    }
    if((2*iterator+2 < current) && arr[iterator*2+2] < arr[minimum]){
        minimum = 2*iterator+2;
    }
    if(minimum != iterator){
        int temp = arr[minimum];
        arr[minimum] = arr[iterator];
        arr[iterator] = temp;
        rebuild(minimum);
    }
}
void Heap::updateFive(int key){
    if(current < 5){
        return;
    }
    maxHeap max;
    int level = current;
    if(current > 31){
        level = 31;
    }
    int* temp = new int[level];
    
    for(int i = 0; i < level; i++) {
        temp[i] = arr[i];
    }
    for(int i = 0; i < level; i++){
        max.addKey(temp[i]);
    }
    for(int i = level-1; i >= 0;i--){
        temp[i] = max.getTop();
        max.deleteTop();
    }
    for(int i = 0; i < 5;i++){
        minFive[i] = temp[i];
    }
    
    delete[] temp;
}   
int Heap::getCurrentSize(){
    return current;
}
int* Heap::getMinFive(){
    return minFive;
}