/**
* Title: Binary Search Trees
* Author : Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 1
* Description : Tree Node that are in Binary search tree cpp file implementation 
*/

#include "TreeNode.h"

using namespace std;

TreeNode::TreeNode(int a){
    item = a;
    leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}
TreeNode::TreeNode(){
    item = 0;
    leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}