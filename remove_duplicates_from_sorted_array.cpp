#include<bits/stdc++.h>
using namespace std;

int remove_duplicates(int arr[],int n)
{
    int temp = n;
    for (int i = n-1; i > 0; i--)
    {
        if (arr[i] == arr[i-1])
        {
            temp--;
            int j = i;
            while(j<n-1)
            {   arr[j] = arr[j+1];
                j++;
            }
            if (j==n-1)
            {
                n--;
            } 
        }
    }
    return temp;
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
    int ans = remove_duplicates(arr,n);
    cout<<ans<<endl;
    for (int i = 0; i < ans; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}