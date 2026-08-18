#include <iostream>
using namespace std;

int main()
{
    string plates[] = {"GJ01AB1111", "GJ02CD2222", "GJ03EF3333", "GJ04GH4444"};
    int n = 4;
    string target = "GJ03EF3333";

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (plates[i] == target)
        {
            result = i + 1;
            break;
        }
    }

    if (result != 0)
    {
        cout << "Target plate found at position : " << result << endl;
    }
    else
    {
        cout << "Target plate not found." << endl;
    }

    return 0;
}