// Level order traversal in spiral form

// Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.


//Function to return a list containing the level order traversal in spiral form.
// TC = O(n)
// SC = O(n)
vector<int> findSpiral(Node *root)
{
    //Your code here
    if(root == nullptr) return vector<int>();
    vector<vector<int>>res;
    queue<Node*>q;
    q.push(root);
 
    while(!q.empty()){
        vector<int>temp;
        int sz = q.size();
        for(int i=0;i<sz;i++){
            Node* node = q.front();
            q.pop();
             if(node->left!=nullptr){
             q.push(node->left);
             }
             if(node->right!=nullptr){
                 q.push(node->right);
             }
             temp.push_back(node->data);
        }
        res.push_back(temp);
    }
    for(int i=0;i<res.size();i++){
        if((i&1) == 0){
            reverse(res[i].begin(),res[i].end());
        }
    }
    vector<int>ans;
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            ans.push_back(res[i][j]);
        }
    }
    return ans;
}

