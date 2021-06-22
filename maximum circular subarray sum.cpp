#include<bits/stdc++.h>
using namespace std;

int maxSumKadane(int arr[], int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int maxCirSum(int arr[], int n)
{
    int wrapSum ;
    int nonWrapSum = maxSumKadane(arr, n);

    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
        arr[i] = -arr[i];
    }
    wrapSum = totalSum + maxSumKadane(arr, n);// -- becomes +
    
    return max(wrapSum, nonWrapSum);    
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
    cout<<maxCirSum( arr, n);
    return 0;
}