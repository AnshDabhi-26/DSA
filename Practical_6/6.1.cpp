#include <iostream>
#include <string>
using namespace std;
int n = 5;
string arr[5];
int topIndex = -1;
void printTop() {
  if (topIndex == -1) {
    cout << "Counter is empty" << endl;
  } else {
    cout << "Top tray: " << arr[topIndex] << endl;
  }
}
void place(string tray) {
  if (topIndex == n - 1) {
    cout << "Error: Counter is full, cannot place " << tray << endl;
    return;
  }
  topIndex++;
  arr[topIndex] = tray;
  printTop();
}
void take() {
  if (topIndex == -1) {
    cout << "Error: Counter is empty, cannot take" << endl;
    return;
  }
  topIndex--;
  printTop();
}
int main() {
  place("Tray1");
  place("Tray2");
  take();
  take();
  take();
  place("Tray3");
  return 0;
}