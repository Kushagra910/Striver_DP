#include <bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  Node* left;
  Node*right;
  Node(int val){
    this->val = val;
    left = nullptr;
    right = nullptr;
  }
};


void preOrder(Node* head){
  if(head == nullptr) return;
  cout << head->val << " ";
  preOrder(head->left);
  preOrder(head->right);
}

int main(){

  // Tree creation
  Node* myTree = new Node(1);
  myTree->left = new Node(2);
  myTree->right = new Node(3);
  myTree->left->left = new Node(4);
  myTree->left->right = new Node(5);
  myTree->right->left = new Node(6);
  myTree->right->right = new Node(7);

  cout << " Printing PreOrder Traversal Using DFS" << endl;
  preOrder(myTree);
  cout << endl;

  return 0;
}