#ifndef BT_HH 
#define BT_HH

#include <iostream>
using namespace std;

typedef struct Tree_node{
    int data;
    Tree_node* left;
    Tree_node* right;
} Tree_node;

int getHeightBT(Tree_node*);
void createNode(Tree_node** currentNode, int data);
vector<int> inorderBT(Tree_node* currentNode);
vector<int> preorderBT(Tree_node* currentNode);
vector<int> postorderBT(Tree_node* currentNode);
vector<int> levelorderBT(Tree_node* currentNode);
Tree_node* createTreeFromInorderPreorder(vector<int> inOrderArr, vector<int> preOrderArr);

#endif