/**
* Title: Graphs
* Author : Atakan Akar
* ID: 22203140
* Section : 1
* Homework : 4
* Description : Implementation file for a linked-list–based queue using a struct Node
*/

#include "Queue.h"

Queue::Queue() {
    
    front = nullptr;
    rear  = nullptr;
}

Queue::~Queue() {
    
    while (!isEmpty()) {
        dequeue();
    }
}

bool Queue::isEmpty() const {
    return (front == nullptr);
}

void Queue::enqueue(int val) {
    
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear  = newNode;
    } else {
        rear->next = newNode;
        rear       = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        
        return -1;
    }

    
    int val = front->data;
    
  
    Node* temp = front;
    front = front->next;
    
   
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    return val;
}
