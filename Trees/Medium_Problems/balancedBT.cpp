// Check for Balanced Tree

// Given a binary tree, find if it is height balanced or not. 
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

// Brute Force
// TC = O(n^2) because we are calculating height for every node of the tree and height function itself takes O(n) time
/// to calculate height
// SC = O(n)

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int height(Node* node){
        if(node == nullptr) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        return 1 + max(lh,rh);
    }

    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root == nullptr) return true;
        int lh = 0;
        int rh = 0;
        if(root->left!=nullptr){
             lh = height(root->left);  
        }
        if(root->right!=nullptr){
             rh = height(root->right);
        }
        
        if(abs(lh-rh)>1) return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left || !right) return false;
        return true;
    }
};

// Optimised 
// TC = O(n)
// SC = O(n)
// just Optimised the maxDepth of binary tree code
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int height(Node* node){
        if(node == nullptr) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        if(lh == -1 || rh == -1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1 + max(lh,rh);
    }

    bool isBalanced(Node *root)
    {
        //  Your Code here
        return (height(root)!=-1) ? true : false;
    }
};