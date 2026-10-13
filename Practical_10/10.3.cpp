#include <iostream>

using namespace std;

int main() {
    int slots[10];
    for (int i = 0; i < 10; i++) {
        slots[i] = -1;
    }

    int n;
    cout << "Enter number of student IDs: ";
    cin >> n;

    cout << "Enter student IDs:\n";
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;

        int hash1 = id % 10;
        int hash2 = 7 - (id % 7);
        
        int index = hash1;
        bool placed = false;

        for (int j = 0; j < 10; j++) {
            index = (hash1 + j * hash2) % 10;
            if (slots[index] == -1) {
                slots[index] = id;
                placed = true;
                break;
            }
        }

        if (placed == false) {
            cout << "Table is full or cannot place ID " << id << "\n";
        }
    }

    cout << "Final state of table:\n";
    for (int i = 0; i < 10; i++) {
        if (slots[i] != -1) {
            cout << "Slot " << i << ": " << slots[i] << "\n";
        } else {
            cout << "Slot " << i << ": Empty\n";
        }
    }

    return 0;
}
