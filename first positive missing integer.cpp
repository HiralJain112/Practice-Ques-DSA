#include<bits/stdc++.h>
using namespace std;

int first_pos_missing(int arr[], int n)
{
    const int N = 1e6 +2;
    bool check[N];
    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        check[arr[i]] = true;
    }
    
    for (int i = 1; i < N; i++)
    {
        if (!check[i])
        {
            return i;
            break;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<first_pos_missing(arr,n);
    return 0;
}