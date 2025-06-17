/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of game cpp file
*/


#include "game.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include "BST.h"

using namespace std;

game::game(std::string inputFile, std::string outputFile)
{
    inputFileName = inputFile;
    outputFileName = outputFile;
    bobo = 0;
    holosko = 0;
}
void game::process() {
    ifstream inFile(inputFileName.c_str());
    if (!inFile) {
        cerr << "Error: Cannot open input file." << endl;
        exit(1);
    }

    int size;
    inFile >> size;

    int cardsBobo[size];
    int cardsHolosko[size];


    for (int i = 0; i < size; i++) {
        inFile >> cardsBobo[i];
    }

    for (int i = 0; i < size; i++) {
        inFile >> cardsHolosko[i];
    }
    BST bstBobo;
    BST bstHolosko;
    inFile.close();
    bstBobo.heapSort(cardsBobo,size);
    bstHolosko.heapSort(cardsHolosko,size);

    int* iterator1 = new int();
    int* iterator2 = new int();
    (*iterator1) = 0;
    (*iterator2) = 0;

    int optimumBobo[size];
    int optimumHolosko[size];
    for(int i = 0; i < size;i++){
        optimumBobo[i] =0;
        optimumHolosko[i] =0;
    }


    bstBobo.arrangeTheInsertionOrder(cardsBobo,optimumBobo,0,size-1,iterator1);
    bstHolosko.arrangeTheInsertionOrder(cardsHolosko,optimumHolosko,0,size-1,iterator2);

    delete iterator1;
    delete iterator2;
    for(int i = 0; i < size;i++){
        bstBobo.insertKey(optimumBobo[i]);
        bstHolosko.insertKey( optimumHolosko[i]);
    }

    int turn = 0;
    int iterator = 0;
    while(iterator < size){
        if(turn == 0){
            int boboCard = bstBobo.findMax();
            int holoskoCard = bstHolosko.findOponent(boboCard);
            if (holoskoCard != -1) {
                bstBobo.deleteKey(boboCard);   
                bstHolosko.deleteKey(holoskoCard);
                bobo++; 
            } 
            if(holoskoCard == -1){
                holosko++;
                bstBobo.deleteKey(boboCard);  
                int max = bstHolosko.findMax();   
                bstHolosko.deleteKey(max);
            }
            turn = 1;
        }
        else{
            turn = 0;
            int holoskoCard = bstHolosko.findMax();
            int boboCard = bstBobo.findOponent(holoskoCard);
            if (boboCard != -1) {
                holosko++; 
                bstBobo.deleteKey(boboCard);   
                bstHolosko.deleteKey(holoskoCard);
            } 
            if(boboCard == -1){
                bobo++;
                bstHolosko.deleteKey(holoskoCard);
                int max = bstBobo.findMax();   
                bstBobo.deleteKey(max);
            }
        }
        iterator ++;
    }


    


   if (outputFileName.empty()) {
        cout << bobo << " " << holosko << endl;
    } else {
        ofstream outFile(outputFileName.c_str());
        if (!outFile) {
            cerr << "Error: Cannot open output file." << endl;
            exit(1);
        }
        outFile << bobo << " " << holosko << endl;
        outFile.close();
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_filename> [output_filename]" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = "";
    if (argc > 2) {
        outputFile = argv[2];
    }


    game cardGame(inputFile, outputFile);
    cardGame.process();

    return 0;
}
