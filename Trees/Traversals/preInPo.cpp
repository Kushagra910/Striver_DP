#include <bits/stdc++.h>
using namespace std;

// intialising the Tree
struct Node{
  int val;
  Node* left;
  Node* right;
  Node(int val){
    this->val = val;
    left = right = nullptr;
  }
};

// function that prints preorder,inorder&postorder in one traversal
// TC = O(3*n)
// SC = O(4*n)
void preInPo(Node* root){
  stack<pair<Node*,int>>st;             // here stack is storing node,num
  vector<int>pre,in,post;   
  if(root == nullptr) return;            
  st.push({root,1});                  
  while(!st.empty()){
    auto it = st.top();
    st.pop();
    if(it.second == 1){                 // if num == 1 then add in preorder 
       pre.push_back(it.first->val);
       it.second ++;                    // increment the num
       st.push(it);
       if(it.first->left!=nullptr){      // check for left
        st.push({it.first->left,1});
       }
    }
    else if(it.second == 2){           // if num == 2 then add in inorder
        in.push_back(it.first->val);
        it.second++;                   // increment the num
        st.push(it);
        if(it.first->right!=nullptr){     // check for right
          st.push({it.first->right,1});
        }
    }
    else{                              //if num == 3 add in postorder
        post.push_back(it.first->val);
    }
  }

  cout << "printing preorder traversal" <<endl;
  for(auto it:pre){
    cout << it << " ";
  }
  cout << endl;

  cout << "printing inorder traversal" <<endl;
  for(auto it:in){
    cout << it << " ";
  }
  cout << endl;

    cout << "printing postorder traversal" <<endl;
  for(auto it:post){
    cout << it << " ";
  }
  cout << endl;

}

// creating my tree object
int main(){
  Node* myTree = new Node(1);
  myTree->left = new Node(2);
  myTree->right = new Node(3);
  myTree->left->left = new Node(4);
  myTree->left->right = new Node(5);
  myTree->right->left = new Node(6);
  myTree->right->right = new Node(7);
  preInPo(myTree);
  return 0;
}