#include <iostream>

using namespace std;

struct Node {
    int book_code;
    Node* next;
};

int main() {
    Node* shelves[10];
    for (int i = 0; i < 10; i++) {
        shelves[i] = NULL;
    }

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes:\n";
    for (int i = 0; i < n; i++) {
        int code;
        cin >> code;

        int shelf = code % 10;
        
        Node* newNode = new Node;
        newNode->book_code = code;
        newNode->next = NULL;

        if (shelves[shelf] == NULL) {
            shelves[shelf] = newNode;
        } else {
            Node* temp = shelves[shelf];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    cout << "Final contents of all shelves:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";
        Node* temp = shelves[i];
        if (temp == NULL) {
            cout << "Empty";
        }
        while (temp != NULL) {
            cout << temp->book_code << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    return 0;
}
