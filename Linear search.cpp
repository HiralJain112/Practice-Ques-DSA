#include<bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[],int n, int key)
{
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<LinearSearch(arr, n, key);
    return 0;
}