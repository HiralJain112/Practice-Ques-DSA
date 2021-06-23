#include<bits/stdc++.h>
using namespace std;

pair<int ,int> max_min(int arr[], int n)
{
    int maxNo = INT_MIN;
    int minNo = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        maxNo = max(maxNo, arr[i]);
        minNo = min(minNo, arr[i]);
    }
    pair<int ,int> p;
    p.first = maxNo;
    p.second = minNo;
    return p;
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
    pair<int ,int> res;
    res = max_min(arr, n);
    cout<<res.first<<" "<<res.second;
    return 0;
}