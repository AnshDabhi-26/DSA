#include <iostream>
using namespace std;

int main()
{
    int codes[] = {101, 202, 303, 404, 505, 606, 707, 808};
    int target = 505;

    int low = 0, high = 7;
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (codes[mid] == target)
        {
            result = mid;
            break;
        }
        else if (codes[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (result != -1)
    {
        cout << "Target code found at index: " << result << endl;
    }
    else
    {
        cout << "Target code not found." << endl;
    }

    return 0;
}