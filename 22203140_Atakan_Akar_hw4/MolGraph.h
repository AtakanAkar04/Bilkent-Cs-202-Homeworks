/**
* Title: Graphs
* Author : Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 4
* Description : Header file for MolGraph class
*/

#ifndef MOLGRAPH_H
#define MOLGRAPH_H

#include <string>
#include "Queue.h" 

class MolGraph {
private:
    int numberOfAtoms;
    int** adjacencyList;    
    int* adjacencyListSize; 

public:
    
    MolGraph(const std::string& filename);
    ~MolGraph();
    void dFsForDist(int currentNode, bool* usedArr, int* distArr);
    void minBondPath(int source, int destination);
    void getDiameter();
    void getMST();
    void initiArray(int *visited, int *distance, int size);
};

#endif 