#include <bits/stdc++.h>
using namespace std;

#define NO_OF_CHARS 26

bool areAnagram(char* str1, char* str2)
{
	int count[NO_OF_CHARS] = { 0 };
	int i;

	for (i = 0; str1[i] && str2[i]; i++) {
		count[str1[i]]++;
		count[str2[i]]--;
	}
    if (str1[i]||str2[i])
    {
        return false;
    }
    
	for (i = 0; i < NO_OF_CHARS; i++)
		if (count[i])
			return false;

	return true;
}

// Driver code
int main()
{
	char str1[] = "admirer";
	char str2[] = "married";
	
	if(areAnagram(str1, str2))
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    
	return 0;
}
