#include "bst.hh"
#include <iomanip>

void printBT(const std::string& prefix,Tree_node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        // print the value of the node
        std::cout << node->data << std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

void printBT(Tree_node* node)
{
    printBT("", node, false);
}

Tree_node*
insert(Tree_node* currentNode, int data) {
    // reached leaf/ root is null
    if (currentNode == NULL) {
        createNode(&currentNode, data);
    } else {
        //go till end of the left/right subtree
        //based on the data, create the node as new left/right leaf (above if)
        //roll back recursively returning own node to prevously called parent
        //parent->left/right = insert(nullleft/nullright,data)
        if(data < currentNode->data) {
            currentNode->left = insert(currentNode->left, data);
        } else {
            currentNode->right = insert(currentNode->right, data);
        }
    }

    return currentNode;
}

Tree_node*
iter_insert(Tree_node* currentNode, int data) {
    
    Tree_node* temp = currentNode;
    if(currentNode == NULL){
        createNode(&currentNode, data);
    }
    while(temp){
        if(data < temp->data){
            if(temp->left)
                temp=temp->left;
            else {
                createNode(&(temp->left), data);
                break;
            }
        } else {
            if(temp->right)
                temp=temp->right;
            else {
                createNode(&(temp->right), data);
                break;
            }
        }
    }
    
    return currentNode;
}

bool search(Tree_node* currentNode, int data){
    Tree_node* temp = currentNode;

    while (temp) {
        if(data == temp->data){
            return true;
        } else {
            if(data < temp->data)
                temp=temp->left;
            else
                temp=temp->right;
        }
    }

    return false;
}

Tree_node*
FindMin(Tree_node* currentNode){
    Tree_node* temp = currentNode;

    while(temp->left){
        temp=temp->left;
    }
    return temp;
}

Tree_node*
FindMax(Tree_node* currentNode){
    Tree_node* temp = currentNode;

    while(temp->right){
        temp=temp->right;
    }
    return temp;
}


Tree_node*
deleteNode(Tree_node* currentNode, int data)
{
    //if currentNode is null return null
    if(currentNode == NULL){
        return NULL;
    }else{
        //if data < currentNode delete from left subtree
        //if data > currentNode delete from right subtree
        //if data matches then perform delte operation
        if(data < currentNode->data){
            currentNode->left = deleteNode(currentNode->left, data);
        } else if (data > currentNode->data){
            currentNode->right = deleteNode(currentNode->right, data);
        } else {
            //Perform delete
            //currentNode has 0 elements i.e it is a leaf
            if(currentNode->left==NULL && currentNode->right==NULL){
                free(currentNode);
                currentNode = NULL;
            } else{
                Tree_node* temp = NULL;
                if(currentNode->right == NULL){
                    //current node has left child only assign left child as current node
                    // old current node store as temp and free
                    temp =  currentNode;
                    currentNode = currentNode->left;
                    free(temp);
                    temp = NULL; 
                } else if(currentNode->left == NULL){
                    //current node has right child only assign right child as current node
                    // old current node store as temp and free
                    temp =  currentNode;
                    currentNode = currentNode->right;
                    free(temp);
                    temp = NULL;
                } else {
                    //current node has both the childs
                    //find min of right or max of left subtree based on height and delete
                    if(getHeightBT(currentNode->right) > getHeightBT(currentNode->left)){
                        temp = FindMin(currentNode->right);

                        //asign that found node's data to current node
                        // delte thet found node from the subtree recusrsively (trust!!!!)
                        currentNode->data = temp->data;
                        currentNode->right = deleteNode(currentNode->right, temp->data);
                    } else {
                        temp = FindMax(currentNode->left);

                        //asign that found node's data to current node
                        // delte thet found node from the subtree recusrsively (trust!!!!)
                        currentNode->data = temp->data;
                        currentNode->left = deleteNode(currentNode->left, temp->data);
                    }
                }
            }
        }
    }
    return currentNode;
}
