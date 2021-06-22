#include<bits/stdc++.h>
using namespace std;

bool pairSum(int arr[], int n, int target)
{
    sort(arr, arr+n);
    int low = 0;
    int high = n-1;
    while (low < high)
    {
        if (arr[low] + arr[high] == target)
        {
           // cout<<low<<" "<<high;
            return true;
        }
        else if (arr[low] + arr[high] < target)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return false;
}

int main()
{
    int n, target;
    cin>>n>>target;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<pairSum( arr, n, target);
    return 0;
}