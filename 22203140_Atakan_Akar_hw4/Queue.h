/**
* Title: Graphs
* Author : Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 4
* Description : Header file for a linked-list–based queue using a struct Node
*/

#ifndef QUEUE_H
#define QUEUE_H


struct Node {
    int data;
    Node* next;
};

class Queue {
public:
    Queue();         
    ~Queue();       

    bool isEmpty() const;  
    void enqueue(int val); 
    int dequeue();         

private:
    Node* front;     
    Node* rear;      
};

#endif 
