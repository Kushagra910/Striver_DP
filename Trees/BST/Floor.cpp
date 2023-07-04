// Floor in BST

// You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
// Note: when x is smaller than the smallest node of BST then returns -1.

// Function to search a node in BST.
// TC = O(log n) base 2;
int floor(Node* root, int x) {
    // Code here
    int floor = -1;
    while(root != nullptr){
        if(root->data == x){
            floor = root -> data;
            return floor;
        }
        if(root->data < x){
            floor = root->data;
            root = root -> right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
}