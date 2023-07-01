// 104. Maximum Depth of Binary Tree

// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// My code
// TC = O(n);
// SC = O(n) auxiliary stack space;
class Solution {
    int maxi = INT_MIN;
    void dfs(TreeNode*node,int &cnt){
        if(node == nullptr){
            return;
        }
        if(node->left!= nullptr){
            cnt++;
            dfs(node->left,cnt);
            maxi = max(maxi,cnt);
            cnt--;
        }
        if(node->right!=nullptr){
            cnt++;
            dfs(node->right,cnt);
            maxi = max(maxi,cnt);
            cnt--;
        }
    }
public:
    int maxDepth(TreeNode* root) {
        int cnt  = 1;
        if(root == nullptr) return 0;
        else if(root->val >= 0 && root->left == nullptr && root->right == nullptr) return cnt; 
        dfs(root,cnt);
        return maxi;
    }
};


// Better code (striver's)

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node == nullptr) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        return 1 + max(lh,rh);
    }
};
