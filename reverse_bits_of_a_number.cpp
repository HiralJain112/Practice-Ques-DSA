#include<bits/stdc++.h>
using namespace std;

int reverseBits(int num)
{
    int reverse_num = 0;
    while(num > 0)
    {
        reverse_num <<= 1;
        if (num & 1 == 1)
        {
            reverse_num ^= 1;
        }
        num >>= 1;
    }
    return reverse_num;
}
int main()
{
    int num;
    cin>>num;
    cout<<reverseBits(num);
    return 0;
}