#include <iostream>
#include <string>
using namespace std;

struct Node {
  string name;
  Node* left;
  Node* right;
};

Node* createNode(string name) {
  Node* newNode = new Node();
  newNode->name = name;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void inorder(Node* root) {
  if (root == NULL) return;
  inorder(root->left);
  cout << root->name << " ";
  inorder(root->right);
}

void preorder(Node* root) {
  if (root == NULL) return;
  cout << root->name << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node* root) {
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->name << " ";
}

void levelOrder(Node* root) {
  if (root == NULL) return;
  
  Node* queue[100];
  int front = 0;
  int rear = 0;
  
  queue[rear] = root;
  rear++;
  
  while (front < rear) {
    Node* current = queue[front];
    front++;
    
    cout << current->name << " ";
    
    if (current->left != NULL) {
      queue[rear] = current->left;
      rear++;
    }
    if (current->right != NULL) {
      queue[rear] = current->right;
      rear++;
    }
  }
}

int main() {
  Node* root = createNode("CEO");
  root->left = createNode("Manager1");
  root->right = createNode("Manager2");
  root->left->left = createNode("Emp1");
  root->left->right = createNode("Emp2");
  root->right->left = createNode("Emp3");
  root->right->right = createNode("Emp4");

  cout << "Inorder (HR): ";
  inorder(root);
  cout << endl;

  cout << "Preorder (Archive): ";
  preorder(root);
  cout << endl;

  cout << "Postorder (Payroll): ";
  postorder(root);
  cout << endl;

  cout << "Level Order (Floor Manager): ";
  levelOrder(root);
  cout << endl;

  return 0;
}
