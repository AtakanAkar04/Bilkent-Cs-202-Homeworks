/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of game header file
*/
#ifndef GAME_H
#define GAME_H
#include <string>
#include "Heap.h"
#include "maxHeap.h"

class game {
public:
    game(std::string inputFile, std::string outputFile);
    
    void process(); 
private:
    std::string inputFileName;
    std::string outputFileName;
    int bobo;
    int holosko;
    Heap heapOfBobo;
    maxHeap heapOfHolosko;
   
  
    
};

#endif