#include <bits/stdc++.h>
using namespace std;

int LAP(int arr[], int n)
{
	int ans = 2;
	if (n <= 2)
		return n;

	vector<int> llap(n, 2);

	sort(arr,arr+n);

	for (int j = n - 2; j >= 0; j--)
	{
		int i = j - 1;
		int k = j + 1;
		while (i >= 0 && k < n)
		{
			if (arr[i] + arr[k] == 2 * arr[j])
			{
				llap[j] = max(llap[k] + 1, llap[j]);
				ans = max(ans, llap[j]);
				i -= 1;
				k += 1;
			}
			else if (arr[i] + arr[k] < 2 * arr[j])
				k += 1;
			else
				i -= 1;
		}
	}
	return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<LAP(arr,n);
    return 0;
}