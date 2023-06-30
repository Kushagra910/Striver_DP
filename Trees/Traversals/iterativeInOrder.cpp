
// Iterative Inorder traversal
// TC = O(n)
// SC = O(n)
class Solution {
  public:
  
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>ans;
        stack<Node*>st;
        Node* node = root;
        while(true){
            if(node!=nullptr){
                st.push(node);
                node = node -> left;
            }
            else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                ans.push_back(node->data);
                node = node -> right;
            }
        }
        return ans;
    }
};