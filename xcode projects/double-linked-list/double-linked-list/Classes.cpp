//
//  Classes.cpp
//  double-linked-list
//
//  Created by Mark Garcia on 2/3/23.
//

#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node* next;
    
    Node(int value) {
        this->value = value;
    }
};

class DoubleLinkedList {
public:
    Node* head;
    Node* tail;
    int length;
    
    DoubleLinkedList(int value) {
        Node* tmp = new Node(value);
        head = tmp;
        tail = tmp;
        length++;
    }
    
    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length += 1;
    }
    
    void prepend(int value) {
        Node* tmp = new Node(value);
        if (length == 0) {
            head = tmp;
            tail = tmp;
        } else {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
        length++;
    }
    
    void pop() {
        
    }
    
    void shift() {
        
    }
    
    Node* get(int index) {
        return nullptr;
    }
    
    void set(int index, int value) {
        
    }
    
    void insert(int index, int value) {
        
    }
    
    void deleteAt(int index) {
        
    }
    
    void print() {
        Node* tmp = head;
        
        while(tmp) {
            cout << tmp->value << " -> ";
            tmp = tmp->next;
        }
        cout << "end" << endl;
    }
};
