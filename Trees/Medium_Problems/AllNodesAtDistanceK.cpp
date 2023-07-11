// 863. All Nodes Distance K in Binary Tree

// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
// You can return the answer in any order.

//Binary trees are pointed in downwards fashion but here we require to go to parents

// So simple 3 process are done 
// 1 - Create Parent Pointers using BFS and stored in an unorderd map
// 2 - BFS for target as source node and take a variable distance which keeps on increasing untill K is reached and break
// 3 - Remaining element in Queue DS is required answer

// TC = O(n) + O(n) + O(log n)    first traversing to make parent pointer , next traversing all the nodes that are at a distance K (worst case full traversal) + hashmap->logn
// SC = O(n) overall 
class Solution {
private:
    void mark_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            if(current->left != nullptr){
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right != nullptr){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        mark_parent(root,parent_track);
        vector<int>ans;
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;
        int distance = 0;
        while(!q.empty()){
            int sz = q.size();
            if(distance == k) break;
            distance ++;
            for(int i=0;i<sz;i++){
                auto curr = q.front();
                q.pop();
                if(curr->left != nullptr and vis[curr->left] == false){
                    q.push(curr->left);
                    vis[curr->left] = true; 
                }
                if(curr->right != nullptr and vis[curr->right] == false){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent_track[curr]!=nullptr and !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]]  = true;
                }
            }
        }
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};