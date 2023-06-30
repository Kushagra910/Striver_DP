// Iterative Postorder Traversal using 2 stacks

// TC = O(n)
// SC = O(2*n)

vector <int> postOrder(Node* root)
{
  // Your code here
    vector<int>ans;
    if(root == nullptr) return ans;
    stack<Node*>st1,st2;
    st1.push(root);
    while(!st1.empty()){
        Node* node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left!=nullptr){
            st1.push(node->left);
        }
        if(node->right!=nullptr){
            st1.push(node->right);
        }
    }
    
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}