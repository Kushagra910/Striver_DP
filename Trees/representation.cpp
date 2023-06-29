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

void inOrder(Node* head){
  if(head == nullptr){
    return;
  }
  inOrder(head->left);
  cout << head->val << " ";
  inOrder(head->right);
}


void postOrder(Node* head){
  if(head == nullptr) return;
  postOrder(head->left);
  postOrder(head->right);
  cout << head->val << " ";
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

  cout << " Printing InOrder Traversal Using DFS" << endl;
  inOrder(myTree);
  cout << endl;

  cout << " Printing PostOrder Traversal using DFS" << endl;
  postOrder(myTree);
  return 0;
}