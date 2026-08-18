#include <iostream>
using namespace std;
int iterativeSearch(string arr[], int n, string target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}


int recursiveSearch(string arr[], int n, string target, int index)
{
    if (index == n)
        return -1;

    if (arr[index] == target)
        return index;

    return recursiveSearch(arr, n, target, index + 1);
}

int main()
{
    int n;

    cout << "Enter number of vehicles: ";
    cin >> n;

    string plates[100];

    cout << "Enter license plates:";
    for (int i = 0; i < n; i++)
    {
        cin >> plates[i];
    }

    string target;

    cout << "Enter target license plate: ";
    cin >> target;

   
    int pos1 = iterativeSearch(plates, n, target);

    if (pos1 != -1)
        cout << "Iterative Search: Found at position " << pos1 + 1 << endl;
    else
        cout << "Iterative Search: Not Found" << endl;

    int pos2 = recursiveSearch(plates, n, target, 0);

    if (pos2 != -1)
        cout << "Recursive Search: Found at position " << pos2 + 1 << endl;
    else
        cout << "Recursive Search: Not Found" << endl;

    return 0;
}
