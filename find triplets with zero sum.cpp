#include<bits/stdc++.h>
using namespace std;

void find_0_Triplets(int arr[], int n)
{
	bool ans = false;

	sort(arr, arr+n);

	for (int i=0; i<n-1; i++)
	{
		int left = i + 1;
		int right = n - 1;
		while (left < right)
		{
			if (arr[i] + arr[left] + arr[right] == 0)
			{
				cout<<arr[i]<<" "<<arr[left]<<" "<<arr[right]<<endl;
				left++;
				right--;
				ans = true;
				break;
			}

			else if (arr[i] + arr[left] + arr[right] < 0)
				left++;

			else
				right--;
		}
	}

	if (ans == false)
		cout <<"-1"<< endl;
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
    
	find_0_Triplets(arr, n);
	return 0;
}
