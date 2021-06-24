#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,S;
    cin>>n>>S;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int i = 0, j = 0, start = -1, end = -1;
    int sum = 0;

    while (j<n && sum+arr[j] <= S)
    {
        sum += arr[j];
        j++;
    }
    
    if (sum == S)
    {
        cout<< i+1<<" "<<j<<endl;
        return 0;
    }
    
    while (j<n)
    {
       sum += arr[j];
       while (sum > S)
       {
           sum -= arr[i];
           i++;
       }
       if (sum == S)
       {
           start = i+1;
           end = j+1;
           break;
       }
       j++;
    }
    cout<<start<<" "<<end;
    return 0;
}