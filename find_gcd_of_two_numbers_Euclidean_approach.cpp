#include<bits/stdc++.h>
using namespace std;

int GCD(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    return GCD(num2 , num1 % num2);
}

int main()
{
    int num1,num2;
    cin>>num1>>num2;

    cout<<GCD(num1, num2);
    return 0;
}