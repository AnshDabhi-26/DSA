#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n) {
   for (int i = 1; i < n; i++) {
       int key = arr[i];
       int j = i - 1;
       while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int marks1[] = {85, 72, 93, 64, 88};
    int marks2[] = {85, 72, 93, 64, 88};
    int marks3[] = {85, 72, 93, 64, 88};
    int n = 5;
    
    bubbleSort(marks1, n);
    selectionSort(marks2, n);
    //insertionSort(marks3, n);
    
    return 0;
}
