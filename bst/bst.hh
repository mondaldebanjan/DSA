#ifndef BST_HH
#define BST_HH

#include <iostream>
#include "bt.hh"
using namespace std;

void printBT(Tree_node* node);
Tree_node* insert(Tree_node* p, int data);
Tree_node* iter_insert(Tree_node* p, int data);
bool search(Tree_node* currentNode, int data);
Tree_node* deleteNode(Tree_node* currentNode, int data);
#endif