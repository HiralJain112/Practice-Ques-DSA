#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    int currSum[n+1];
    currSum[0] = 0;
    for(int i=1 ; i<=n ; i++)
    {
        currSum[i] = currSum[i-1] + arr[i-1];
    }
    int maxSum = INT_MIN;
    for (int i = 1; i <= n ; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = currSum[i] - currSum[j];
            maxSum = max( maxSum, sum);
        }
    }
    
    return maxSum;
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
    cout<<maxSubarraySum( arr, n);
    return 0;
}