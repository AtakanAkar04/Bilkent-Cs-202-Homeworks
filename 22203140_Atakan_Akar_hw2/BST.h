/**
* Title: AVL Trees & Heap
* Author: Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 2
* Description : Implementataiton of BST header file
*/


#ifndef __BST_H
#define __BST_H

#include <iostream>
#include "TreeNode.h"
#include "maxHeap.h"

using namespace std;



class BST{
public:
    BST(); //checked
    ~BST(); //checked
    void deleteBSTRecursive(TreeNode* node); //checked
    void insertKey(int key);  //checked 
    void deleteKey(int key); //checked
    bool insertKeyRecursive(TreeNode*& node,int key); //checked
    void deleteKeyRecursive(TreeNode*& node,int key); //checked
    void findRightOfLeftMost(TreeNode*& node,int& itemToChange); //checked
    TreeNode* getRoot(); 
    TreeNode* root; //checked
    int findMax();
    int findOponent(int key);
    void heapSort(int* arr,int size);
    void heapRebuild(int* arr, int index,int size);
    void arrangeTheInsertionOrder(int arr[], int newArr[], int first, int last,int* itera);

};
#endif