// Iterative Preorder Traversal using stack DS

//Function to return a list containing the preorder traversal of the tree.
// TC = O(n)
// SC = O(n)
vector <int> preorder(Node* root)
{
  // Your code here
  vector<int>ans;
  if(root == nullptr) return ans;
  stack<Node*>st;
  st.push(root);
  while(!st.empty()){
      Node* node = st.top();
      st.pop();
      ans.push_back(node->data);
      if(node->right!=nullptr){
          st.push(node->right);
      }
      if(node->left!=nullptr){
          st.push(node->left);
      }
  }
  return ans;
}