#include <iostream>
using namespace std;

struct Node {
  int code;
  Node* left;
  Node* right;
};

Node* createNode(int code) {
  Node* newNode = new Node();
  newNode->code = code;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* insert(Node* root, int code) {
  if (root == NULL) {
    return createNode(code);
  }
  
  if (code < root->code) {
    root->left = insert(root->left, code);
  } else if (code > root->code) {
    root->right = insert(root->right, code);
  }
  
  return root;
}

void inorder(Node* root) {
  if (root == NULL) return;
  inorder(root->left);
  cout << root->code << " ";
  inorder(root->right);
}

int main() {
  Node* root = NULL;
  
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
  
  cout << "Inorder Sequence of Book Codes: ";
  inorder(root);
  cout << endl;
  
  return 0;
}
