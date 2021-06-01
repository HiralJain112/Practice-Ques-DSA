#include <bits/stdc++.h>
using namespace std;

int first_unique_character(string str)
{
	unordered_map<int, int> freq;

    for (char ch : str)
    {
        freq[ch]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (freq[str[i]] == 1)
        {
            return i;
        }
        
    }
    return -1;
}

int main()
{
	string str ;
    cin>>str;
    cout<<first_unique_character(str);
	return 0;
}
