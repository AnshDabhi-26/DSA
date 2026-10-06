#include <iostream>
using namespace std;

int n = 5;
int arr[5];
int front = -1;
int rear = -1;
int current_size = 0;

void join(int token) {
  if (current_size == n) {
    cout << "Error: Counter is full, cannot issue token." << endl;
    return;
  }
  
  if (front == -1) {
    front = 0;
    rear = 0;
  } else {
    rear = (rear + 1) % n;
  }
  
  arr[rear] = token;
  current_size++;
  cout << "Current front token: " << arr[front] << endl;
}

void serve() {
  if (current_size == 0) {
    cout << "Error: Counter is empty, no one to serve." << endl;
    return;
  }
  
  if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    front = (front + 1) % n;
  }
  
  current_size--;
  
  if (current_size > 0) {
    cout << "Current front token: " << arr[front] << endl;
  } else {
    cout << "Counter is now empty" << endl;
  }
}

int main() {
  join(101);
  join(102);
  join(103);
  
  serve();
  
  join(104);
  join(105);
  join(106);
  
  join(107);
  
  serve();
  serve();
  
  return 0;
}
