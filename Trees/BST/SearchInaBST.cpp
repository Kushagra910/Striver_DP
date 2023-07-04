// 700. Search in a Binary Search Tree

// You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

// search in a simple binary tree will have a TC of O(n) in worst case when the tree is degenerate ,can use any search pre,post,in,level and this is why BST was introduced
// TC = O(log n) base 2 
 class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != nullptr && root->val != val){
            root = (root->val<val) ? root->right: root->left;
        }
        return root;
    }
};
