#include<bits/stdc++.h>
using namespace std;

int ascendingBS(int arr[],int low,int high, int k)
{
    while(low <= high)
    {
        int mid = (low +high)/2 ;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1 ; 
        }
    }
    return -1;
}
int descendingBS(int arr[],int low,int high, int k)
{
    while(low <= high)
    {
        int mid = (low +high)/2 ;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1 ; 
        }
    }
    return -1;
}


int findBiotonicIdx(int arr[],int n,int low,int high)
{
   int bp = -1;
   int mid = (low + high)/2 ;
   if (arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
   {
        bp = mid;
   }
   else if (arr[mid] < arr[mid+1] && arr[mid] > arr[mid-1])
   {
       bp = findBiotonicIdx(arr,n,mid,high);
   }
   else if (arr[mid] > arr[mid+1] && arr[mid] < arr[mid-1])
   {
       bp = findBiotonicIdx(arr,n,low,mid);
   }
   
   return bp;
}

int searchBiotonic(int arr[],int n,int k,int index)
{
    if (k > arr[index] )
    {
        return -1;
    }
    else if (k == arr[index])
    {
        return index;
    }
    else
    {
        int i = ascendingBS(arr,0,index-1,k);

        if (i != -1)
        {
            return i;
        }
        return descendingBS(arr,index+1,n-1,k);
    }
}

int main()
{
    int n,k;
    cin>>n>>k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int low = 0, high = n-1;
    int index = findBiotonicIdx(arr,n,low,high); 
    cout<<searchBiotonic(arr,n,k,index);
    return 0;
}
