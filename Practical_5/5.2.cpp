#include <iostream>
#include <string>
using namespace std;
struct SNode {
    string name;
    SNode* next;
};
SNode* shead = NULL;
void sdisplay() {
    if (shead == NULL) {
        cout << "Empty" << endl;
        return;
    }
    SNode* temp = shead;
    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != shead);
    cout << endl;
}
void sjoin(string name, string after) {
    SNode* n = new SNode();
    n->name = name;
    if (shead == NULL) {
        n->next = n;
        shead = n;
        sdisplay();
        return;
    }
    SNode* temp = shead;
    while (temp->name != after && temp->next != shead) {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    sdisplay();
}
void sleave(string name) {
    if (shead == NULL) return;
    if (shead->next == shead && shead->name == name) {
        delete shead;
        shead = NULL;
        sdisplay();
        return;
    }
    SNode* temp = shead;
    SNode* prev = NULL;
    while (temp->next != shead && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->name == name) {
        if (temp == shead) {
            SNode* last = shead;
            while (last->next != shead) {
                last = last->next;
            }
            shead = temp->next;
            last->next = shead;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
    sdisplay();
}
struct DNode {
    string name;
    DNode* prev;
    DNode* next;
};
DNode* dhead = NULL;
void ddisplay() {
    if (dhead == NULL) {
        cout << "Empty" << endl;
        return;
    }
    DNode* temp = dhead;
    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != dhead);
    cout << endl;
}
void djoin(string name, string after) {
    DNode* n = new DNode();
    n->name = name;
    if (dhead == NULL) {
        n->next = n;
        n->prev = n;
        dhead = n;
        ddisplay();
        return;
    }
    DNode* temp = dhead;
    while (temp->name != after && temp->next != dhead) {
        temp = temp->next;
    }
    n->next = temp->next;
    n->prev = temp;
    temp->next->prev = n;
    temp->next = n;
    ddisplay();
}
void dleave(string name) {
    if (dhead == NULL) return;
    if (dhead->next == dhead && dhead->name == name) {
        delete dhead;
        dhead = NULL;
        ddisplay();
        return;
    }
    DNode* temp = dhead;
    while (temp->next != dhead && temp->name != name) {
        temp = temp->next;
    }
    if (temp->name == name) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == dhead) {
            dhead = temp->next;
        }
        delete temp;
    }
    ddisplay();
}
int main() {
    cout << "Singly Circular:" << endl;
    sjoin("A", "");
    sjoin("B", "A");
    sjoin("C", "B");
    sleave("B");
    cout << "Doubly Circular:" << endl;
    djoin("A", "");
    djoin("B", "A");
    djoin("C", "B");
    dleave("A");
    return 0;
}