#include<bits/stdc++.h>
using namespace std;

void set_matrix_zeros(int arr[][], int r, int c)
{
     bool r_flag = false;
     bool c_flag = false;

     for (int i = 0; i < r; i++)
     {
         for (int j = 0; j < c; j++)
         {
             if (i==0 && arr[i][j] == 0)
             {
                 r_flag = true;
             }
             if (j==0 && arr[i][j] == 0)
             {
                 c_flag = true;
             }
             if (arr[i][j] == 0)
             {
                 arr[0][j] = 0;
                 arr[i][0] = 0;
             }   
         }    
     }
     
     for (int i = 1; i < r; i++)
     {
         for (int j = 0; j < c; j++)
         {
             if (arr[0][j]==0 || arr[i][0]==0)
             {
                 arr[i][j] = 0;
             }
             
         }
         
     }
     
     if (r_flag)
     {
         for (int j = 0; j < c; j++)
         {
             arr[0][j] = 0;
         }
     }
     if (c_flag)
     {
         for (int i = 0; i < r; i++)
         {
             arr[i][0] = 0;
         }
     }
}
int main()
{
    int r,c;
    cin>>r>>c;
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>arr[i][j];
        }
    }
    set_matrix_zeros(arr,r,c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}