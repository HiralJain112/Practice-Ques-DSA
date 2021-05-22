#include<bits/stdc++.h>
using namespace std;

int intSqrt(int num) {
        // write your awesome code here
        int i;
        for( i=1 ;i<=(num/2) ; i++)
        {
            if(i*i >= num)
            {
                break;
            }
        }
        if(i*i == num)
        {
            return i;
        }
        return --i;
    }

int main()
{
    int n;
    cin>>n;
    cout<<intSqrt(n);
    return 0;
}