// Iterative postorder traversal
// TC = O(2*n)
// SC =O(n)

vector <int> postOrder(Node* root)
{
  // Your code here
    vector<int>ans;
    if(root == nullptr) return ans;
    stack<Node*>st;
    while(root != nullptr || !st.empty()){
        if(root != nullptr){
            st.push(root);
            root = root->left;
        }
        else{
            Node*temp = st.top()->right;
            if(temp == nullptr){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else{
                root = temp;
            }
        }
    }
    return ans;
}
