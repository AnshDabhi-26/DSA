#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void countSongs() {
    int c = 0;
    Node* temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    cout << "Count: " << c << endl;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->song << " ";
        temp = temp->next;
    }
    cout << endl;
}

void addBeginning(string s) {
    Node* n = new Node();
    n->song = s;
    n->prev = NULL;
    n->next = head;
    if (head != NULL) {
        head->prev = n;
    }
    head = n;
    if (tail == NULL) {
        tail = n;
    }
    display();
}

void addEnd(string s) {
    Node* n = new Node();
    n->song = s;
    n->next = NULL;
    n->prev = tail;
    if (tail != NULL) {
        tail->next = n;
    }
    tail = n;
    if (head == NULL) {
        head = n;
    }
    display();
}

void insertAfter(string target, string s) {
    Node* temp = head;
    while (temp != NULL && temp->song != target) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node* n = new Node();
        n->song = s;
        n->prev = temp;
        n->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = n;
        } else {
            tail = n;
        }
        temp->next = n;
    }
    display();
}

void removeFirst() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }
    display();
}

int main() {
    addBeginning("Song1");
    addEnd("Song2");
    insertAfter("Song1", "Song1.5");
    countSongs();
    removeFirst();
    return 0;
}
