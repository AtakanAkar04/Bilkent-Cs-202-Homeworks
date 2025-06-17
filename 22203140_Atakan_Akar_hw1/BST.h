/**
* Title: Binary Search Trees
* Author : Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 1
* Description : Binary search tree header file
*/

#ifndef __BST_H
#define __BST_H

#include <iostream>
#include "TreeNode.h"
using namespace std;


class BST{
public:
    BST(int keys[],int size);  //checked
    BST(); //checked
    ~BST(); //checked
    void deleteBSTRecursive(TreeNode* node); //checked
    void insertKey(int key);  //checked 
    void insertKeyForAnalysis(int key); 
    void insertKeyRecursiveForAnalysis(TreeNode*& node,int key); 
    void deleteKey(int key); //checked
    void displayInorder(); //checked
    void findFullBTLevel(); //checked
    void lowestCommonAncestor(int A,int B);//checked
    void maximumSumPath(); //checked
    void maximumWidth(); //checked
    void pathFromAtoB(int A,int B); //checked
    bool insertKeyRecursive(TreeNode*& node,int key); //checked
    void inorderTraversal(TreeNode* node,bool* isFirst); //checjed
    void deleteKeyRecursive(TreeNode*& node,int key); //checked
    void findRightOfLeftMost(TreeNode*& node,int& itemToChange); //checked
    int findFullBTLevelRecursive(TreeNode* node); //checked
    TreeNode* findCommonAncestorBSTRecursive(TreeNode* node,int A,int B); //checked
    int maximumSumPathRecursive(TreeNode* node); //checked
    int findMaximumDepth(TreeNode* node);  //checked
    void printMaximumLevelRecursive(TreeNode* node,int level,int levelWanted,bool* firstPrinted); //checked
    void printingLeft(TreeNode* node,int A,int ancestorValue); 
    void insertionForStart(TreeNode*& root,int i);  //checked
    bool lookWhetherKeysExist(int A,int B);  //checked
    bool lookOneExist(TreeNode* node,int C);//checked
    void printForMaximumSumPath(TreeNode* root,bool* isFirst); //checked
    TreeNode* getRoot(); 
    TreeNode* root; //checked
    int findTheNumbersOfTheTotalNode(TreeNode* node,int wantedLevel,int currentLevel); //checked
    void printingFromRight(TreeNode* node,int A,int ancestorValue); //checked

};
#endif