#ifndef LL_H
#define LL_H

#include<iostream>
#include <limits.h>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
} Node;


Node* insertNode(Node* currentNode, int data);
void newNode(Node** currentNode, int data);
int countNodes(Node *currentNode);
int sumOfNodes(Node *currentNode);
void displayNode(Node *currentNode);
int findMax(Node *currentNode);
int searchElemnt(Node *currentNode, int num, int current_index = 0);
Node* insetAtBegin(Node* currentNode, int data);
Node* insertAt(Node* currentNode, int data, int index);
Node* deleteAtEnd(Node* currentNode);
#endif