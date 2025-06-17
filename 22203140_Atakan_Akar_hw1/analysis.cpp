/**
* Title: Binary Search Trees
* Author : Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 1
* Description : Analysis cpp file implementation 
*/


#include <iostream>
#include <ctime>      
#include <cstdlib>       
#include "analysis.h"
#include "BST.h"  
using namespace std;

int getHeight(TreeNode* node) {
    if (node == nullptr)
        return 0;
    else{
        int left = getHeight(node->leftChildPtr);
        int right = getHeight(node->rightChildPtr);
        if(left> right) 
            return 1 + left;
        else{
            return 1 + right;
        }
    }
    
}
void arrangeTheInsertionOrder(int arr[], int newArr[], int first, int last,int* itera){
    if(first > last){
        return;
    }
    int orta = (first + last) / 2;
    newArr[(*itera)] = arr[orta];
    (*itera)++;
    arrangeTheInsertionOrder(arr, newArr,first, orta-1,itera);
    arrangeTheInsertionOrder(arr, newArr, orta+1, last,itera);

}
void timeAnalysis() {
    BST tree;
    srand(time(0));

    clock_t start = clock(); 

    for (int i = 1; i <= 10000; ++i) {
        int randomNum = rand();
        tree.insertKeyForAnalysis(randomNum);

        if (i % 1000 == 0) {
            clock_t nowTime = clock();
            double total = double(nowTime - start) / CLOCKS_PER_SEC;
            int height = getHeight(tree.getRoot());  

            cout << "After" << i << ":" << endl;
            cout << "Time" << total  << endl;
            cout << "height " << height << endl;
            start = nowTime;  
        }
    }
    //Balance Tree
    BST balancedTree;
    int firstArray[10000];
     for(int i = 0; i < 10000;i++){
        int randomNum = rand();
        firstArray[i] = randomNum;
    }
    sortForBetterTreePreperation(firstArray,10000);
    int lastArr[10000];
    for(int i = 0;i < 10000;i++){
        lastArr[i] = 0;
    }
    int* itera = new int();
    *itera = 0;
    arrangeTheInsertionOrder(firstArray, lastArr, 0, 9999,itera);
    delete itera;
    start = clock(); 
    for (int i = 1; i <= 10000; ++i) {
        balancedTree.insertKeyForAnalysis(lastArr[i-1]);

        if (i % 1000 == 0) {
            clock_t nowTime = clock();
            double total = double(nowTime - start) / CLOCKS_PER_SEC;
            int height = getHeight(balancedTree.getRoot());  

            cout << "After " << i << " for optimized tree:" << endl;
            cout << "Time " << total << " optimized tree" << endl;
            cout << "height of the tree for optimized tree: " << height << endl;
            start = nowTime;  
        }
    }
    BST veryBadOrderedTree;
    int orderedArray[10000];
    for(int i = 0; i < 10000;i++){
        int randomNum = rand();
        orderedArray[i] = randomNum;
    }
    sortForBetterTreePreperation(orderedArray,10000);
    start = clock(); 
    for (int i = 1; i <= 10000; ++i) {
        veryBadOrderedTree.insertKeyForAnalysis(orderedArray[i-1]);

        if (i % 1000 == 0) {
            clock_t nowTime = clock();
            double total = double(nowTime - start) / CLOCKS_PER_SEC;
            int height = getHeight(veryBadOrderedTree.getRoot());  

            cout << "After " << i << " for ordered insertion tree:" << endl;
            cout << "Time: " << total << "for ordered insertion tree" << endl;
            cout << "height of the tree for ordered insertion tree: " << height << endl;
            start = nowTime;  
        }
    }
}


void sortForBetterTreePreperation(int arr[],int size){
    bool isSwapped = true;
     for (int i = 0; i < size - 1 && isSwapped; i++) {
        isSwapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = true;
            }
        }
    }
}