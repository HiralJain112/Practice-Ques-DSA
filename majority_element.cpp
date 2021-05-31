#include <bits/stdc++.h>
using namespace std;

void findMajority(int arr[], int size)
{
	unordered_map<int, int> m;
	for(int i = 0; i < size; i++)
		m[arr[i]]++;
	int count = 0;
	for(auto i : m)
	{
		if(i.second > size / 2)
		{
			count =1;
			cout << i.first<<endl;
			break;
		}
	}
	if(count == 0)
		cout << "-1" << endl;
}

// Driver code
int main()
{
	int arr[] = {8,8,8,8,8,10,10};
	int n = sizeof(arr) / sizeof(int);
	
	// Function calling
	findMajority(arr, n);

	return 0;
}

