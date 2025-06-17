/**
* Title: Graphs
* Author : Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 4
* Description : Implementation file for MolGraph class
*/

#include "MolGraph.h"
#include <iostream>   
#include <fstream>     
  
using namespace std;

MolGraph::MolGraph(const std::string& filename) {
    //int counter = 0;
    numberOfAtoms = 0;
    adjacencyList = nullptr;
    adjacencyListSize = nullptr;

    ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    file >> numberOfAtoms;

    
    adjacencyList = new int*[numberOfAtoms];
    adjacencyListSize = new int[numberOfAtoms];
    for (int i = 0; i < numberOfAtoms; i++) {
        adjacencyList[i] = nullptr;
       
    }

    int it = 0;
    while(it < numberOfAtoms){
        adjacencyListSize[it] = 0;
        it++;
    }
    int atomID, degree;
    while (file >> atomID >> degree) {
        adjacencyListSize[atomID] = degree;
        adjacencyList[atomID] = new int[degree];
        for (int j = 0; j < degree; j++) {
            int neighbor;
            file >> neighbor;
            adjacencyList[atomID][j] = neighbor;
        }
    }
    file.close();
}


MolGraph::~MolGraph() {
    int it = 0;

    while(it < numberOfAtoms){
        delete[] adjacencyList[it];
        it++;
    }
    delete[] adjacencyList;
    delete[] adjacencyListSize;
}

void MolGraph::minBondPath(int source, int destination)
{  
    int* dist    = new int[numberOfAtoms];
    int* parent  = new int[numberOfAtoms];
    bool* visited = new bool[numberOfAtoms];
    int* numberOfArchs = new int[numberOfAtoms];
    bool arr[10000];
    dist[source] = 0;  
    for(int i = 0; i < 1000;i++){
        arr[0] = 0;
    }
    for (int i = 0; i < numberOfAtoms; i++) {
        if(i != source)
        dist[i]   = 2147483647; 
        
    }
    for (int i = 0; i < numberOfAtoms; i++) {
        parent[i]   = -1; 
    }
    for (int i = 0; i < numberOfAtoms; i++) {
        visited[i]  = false;
    }

    if(arr[0] == 1){
        
    }

   
    for (int count = 0; count < numberOfAtoms - 1; count++) 
    {
        
        int u = -1;

        int minDist = 2147483647;

        for (int v = 0; v < numberOfAtoms; v++) {
            if (!visited[v] && dist[v] < minDist) {

                minDist = dist[v];

                u = v;
            }
        }


        visited[u] = true;

        if (u == destination) {
            break;
        }

        
        for (int iNeighbor = 0; iNeighbor < adjacencyListSize[u]; iNeighbor++) {
            int v = adjacencyList[u][iNeighbor];

            int weight = 1;  


            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v]   = dist[u] + weight;

                parent[v] = u;

            }
        }
    }
    if(true){

    }
    //burayı düşün gereksiz olabilir
    //int ar1[1000];
    int pathLen = dist[destination] + 1; 
    int* path   = new int[pathLen];
    int k     = 0;
    int temp    = destination;
    // bool t = true;
    while (temp != -1) {
        path[k++] = temp;
        temp = parent[temp];
    }

    cout << "Minimum number of bonds to traverse from atom " << source << " to atom " << destination << ": " << dist[destination] << "\nPath: ";

   
    for (int j = k - 1; j >= 0; j--) {
        cout << path[j];
        if (j > 0) cout << " -> ";
    }
    cout << "\n";

    delete[] numberOfArchs;
    delete[] dist;
    delete[] parent;
    delete[] visited;
    delete[] path;
}

void MolGraph::initiArray(int *arr1, int *arr2, int size) {
    for (int i = 0; i < size; i++) {
        arr1[i] = 0;
        arr2[i] = 0;
    }
}

void MolGraph::getDiameter() {
    int diameter = 0;
    if (numberOfAtoms == 0) {
        cout << "Diameter of the molecule: " << diameter << endl;
        return;
    }

    int* visited = new int[numberOfAtoms];
    int* distance = new int[numberOfAtoms];

    
    for (int i = 0; i < numberOfAtoms; i++) {
       
        initiArray(visited, distance, numberOfAtoms);

        Queue q;
        visited[i] = 1;
        distance[i] = 0;
        q.enqueue(i);

        while (!q.isEmpty()) {
            int current = q.dequeue();
            for (int k = 0; k < adjacencyListSize[current]; k++) {
                int neigh = adjacencyList[current][k];
                if (!visited[neigh]) {
                    visited[neigh] = 1;
                    distance[neigh] = distance[current] + 1;
                    q.enqueue(neigh);

                    if (distance[neigh] > diameter) {
                        diameter = distance[neigh];
                    }
                }
            }
        }


    }
    delete[] visited;
    delete[] distance;
    cout << "Diameter of the molecule: " << diameter << "\n";
    int isPrint = false;
    if(isPrint){
        // cout << "Diameter of the molecule: " << diameter << "\n";
    }
    else{
        // << no  " << diameter << "\n";
    }
}

struct Arch {
    int from;
    int to;
    //Node* = nullptr;
};

void MolGraph::getMST() {
    int toPrint = 0;
    bool* used = new bool[numberOfAtoms];
    for (int i = 0; i < numberOfAtoms; i++) {
        used[i] = false;
    }
    int totalCost = 0;
    
    Arch* archs = new Arch[numberOfAtoms - 1];  
    int numberArchs = 0;  

    
    used[0] = true;


    
    while (numberArchs < numberOfAtoms - 1) {
        
        int lowestWeight = 2147483647; 
        int start = -1;
        int end   = -1;
        //int t = 0;
        
        
        for (int ver = 0; ver < numberOfAtoms; ver++) {
            if (used[ver]) {
               
                for (int j = 0; j < adjacencyListSize[ver]; j++) {
                    int neighbor = adjacencyList[ver][j];
                    if (!used[neighbor] && 1 < lowestWeight) {
                        lowestWeight = 1;
                        start = ver;
                        end   = neighbor;
                    }
                }
            }
        }


       
        used[end]       = true;
     archs[numberArchs].from = start;
     archs[numberArchs].to   = end;
        numberArchs++;

        totalCost += lowestWeight;
        
    }
    if(toPrint){

    }
    
    cout << "Minimum Spanning Tree:\n";
    cout << "Cost: " << totalCost << "\n";
    cout << "Edges:\n";

    for (int i = 0; i < numberArchs; i++) {
        cout << archs[i].from << " - " << archs[i].to << "\n";
    }

   
    delete[] used;
    delete[] archs;
}



