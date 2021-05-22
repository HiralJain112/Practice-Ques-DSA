#include<bits/stdc++.h>
using namespace std;

int romanToInteger(string str)
{
    map<char, int> val = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (val[str[i]] >= val[str[i+1]])
        {
            sum += val[str[i]] ;
        }
        else
        {
            sum -= val[str[i]];
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