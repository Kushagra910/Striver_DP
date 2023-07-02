// 124. Binary Tree Maximum Path Sum

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

// here brute force was slighly complicated so we donot think about it and its TC would have been O(n^2)
// but instead this question is solved using previous concepts like maxDiameter,maxDepth,postOrderTraversal

// TC = O(n)
// SC = O(n)
class Solution {
public:
    int maxPath(TreeNode* node,int &maxi){
        if(node == nullptr) return 0;
        int lh = max(0,maxPath(node->left,maxi));
        int rh = max(0,maxPath(node->right,maxi));
        maxi = max(maxi,node->val+lh+rh);
        return node->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root,maxi);
        return maxi;
    }
};