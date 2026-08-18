#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, key;

    cout << "Enter number of book codes: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted book codes:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target book code: ";
    cin >> key;

    int result = binarySearchIterative(arr, n, key);

    if (result != -1)
        cout << "Book code found at position: " << result + 1;
    else
        cout << "Book code not found.";

    return 0;
}
