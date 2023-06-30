 /// PostOrder Traversal
 // TC = O(n)
 // SC = O(n)
 

  void postOrder(Node* head,vector<int>&ans){
      if(head == nullptr){
        return;
      }
      postOrder(head->left,ans);
      postOrder(head->right,ans);
      ans.push_back(head->data);
    }

vector <int> postOrder(Node* root)
{
  // Your code here
        vector<int>ans;
        postOrder(root,ans);
        return ans;
}