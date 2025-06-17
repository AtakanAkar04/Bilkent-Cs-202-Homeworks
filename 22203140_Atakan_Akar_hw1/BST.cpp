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
void BST::insertionForStart(TreeNode*& node,int key){
    if(node == nullptr){
        node = new TreeNode(key);
        return;
    }
    else if(node->item < key){
        insertionForStart(node->rightChildPtr,key);
    }
    else{
        insertionForStart(node->leftChildPtr,key);
    }
}
BST::BST(int keys[],int size){
    root = nullptr;
    cout << "BST with size " << size << " is created." << endl;
    for(int i = 0; i < size;i++){
        insertionForStart(root,keys[i]);
    }
}
void BST::insertKey(int key){
    bool isAdded = insertKeyRecursive(root,key);
    if(isAdded){
        cout << "Key " << key << " is added." << endl;
    }
}
bool BST::insertKeyRecursive(TreeNode*& node, int key){
    if(node == nullptr){
        node = new TreeNode(key);
        return true;
    }
    else if(node->item == key){
        cout << "Key " << node->item << " is not added. It exists!" << endl;
        return false;
    }
    else if(node->item < key){
        return insertKeyRecursive(node->rightChildPtr,key);
    }
    else{
        return insertKeyRecursive(node->leftChildPtr,key);
    }
}
void BST::displayInorder(){
    if(root == nullptr){
        cout <<"The tree is empty." << endl;
        return;
    }
    cout << "Inorder display is:";
    bool isFirst = true;
    inorderTraversal(root,&isFirst);
    cout << endl;
}
void BST::inorderTraversal(TreeNode* node,bool* isFirst){
    if(node != nullptr){
        inorderTraversal(node->leftChildPtr,isFirst);
        if(*isFirst){
            cout << " "<<node->item ;
            *isFirst = false;
        }
        else{
            cout << ", "<<node->item ;
        }
        inorderTraversal(node->rightChildPtr,isFirst);
    }
}
void BST::deleteKey(int key){
    deleteKeyRecursive(root,key);
}
void BST::deleteKeyRecursive(TreeNode*& node,int key){
    if(node == nullptr){
        cout << "Key " << key << " is not deleted. It does not exist!" << endl;
        return;
    }
    else if(node->item == key){
        cout << "Key " << key << " is deleted." << endl;
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
void BST::findFullBTLevel(){
    if(root == nullptr){
        cout <<"The tree is empty." << endl;
        return;
    }
    int fullCount = findFullBTLevelRecursive(root);
    cout << "Full binary tree level is: "<<fullCount << endl;
}
int BST::findFullBTLevelRecursive(TreeNode* node){
    if(node == nullptr){
        return 0;
    }
        int int1 = findFullBTLevelRecursive(node->leftChildPtr);
        int int2 = findFullBTLevelRecursive(node->rightChildPtr);
        if(int1 < int2)
            return 1 + int1;
        return 1 + int2;
    
}

TreeNode* BST::findCommonAncestorBSTRecursive(TreeNode* node,int A,int B){
    if(node == nullptr){
        return nullptr;
    }
    else if(node->item > A  && node->item > B){
        return findCommonAncestorBSTRecursive(node->leftChildPtr,A,B);
    }
    else if(node->item < A  && node->item < B){
        return findCommonAncestorBSTRecursive(node->rightChildPtr,A,B);
    }
    else{
        return node;
    }
}
void BST::lowestCommonAncestor(int A,int B){
    bool b1 = lookWhetherKeysExist(A,B);
    if(!b1){
        cout << "Error: One or both keys (" << A << ", " << B << ") do not exist in the tree." << endl;
        return;
    }
    TreeNode* temp = findCommonAncestorBSTRecursive(root,A,B);
    if(temp != nullptr)
        cout << "Lowest common ancestor of " << A<< " and " << B << " is: "<<temp->item << endl;  
} 
void BST::maximumSumPath(){
    if(root == nullptr){
        cout <<"The tree is empty." << endl;
        return;
    }
    cout << "Maximum sum path is: ";
    if(root == nullptr){
        cout << endl;
        return;
    }
    bool is = true;
    printForMaximumSumPath(root,&is);
    cout << endl;
    

}
void BST::printForMaximumSumPath(TreeNode* root,bool* isFirst){
    if(root == nullptr)
        return;
    int left = maximumSumPathRecursive(root->leftChildPtr);
    int right = maximumSumPathRecursive(root->rightChildPtr);
    if(*isFirst)
        cout << root->item;
    else{
        cout <<  ", " << root->item;
    }
    *isFirst = false;
    if(root->leftChildPtr == nullptr && root->rightChildPtr == nullptr)
        return;
    if(left >= right && root->leftChildPtr != nullptr){
        printForMaximumSumPath(root->leftChildPtr,isFirst);
    }
    else{
        printForMaximumSumPath(root->rightChildPtr,isFirst);
    }

}
int BST::maximumSumPathRecursive(TreeNode* root){
    if(root == nullptr)
        return 0;
    int left = maximumSumPathRecursive(root->leftChildPtr);
    int right = maximumSumPathRecursive(root->rightChildPtr);
    if(left > right)
        return root->item + left;
    return root->item + right;
}


void BST::maximumWidth(){
    if(root == nullptr){
        cout <<"The tree is empty." << endl;
        return;
    }
    int height = findMaximumDepth(root);
    cout << "Maximum level is:";
    int maxLevel = 0;
    int maxCount = 0;
    
    if(height != 0){
        
        for(int i = 0; i < height;i++){
            int current = findTheNumbersOfTheTotalNode(root,i,0);
            if(current > maxCount){
                maxCount = current;
                maxLevel = i;
            }
        }
        bool firstPrinted = true;
        printMaximumLevelRecursive(root,0,maxLevel,&firstPrinted);
    }
    else{
        cout << " 0";
    }
    cout << endl;
}
int BST::findTheNumbersOfTheTotalNode(TreeNode* node,int wantedLevel,int currentLevel){
    if(node == nullptr || currentLevel > wantedLevel){
        return 0;
    }
    if(wantedLevel == currentLevel)
        return 1;
    
    int left = findTheNumbersOfTheTotalNode(node->leftChildPtr,wantedLevel,currentLevel+1);
    int right = findTheNumbersOfTheTotalNode(node->rightChildPtr,wantedLevel,currentLevel+1);
    return left + right;
}
void BST::printMaximumLevelRecursive(TreeNode* node, int level,int levelWanted,bool* firstPrinted){
    if(node != nullptr){
        printMaximumLevelRecursive(node->leftChildPtr,level+1,levelWanted,firstPrinted);
        if(level == levelWanted){
            if(*firstPrinted){
                *firstPrinted = false;
                cout << " "<<node->item;
            }
            else{
                cout << ", "<<node->item;
            }

        }
        printMaximumLevelRecursive(node->rightChildPtr,level+1,levelWanted,firstPrinted);
    }
}
int BST::findMaximumDepth(TreeNode* node){
    if(node == nullptr)
        return 0;
    int intLeft = 1 + findMaximumDepth(node->leftChildPtr);
    int intRight = 1 + findMaximumDepth(node->rightChildPtr);
    if(intLeft > intRight)
        return intLeft;
    return intRight;
}
void BST::pathFromAtoB(int A,int B){
    bool b1 = lookWhetherKeysExist(A,B);
    if(!b1){
        cout << "Error: One or both keys (" << A << ", " << B << ") do not exist in the tree." << endl;
        return;
    }
    TreeNode* ancestor = findCommonAncestorBSTRecursive(root,A,B);
    cout << "Path from " << A << " to " << B << " is: " ;
    if(A == B){
        cout << A << endl;
        return;
    }
    else if(A == ancestor->item && B > ancestor->item){
        cout << A ;
        TreeNode* temp = ancestor->rightChildPtr;
        bool is = true;
        while(is){
            if(temp->item == B)
                is = false;
            cout << ", "<<temp->item ;
            if(temp->item < B){
                temp = temp->rightChildPtr;
            }
            else{
                temp = temp->leftChildPtr;
            }
        }
    }
    else if(A == ancestor->item && B < ancestor->item){
        cout << A;
        TreeNode* temp = ancestor->leftChildPtr;
        bool is = true;
        while(is){
            if(temp->item == B)
                is = false;
            cout << ", "<<temp->item ;
            if(temp->item < B){
                temp = temp->rightChildPtr;
            }
            else{
                temp = temp->leftChildPtr;
            }
        }
        
    }
    else if(A > ancestor->item && B == ancestor->item){
        printingFromRight(ancestor,A,ancestor->item);
        cout << B;
    }
    else if(A < ancestor->item && B == ancestor->item){
        printingLeft(ancestor,A,ancestor->item);
        cout << B;
    }
    else if(A < ancestor->item && B > ancestor->item){
        printingLeft(ancestor,A,ancestor->item);
        TreeNode* temp = ancestor->rightChildPtr;
        cout << ancestor->item;
        bool is = true;
        while(is){
            if(temp->item == B)
                is = false;
            cout << ", "<<temp->item ;
            if(temp->item < B){
                temp = temp->rightChildPtr;
            }
            else{
                temp = temp->leftChildPtr;
            }
        }
    }
    else if(A > ancestor->item && B < ancestor->item){
        printingFromRight(ancestor,A,ancestor->item);
        TreeNode* temp = ancestor->leftChildPtr;
        cout << ancestor->item;
        bool is = true;
        while(is){
            if(temp->item == B)
                is = false;
            cout << ", "<<temp->item ;
            if(temp->item < B){
                temp = temp->rightChildPtr;
            }
            else{
                temp = temp->leftChildPtr;
            }
        }
    }
    cout << endl;
}
void BST::printingLeft(TreeNode* node,int A,int ancestorValue){
    if(node->item == A){
        cout << node->item << ", ";
        return;
    }
    if(node->item > A)
        printingLeft(node->leftChildPtr,A,ancestorValue);
    else{
        printingLeft(node->rightChildPtr,A,ancestorValue);
    }
    if(node->item != ancestorValue)
        cout << node->item << ", ";
}
void BST::printingFromRight(TreeNode* node,int A,int ancestorValue){
    if(node->item == A){
        cout << node->item << ", ";
        return;
    }
    if(node->item > A)
        printingLeft(node->leftChildPtr,A,ancestorValue);
    else{
        printingLeft(node->rightChildPtr,A,ancestorValue);
    }
    if(node->item != ancestorValue)
        cout << node->item << ", ";
}
bool BST::lookWhetherKeysExist(int A,int B){
    bool b1 = lookOneExist(root,A);
    bool b2 = lookOneExist(root,B);
    return b1 && b2;
}
bool BST::lookOneExist(TreeNode* node,int C){
    if(node == nullptr)
        return false;
    if(node->item == C)
        return true;
    if(node->item > C)
        return lookOneExist(node->leftChildPtr,C);
    
    return lookOneExist(node->rightChildPtr,C);
}
TreeNode* BST::getRoot(){
    return root;
}
void BST::insertKeyForAnalysis(int key){
    insertKeyRecursiveForAnalysis(root,key);
}
void BST::insertKeyRecursiveForAnalysis(TreeNode*& node,int key){
    if(node == nullptr){
        node = new TreeNode(key);
    }
    else if(node->item == key){
        cout << "Key " << node->item << " is not added. It exists!" << endl;
    }
    else if(node->item < key){
        insertKeyRecursive(node->rightChildPtr,key);
    }
    else{
        insertKeyRecursive(node->leftChildPtr,key);
    }
}



