#include <bits/stdc++.h>
using namespace std;

int areEqual(int arr1[], int arr2[], int n)
{
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[arr1[i]]++;


	for (int i = 0; i < n; i++) {
		if (mp.find(arr2[i]) == mp.end())
			return 0;
		if (mp[arr2[i]] == 0)
			return 0;
		mp[arr2[i]]--;
	}

	return 1;
}

int main()
{
	int arr1[] = { 3, 8, 9, 1};
	int arr2[] = { 9, 3, 8, 1};
	int n = sizeof(arr1) / sizeof(int);
	cout<<areEqual(arr1, arr2, n);
		
	return 0;
}
