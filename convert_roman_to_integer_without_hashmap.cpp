#include<bits/stdc++.h>
using namespace std;

int actual_val(char c)
{
    if(c =='I')
    {
        return 1;
    }else if(c == 'V')
    {
        return 5;
    }else if(c == 'X')
    {
        return 10;
    }else if(c == 'L')
    {
        return 50;
    }else if(c == 'C')
    {
        return 100;
    }else if(c == 'D')
    {
        return 500;
    }else if(c == 'M')
    {
        return 1000;
    }
    return -1;    
}

int romanToInteger(string str)
{
   int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (actual_val(str[i]) >= actual_val(str[i+1]))
        {
            sum += actual_val(str[i]) ;
        }
        else
        {
            sum -= actual_val(str[i]);
        }
    }
    return sum;
}
int main()
{
    string str;
    cin>>str;
    cout<<romanToInteger(str);
    return 0;
}