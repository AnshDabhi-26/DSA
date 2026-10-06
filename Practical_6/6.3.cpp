#include <iostream>
#include <string>
using namespace std;
char arr[100];
int topIndex = -1;
void push(char c) {
  topIndex++;
  arr[topIndex] = c;
}
char pop() {
  char c = arr[topIndex];
  topIndex--;
  return c;
}
int getPriority(char c) {
  if (c == '^') {
    return 3;
  } else if (c == '*' || c == '/') {
    return 2;
  } else if (c == '+' || c == '-') {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  string infix = "(3+4)*2";
  string postfix = "";
  for (int i = 0; i < infix.length(); i++) {
    char c = infix[i];
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
      postfix = postfix + c;
    } else if (c == '(') {
      push(c);
    } else if (c == ')') {
      while (topIndex != -1 && arr[topIndex] != '(') {
        postfix = postfix + pop();
      }
      if (topIndex != -1 && arr[topIndex] == '(') {
        pop();
      }
    } else {
      while (topIndex != -1 && getPriority(arr[topIndex]) >= getPriority(c)) {
        postfix = postfix + pop();
      }
      push(c);
    }
  }
  while (topIndex != -1) {
    postfix = postfix + pop();
  }
  cout << postfix << endl;
  return 0;
}