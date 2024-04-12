#include "bt.hh"
#include <vector>
#include <queue>

void 
createNode(Tree_node** currentNode, int data) { 
    *currentNode = (Tree_node*)calloc(1, sizeof(Tree_node));
    (*currentNode)->data = data;
    (*currentNode)->left = (*currentNode)->right = NULL;
}

int getHeightBT(Tree_node* currentNode)
{
    if(currentNode==NULL){
        return -1;
    } 
    return max(getHeightBT(currentNode->left),getHeightBT(currentNode->right))+1;
}

void inorder_recursive(Tree_node* currentNode, vector<int>& traversal){
    if(currentNode){
        inorder_recursive(currentNode->left, traversal);
        traversal.push_back(currentNode->data);
        inorder_recursive(currentNode->right, traversal);
    }
}

void preorder_recursive(Tree_node* currentNode, vector<int>& traversal){
    if(currentNode){
        traversal.push_back(currentNode->data);
        preorder_recursive(currentNode->left, traversal);
        preorder_recursive(currentNode->right, traversal);
    }
}
void postorder_recursive(Tree_node* currentNode, vector<int>& traversal){
    if(currentNode){
        postorder_recursive(currentNode->left, traversal);
        postorder_recursive(currentNode->right, traversal);
        traversal.push_back(currentNode->data);
    }
}

void levelorder_iter(Tree_node* currentNode, vector<int>& traversal){
    //create a queue
    queue<Tree_node*> levelq;
    Tree_node* temp;
    if(currentNode==NULL){
        return;
    }

    //push root to queue
    levelq.push(currentNode);
    while(!levelq.empty()){
        //get the element from queue
        temp = levelq.front();
        traversal.push_back(temp->data);

        //while printing a node keep its left, right childs in the queue
        if(temp->left)
            levelq.push(temp->left);
        if(temp->right)
            levelq.push(temp->right);
        levelq.pop();
    }
}

vector<int>
inorderBT(Tree_node* currentNode){
    vector<int> traversal;
    inorder_recursive(currentNode, traversal);
    return traversal;
}

vector<int>
preorderBT(Tree_node* currentNode){
    vector<int> traversal;
    preorder_recursive(currentNode, traversal);
    return traversal;
}

vector<int>
postorderBT(Tree_node* currentNode){
    vector<int> traversal;
    postorder_recursive(currentNode, traversal);
    return traversal;
}

vector<int>
levelorderBT(Tree_node* currentNode){
    vector<int> traversal;
    levelorder_iter(currentNode, traversal);
    return traversal;
}

Tree_node*
createTreeFromInorderPreorder_helper(vector<int> inOrderArr, vector<int> preOrderArr,
                                     int inOrderStart, int inOrderEnd,
                                     int preOrderStart, int preOrderEnd)
{
    //If start index is less than end index then the arr is empty
    if(inOrderStart>inOrderEnd) {
        return NULL;
    }

    //preOrderStart index is the index of root we are concerned in preorder arr
    Tree_node* root;
    createNode(&root, preOrderArr[preOrderStart]);

    /*
        |----------------------------------------|  |---|  |----------------------------------------|
        |               left                     |  | R |  |                right                   |
        |----------------------------------------|  |---|  |----------------------------------------|
    leftInOrderStart                  leftInOrderEnd       rightInOrderStart                rightInOrderEnd
    inOrderStart                      rootIndex - 1        rootIndex + 1                    inOrderend
    */

    //Left inorder starting index is nothing but actual inorder starting index
    int leftInOrderStart = inOrderStart;
    //Roght inorder ending index is nothing but actual inorder ending index
    int rightInOrderEnd = inOrderEnd;

    //find the root index
    int rootIndex = -1;
    for(int i = inOrderStart; i<=inOrderEnd; i++)
    {
        if(inOrderArr[i]==preOrderArr[preOrderStart]){
            rootIndex = i;
            break;
        }
    }

    int leftInOrderEnd = rootIndex - 1;
    int rightInOrderStart = rootIndex + 1;

    /*
        |---|  |----------------------------------------|  |----------------------------------------|
        | R |  |                left                    |  |                right                   |
        |---|  |----------------------------------------|  |----------------------------------------|
              leftPreOrderStart                                                             rightPreOrderEnd
              preOrderStart + 1                                                             preOrderEnd
    */

    int leftPreOrderStart = preOrderStart + 1;
    int rightPreOrderEnd = preOrderEnd;

    // [leftPreOrderStart - leftPreOrderEnd = leftInOrderStart - leftInOrderEnd] => number of nodes in the traversal is same
    int leftPreOrderEnd = leftPreOrderStart - leftInOrderStart + leftInOrderEnd;

    // [rightPreOrderStart - rightPreOrderEnd = rightInOrderStart - rightInOrderEnd] => number of nodes in the traversal is same
    int rightPreOrderStart = rightInOrderStart - rightInOrderEnd + rightPreOrderEnd;

    root->left = createTreeFromInorderPreorder_helper(inOrderArr, preOrderArr, leftInOrderStart, leftInOrderEnd, leftPreOrderStart, leftPreOrderEnd);
    root->right = createTreeFromInorderPreorder_helper(inOrderArr, preOrderArr, rightInOrderStart, rightInOrderEnd, rightPreOrderStart, rightPreOrderEnd);
    return root;
}

Tree_node*
createTreeFromInorderPreorder(vector<int> inOrderArr, vector<int> preOrderArr)
{
    //we have to perform the recursion based on left and right subtree
    return createTreeFromInorderPreorder_helper(inOrderArr, preOrderArr, 0, inOrderArr.size()-1, 0, preOrderArr.size()-1);
}