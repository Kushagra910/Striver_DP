// Ceil in BST

// Given a BST and a number X, find Ceil of X.
// Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

// Function to return the ceil of given number in BST.
// TC = O(log n) base 2
int findCeil(Node* root, int input) {

    // Your code here
    int ceil = -1;
    while(root!=nullptr){
        if(root->data ==  input){
            ceil = root->data;
            return ceil;
        }
        if(root->data < input){
            root = root->right;
        }
        else {
            ceil = root->data;
            root = root -> left;
        }
    }
    return ceil;
}