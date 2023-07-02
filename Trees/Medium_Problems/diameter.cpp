// 543. Diameter of Binary Tree

// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

// Brute Force 
// TC = O(n^2)
// SC = O(n)

class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1+max(lh,rh);
    }
    int maxi = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        maxi = max(maxi,lh+rh);
        int maxleft = diameterOfBinaryTree(root->left);
        int maxright = diameterOfBinaryTree(root->right);
        return maxi;
    }
};

// Optimsation -> should know how to calculate depth of BT
// TC = O(n)
// SC = O(n)

class Solution {
public:
    int height(TreeNode* node,int &ans){
        if(node == nullptr){
            return 0;
        }
        int lh = height(node->left,ans);
        int rh = height(node->right,ans);
        ans = max(ans,lh+rh);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root,ans);
        return ans;
    }
};