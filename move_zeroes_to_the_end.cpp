#include<bits/stdc++.h>
using namespace std;

void move_zeroes_to_the_end(int arr[], int n)
{
    int count_nz = 0;
   for (int i = 0; i < n; i++)
   {
       if (arr[i] != 0)
       {
           arr[count_nz++] = arr[i];
       }
       
   }
   
   while (count_nz < n)
   {
       arr[count_nz++] = 0;
   }
   
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
    move_zeroes_to_the_end(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}