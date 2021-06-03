#include<bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int arr[], int n)
{

	int mat[n][n];

	int i, j, k, L, q;

	for (i = 1; i < n; i++)
		mat[i][i] = 0;

	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			mat[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				q = mat[i][k] + mat[k + 1][j]
					+ arr[i - 1] * arr[k] * arr[j];
				if (q < mat[i][j])
					mat[i][j] = q;
			}
		}
	}

	return mat[1][n - 1];
}

int main()
{
	int n;
    cin>>n;
    int arr[n+1];
    for (int i = 0; i < n+1; i++)
    {
        cin>>arr[i];
    }
    cout<<matrixChainMultiplication(arr,n+1);
    return 0; 
}