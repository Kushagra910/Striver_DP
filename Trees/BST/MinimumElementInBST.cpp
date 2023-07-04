// Minimum element in BST
// Given a Binary Search Tree. The task is to find the minimum valued element in this given BST.

// TC = O(log n)
int minValue(Node* root) {
    // Code here
    if(root == nullptr) return -1;
    while(root->left!=nullptr){
        root = root->left;
    }
    return root->data;
}