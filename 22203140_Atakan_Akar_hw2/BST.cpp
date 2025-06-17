/**
* Title: Binary Search Trees
* Author : Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 1
* Description : Binary search tree cpp file implementation 
*/



#include "BST.h"

#include <iostream>
using namespace std;
BST::~BST(){
    deleteBSTRecursive(root);
    root = nullptr;
}
void BST::deleteBSTRecursive(TreeNode* node){
    if(node != nullptr){
        deleteBSTRecursive(node->leftChildPtr);
        deleteBSTRecursive(node->rightChildPtr);
        delete node;
    }
}
BST::BST(){
    root = nullptr;
}

void BST::insertKey(int key){
    bool isAdded = insertKeyRecursive(root,key);
    if(isAdded){
    }
}
bool BST::insertKeyRecursive(TreeNode*& node, int key){
    if(node == nullptr){
        node = new TreeNode(key);
        return true;
    }
    else if(node->item == key){
        return false;
    }
    else if(node->item < key){
        return insertKeyRecursive(node->rightChildPtr,key);
    }
    else{
        return insertKeyRecursive(node->leftChildPtr,key);
    }
}

void BST::deleteKey(int key){
    deleteKeyRecursive(root,key);
}
void BST::deleteKeyRecursive(TreeNode*& node,int key){
    if(node == nullptr){
        return;
    }
    else if(node->item == key){
        if(node->leftChildPtr == nullptr && node->rightChildPtr == nullptr){
            TreeNode* delPtr = node;
            node = nullptr;
            delete delPtr;
        }
        else if(node->leftChildPtr != nullptr && node->rightChildPtr == nullptr){
            TreeNode* delPtr = node;
            node = node->leftChildPtr;
            delete delPtr;
        }
        else if(node->leftChildPtr == nullptr && node->rightChildPtr != nullptr){
            TreeNode* delPtr = node;
            node = node->rightChildPtr;
            delete delPtr;
        }
        else{
            findRightOfLeftMost(node->rightChildPtr,node->item);
        }
    }
    else if(node->item > key){
        deleteKeyRecursive(node->leftChildPtr,key);
    }
    else{
        deleteKeyRecursive(node->rightChildPtr,key);
    }
}
void BST::findRightOfLeftMost(TreeNode*& node,int& itemToChange){
    if(node->leftChildPtr == nullptr){
        itemToChange = node->item;
        TreeNode* delPtr = node;
        node = node->rightChildPtr;
        delete delPtr;
    }
    else{
        findRightOfLeftMost(node->leftChildPtr,itemToChange);
    }
}




TreeNode* BST::getRoot(){
    return root;
}

int BST::findMax() {
    if (root == nullptr) {
        return -1; 
    }
    TreeNode* current = root;
    while (current->rightChildPtr != nullptr) {
        current = current->rightChildPtr;
    }
    return current->item; 
}
int BST::findOponent(int key) {
    TreeNode* current = root;
    int predecessor = -1;

    while (current != nullptr) {
        if (current->item < key) {
            if(predecessor < current->item){
                predecessor = current->item;
            }
                
            current = current->rightChildPtr;
        } else {
            current = current->leftChildPtr;
        }
    }
    return predecessor;
}
void BST::heapSort(int* arr,int size){
    for (int index = (size/2) - 1 ;  index >= 0 ;  index--){
        heapRebuild(arr, index, size);
    }
        for (int end = size - 1; end > 0; end--) {
        int temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;
        
        heapRebuild(arr, 0, end);
    }
}
void BST::heapRebuild(int* arr, int index,int size){
    int largest = index;
    if(2*index + 1 < size && arr[2*index + 1] > arr[largest]){
        largest = 2*index + 1;
    }
    if(2*index + 2 < size && arr[2*index + 2] > arr[largest]){
        largest = 2*index + 2;
    }
    if(largest != index){
        int temp = arr[largest];
        arr[largest] = arr[index];
        arr[index] = temp;
        heapRebuild(arr,largest,size);

    }

}
void BST::arrangeTheInsertionOrder(int* arr, int* newArr, int first, int last,int* itera){
    if(first > last){
        return;
    }
    int orta = (first + last) / 2;
    newArr[(*itera)] = arr[orta];
    (*itera)++;
    arrangeTheInsertionOrder(arr, newArr,first, orta-1,itera);
    arrangeTheInsertionOrder(arr, newArr, orta+1, last,itera);

}




