#include <iostream>
#include <string>
using namespace std;
struct Node {
  string page;
  Node *next;
};
Node *topNode = NULL;
void printCurrent() {
  if (topNode == NULL) {
    cout << "No page history" << endl;
  } else {
    cout << "Current page: " << topNode->page << endl;
  }
}
void visit(string page) {
  Node *n = new Node();
  n->page = page;
  n->next = topNode;
  topNode = n;
  printCurrent();
}
void back() {
  if (topNode == NULL) {
    cout << "Cannot go back, no history left" << endl;
    return;
  }
  Node *temp = topNode;
  topNode = topNode->next;
  delete temp;
  printCurrent();
}
int main() {
  visit("google.com");
  visit("youtube.com");
  back();
  back();
  back();
  visit("github.com");
  return 0;
}