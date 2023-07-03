//100. Same Tree

//Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 // Can do any traversal 
 // so using preorder Traversal

 // TC = O(n)
 // SC = O(n)

 class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q==nullptr) return (p == q);
        return ((p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};