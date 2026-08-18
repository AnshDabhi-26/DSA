#include<iostream>
using namespace std;
int main()
{
    
    int items;
    cout<<"Enter the number of items: "<<endl;
    cin>>items;

    int a[items];

    cout<<"Enter items: "<<endl;

    for ( int i= 0; i < items; i++)
    {
    cin>>a[i];
    }
    
    int h;
    cout<<"Enter the number of hours: ";
    cin>>h;

    for (int k=0;k<h;k++)
    {
        int first = a[0];

         for (int i=0; i<items-1;i++)
        {
        a[i]=a[i+1];
        }
    
        a[items-1]=first;
        cout << "After hour " << k + 1 << ": ";
        for (int i = 0; i < items; i++)
        {
            cout << a[i] << " ";
        }
        
        cout << endl;
    }
    
    

}