#include <iostream>

using namespace std;

int main() {
    int slots[10];
    for(int i = 0; i < 10; i++) {
        slots[i] = -1;
    }

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter registration numbers:\n";
    for(int i = 0; i < n; i++) {
        int reg;
        cin >> reg;
        
        int index = reg % 10;
        int original = index;
        bool placed = false;

        while(slots[index] != -1) {
            index = (index + 1) % 10;
            if(index == original) {
                break;
            }
        }
        
        if(slots[index] == -1) {
            slots[index] = reg;
            placed = true;
        }

        if(placed == false) {
            cout << "Parking lot is full for vehicle " << reg << "\n";
        }
    }

    cout << "Final state of parking lot:\n";
    for(int i = 0; i < 10; i++) {
        if(slots[i] != -1) {
            cout << "Slot " << i << ": " << slots[i] << "\n";
        } else {
            cout << "Slot " << i << ": Empty\n";
        }
    }

    return 0;
}
