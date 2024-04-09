#include "ll.hh"

void
createNode(Node** currentNode, int data) {
    *currentNode = (Node*)malloc(sizeof(Node*));
    (*currentNode)->data = data;
}

Node*
insertNode(Node* currentNode, int data){

    //current node of concern is null
    //so this is the last position
    if(currentNode == NULL){
        createNode(&currentNode, data);
    }
    else{
        //current node is not null
        //begin the insertion from next node
        //if it is null
        currentNode->next = insertNode(currentNode->next, 
                                       data);
    }

    //retuen once created new node
    //in between recursion tree returns own node
    return currentNode;
}

void
displayNode(Node *currentNode){
    if(currentNode == NULL){
        cout << endl;
        return;
    }
    else {
        cout << currentNode->data << " ";
        displayNode(currentNode->next);
    }
}

int 
countNodes(Node *currentNode){
    int count = 0;
    
    //return when crossed the end of the list/ no element in list
    if (currentNode == NULL){
        return 0;
    } else {
        //Add own + rest of the lists count
        //rest of the list is represented by -> next
        count += 1 + countNodes(currentNode->next);
    }

    return count;
}

int 
sumOfNodes(Node *currentNode){
    int sum = 0;
    
    //return 0 when crossed the end of the list/ no element in list
    //return 1 in case of mutiply**
    if (currentNode == NULL){
        return 0;
    } else {
        //Add own + rest of the lists sum
        //rest of the list is represented by -> next
        sum += (currentNode->data) + sumOfNodes(currentNode->next);
    }

    return sum;
}

int
findMax(Node *currentNode){
    int max = INT_MIN;

    //return max as INT_MIN when rest of the list is empty
    //so we compare INT_MIN with the last element and traverse back
    //in recusrion call or return INT_MIN if there is no element
    if(currentNode == NULL){
        return max;
    } else {
        //find max from rest of the list
        //compare with own value with the rest max
        //last element will be the first nextMax and comparison will happen in backward recursive calls
        // 1,5,2   here 2 will be nextMax, then (5,2) 5 will be nextMax then (1,(5,2))=>(1,5)=>5 will be the max
        int nextMax = findMax(currentNode->next);
        max = (currentNode->data > nextMax) ? currentNode->data : nextMax;
    }
    return max;
}


//Iterative search space o(1) better than recursive
int
searchElemnt(Node *currentNode, int num, int dummy){
    int index = -1;
    while(currentNode){
        index++;
        if(currentNode->data == num){
            return index;
        }
        currentNode = currentNode->next;
    }
    return -1;
}


//Recursive search
/*int
searchElemnt(Node *currentNode, int num, int current_index){
    if(currentNode == NULL) {
        return -1;
    }
    if(currentNode->data == num){
        return current_index;
    }
    return searchElemnt(currentNode->next, num, current_index+1);
}*/

Node*
insetAtBegin(Node* currentNode, int data){
    return insertAt(currentNode, data, 0);
}

Node*
insertAt(Node* currentNode, int data, int index){
    int current_index = -1;
    //At begining prev is null
    Node* prev = NULL;
    Node *newNode = NULL;
    Node* temp = currentNode;

    //No node case
    if (currentNode == NULL && index == 0) {
        createNode(&newNode, data);
        newNode->data = data;
        return newNode;
    }

    while(temp){
        current_index++;
        //desired index reached create new node and assign current as its next (shift it)
        if(current_index==index){
            createNode(&newNode, data);
            newNode->next=temp;
            //if prev exists i.e not the beginning then asssig prev's next as the new node
            //if prev not exists then this is the new root at beginning
            prev ? prev->next = newNode : currentNode = newNode;
            break;
        }
        //index not reached continue to next index
        prev = temp;
        temp = temp->next;
    }

    //index never reached and new node never created
    if(newNode == NULL){
        cout << "Given index " << index << " not found to insert" << endl;
    }
    return currentNode;
}

Node* deleteAtEnd(Node* currentNode){
    Node* temp = currentNode;

    //List is empty
    if(currentNode==NULL){
        cout << "List empty" <<endl;
        return currentNode;
    }

    //iterate till 2nd last node
    while(temp->next && temp->next->next){
        temp=temp->next;
    }

    if(temp->next){
        temp->next = NULL;
        free(temp->next);
    }
    else{
        currentNode = NULL;
        free(currentNode);
    }

    return currentNode;
}