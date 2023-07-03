// 103. Binary Tree Zigzag Level Order Traversal

// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
//  (i.e., from left to right, then right to left for the next level and alternate between).

//TC =O(n)
// SC = O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        bool leftToright=true;
        queue<TreeNode*>nodesqueue;
        nodesqueue.push(root);
        while(!nodesqueue.empty()){
            int size=nodesqueue.size();
            vector<int>level(size);
            for(int i=0;i<size;i++){
                TreeNode* node=nodesqueue.front();
                nodesqueue.pop();
                int index=(leftToright) ? i :(size-1-i);
                level[index]=node->val;
                if(node->left){
                    nodesqueue.push(node->left);
                }
                if(node->right){
                    nodesqueue.push(node->right);
                }
            }
            leftToright=!leftToright;
            result.push_back(level);
        }
        return result;
    }
};
