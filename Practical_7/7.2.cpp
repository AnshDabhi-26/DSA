t#include <iostream>
#include <string>
using namespace std;

struct Node {
  string patientName;
  Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void arrive(string name) {
  Node *newNode = new Node();
  newNode->patientName = name;
  newNode->next = NULL;
  
  if (front == NULL) {
    front = newNode;
    rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
  cout << "Current front patient: " << front->patientName << endl;
}

void attend() {
  if (front == NULL) {
    cout << "Error: No patients waiting." << endl;
    return;
  }
  
  Node *temp = front;
  front = front->next;
  
  if (front == NULL) {
    rear = NULL;
  }
  
  delete temp;
  
  if (front != NULL) {
    cout << "Current front patient: " << front->patientName << endl;
  } else {
    cout << "No more patients waiting." << endl;
  }
}

int main() {
  arrive("John");
  arrive("Alice");
  
  attend();
  
  arrive("Bob");
  
  attend();
  attend();
  
  attend();
  
  return 0;
}
