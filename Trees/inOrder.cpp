/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

// TC = O(n)  n=number of nodes
// SC = O(n) auxilliary stack space of the height of the tree, but at worst our tree can be a skew 

class Solution {
  public:
    void inOrder(Node* head,vector<int>&ans){
      if(head == nullptr){
        return;
      }
      inOrder(head->left,ans);
      ans.push_back(head->data);
      inOrder(head->right,ans);
    }



    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>ans;
        inOrder(root,ans);
        return ans;
    }
};