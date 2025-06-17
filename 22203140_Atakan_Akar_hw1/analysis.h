/**
* Title: Binary Search Trees
* Author : Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 1
* Description : Anlaysis header file implementation 
*/


#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>
#include <ctime>      
#include <cstdlib>
#include "BST.h"    
using namespace std;

int getHeight(TreeNode* node);
void arrangeTheInsertionOrder(int arr[], int newArr[], int first, int last,int* itera);
void timeAnalysis();
void sortForBetterTreePreperation(int arr[],int size);
#endif