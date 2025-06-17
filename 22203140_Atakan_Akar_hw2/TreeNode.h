/**
* Title: Binary Search Trees
* Author : Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 1
* Description : Tree Node that are in Binary search tree header file implementation 
*/
#ifndef __TREENODE_H
#define __TREENODE_H

#include <iostream>
using namespace std;

class TreeNode{
public:
    TreeNode();
    TreeNode(int a);
    int item; 
    TreeNode *leftChildPtr;
	TreeNode *rightChildPtr; 
};
#endif