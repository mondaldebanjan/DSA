#include "bst.hh"
#include <vector>

#define TEST_1 0
#define TEST_2 0
#define TEST_3 1

void test_bst(vector<int> arr) {
    Tree_node* root = NULL;

    for(auto i:arr){
        root = iter_insert(root, i);
    }

    printBT(root);
#if TEST_1
    cout << "Height is : " << getHeightBT(root) <<endl;
    /*search(root, 55) ? (cout << "55 Found" << endl) : (cout << "55 Not Found" << endl);
    search(root, 3);
    search(root, 3) ? (cout << "3 Found" << endl) : (cout << "3 Not Found" << endl);
    search(root, 2);
    search(root, 2) ? (cout << "2 Found" << endl) : (cout << "2 Not Found" << endl);*/
    root = deleteNode(root, 7);
    printBT(root);
    cout << "Height is : " << getHeightBT(root) <<endl;
    root = deleteNode(root, 6);
    printBT(root);
    cout << "Height is : " << getHeightBT(root) <<endl;
    root = deleteNode(root, 5);
    printBT(root);
    cout << "Height is : " << getHeightBT(root) <<endl;
    root = deleteNode(root, 4);
    printBT(root);
    cout << "Height is : " << getHeightBT(root) <<endl;
    root = deleteNode(root, 3);
    printBT(root);
    cout << "Height is : " << getHeightBT(root) <<endl;
#endif

#if TEST_2
    cout << "Inorder traversal : "; for(auto arr: inorderBT(root)) cout << arr <<" "; cout << endl;
    cout << "Preorder traversal : "; for(auto arr: preorderBT(root)) cout << arr <<" "; cout << endl;
    cout << "Postorder traversal : "; for(auto arr: postorderBT(root)) cout << arr <<" "; cout << endl;
    cout << "Levelorder traversal : "; for(auto arr: levelorderBT(root)) cout << arr <<" "; cout << endl;
    cout << "-----------------------------------------------------------------------" <<endl;
#endif
}

int main()
{

#if not TEST_3
    vector<vector<int>> arr = {
        {2,4,55,6,23,22,5,24,1},
         {1,2,3,4,5},
          {3},
          {},
        {20, 40, 35, 38, 36, 37},
        {55, 7, 5, 25, 4, 6, 3 ,2, 1, 22, 23, 26}
    };

    for(auto i:arr)
    {
        test_bst(i);
    }
#endif

#if TEST_3
    vector<int> inorderArr = {3, 1, 4, 0, 5, 2};
    vector<int> preorderArr = {0, 1, 3, 4, 2, 5};
    Tree_node* root = createTreeFromInorderPreorder(inorderArr, preorderArr);
    printBT(root);
#endif

    return 0;
}