#include<bits/stdc++.h>
using namespace std;

int countTrapping_wt(int arr[], int n)
{
  int low = 0, high = n - 1;
  int leftMax = 0, rightMax = 0;
  int trappedWater = 0;
  while (low < high) 
  {  
    if (arr[low] > leftMax)  
        leftMax = arr[low];
    if (arr[high] > rightMax) 
        rightMax = arr[high];
    
    if (leftMax < rightMax) 
    {     
        trappedWater += (leftMax - arr[low]);
        low++;
    } 
    else 
    {
        trappedWater += (rightMax - arr[high]);
        high--;
    }
  }
  return trappedWater;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i<n; i++)
    {
         cin>>arr[i];
    }
    cout<<countTrapping_wt(arr,n);
    return 0;
}