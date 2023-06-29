/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

// TC = O(n)  n=number of nodes
// SC = O(n) auxilliary stack space of the height of the tree, but at worst our tree can be a skew 
void preOrder(Node* root,vector<int>&ans){
    if(root == nullptr) return;
    ans.push_back(root->data);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
}

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
  // Your code here
  vector<int>ans;
  preOrder(root,ans);
  return ans;
}