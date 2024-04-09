#include <vector>
#include "ll.hh"
using namespace std;

#define TEST_1 0
#define TEST_2 0
#define TEST_3 1

//insert, sum, max, search display
void test_linked_list(vector<int> arr, int num) 
{
    Node *root = NULL;

#if TEST_1
    for(auto i: arr){
        root = insertNode(root, i);
    }
    
    displayNode(root);
    cout << "Number of nodes : " << countNodes(root) <<endl; 
    cout << "Sum of nodes : " << sumOfNodes(root) <<endl; 
    cout << "Max of nodes : " << findMax(root) <<endl;
    int index = searchElemnt(root, num);
    cout << "Search result for " << num << " : ";
    (index>=0) ? (cout << "Found At index " <<  index << endl) : cout << "Not found" << endl;
    cout<<"----------------------------------------------"<<endl;
#endif


#if TEST_2
    for(auto i: arr){
        root = insetAtBegin(root, i);
    }
    root = insertAt(root,4,1);
    root = insertAt(root,4,0);
    displayNode(root);
    cout << "Number of nodes : " << countNodes(root) <<endl; 
    cout<<"----------------------------------------------"<<endl;
#endif

#if TEST_3
    for(auto i: arr){
        root = insetAtBegin(root, i);
    }
    // root = insertAt(root,4,1);
    displayNode(root);
    cout << "Number of nodes : " << countNodes(root) <<endl; 
    root = deleteAtEnd(root);
    cout << "After deleteAtEnd: ";
    displayNode(root);
    cout << "Number of nodes : " << countNodes(root) <<endl;
    cout<<"----------------------------------------------"<<endl;

    while(root){
        root = deleteAtEnd(root);
    }
    cout << "Number of nodes after destroy: " << countNodes(root) <<endl;
    cout<<"----------------------------------------------"<<endl;
#endif

}

int main() {
    //No current element in the list at beginning
#if not TEST_3
     vector<vector<int>> arr = {
                                {1,2,3},
                                {2,3,1,5,10,9,6,7}, // normal
                                {33}, // 1 element
                                {} // no element
                              };
#else
    vector<vector<int>> arr = {
                                {1,2,3},
                                {2,3,1,5,10,9,6,7}, // normal
                                {33,44}, // 1 element
                                {} // no element
                              };
#endif
    for(auto i : arr){
        test_linked_list(i, 2);
    }

    return 0;
}