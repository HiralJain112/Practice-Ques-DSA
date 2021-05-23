//program to rotate a square matrix by 90 degrees in clockwise direction
#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(int arr[][] ,int n)
{
     for (int i = 0; i < n/2; i++)
     {
         for (int j = i; j < n-i-1; j++)
         {
             int temp = arr[i][j];
             arr[i][j] = arr[n-j-1][i];
             arr[n-j-1][i] = arr[n-i-1][n-j-1];
             arr[n-i-1][n-j-1] = arr[j][n-i-1];
             arr[j][n-i-1] = temp;
         } 
     }
}

int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }
    rotateMatrix(arr,n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}