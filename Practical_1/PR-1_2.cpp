#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[n];

    cout<<"Enter number of borrowed books: "<<endl;
    cin >> n;

    cout<<"Enter IDs of books: "<<endl;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    for(int k = 0; k < n; k++)
    {
        int count = 0;

        for(int j = k+1; j < n; j++)
        {
            if(a[k] == a[j])
            {
                count++;
                a[j]=-1;

            }
        }

        if(count > 0 && a[k]!=-1)
        {
            cout << a[k] << " ID no Book is Borrowed "<< count+1 << " times" <<endl;
        }
    }

    return 0;
}