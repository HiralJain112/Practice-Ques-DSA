#include<bits/stdc++.h>
using namespace std;

int min_steps(int arr[], int n)
{
	if (n <= 1)
		return 0;

	if (arr[0] == 0)
		return -1;

	int jump = 1;

	// Stores the subarray last index
	int subArrEndIndex = arr[0];

	int i = 1;

	// Maximum steps covers in
	// first half of sub array
	int subArrFistHalfMaxSteps = 0;

	// Maximum steps covers
	// in second half of sub array
	int subArrSecondHalfMaxSteps = 0;

	// Start traversing array
	for (i = 1; i < n;) {

		subArrEndIndex = i + subArrEndIndex;
	
		// Check if we have reached
		// the end of the array
		if (subArrEndIndex >= n)
			return jump;

		int firstHalfMaxStepIndex = 0;
	
		// Iterate the sub array
		// and find out the maxsteps
		// cover index
		for (; i < subArrEndIndex; i++) {
			int stepsCanCover = arr[i] + i;
			if (subArrFistHalfMaxSteps < stepsCanCover) {
				subArrFistHalfMaxSteps = stepsCanCover;
				subArrSecondHalfMaxSteps = 0;
				firstHalfMaxStepIndex = i;
			}
			else if (subArrSecondHalfMaxSteps
					< stepsCanCover) {
				subArrSecondHalfMaxSteps = stepsCanCover;
			}
		}
		if (i > subArrFistHalfMaxSteps)
			return -1;
		jump++;
	
		// Next subarray end index
		// and so far calculated sub
		// array max step cover value
		subArrEndIndex = arr[firstHalfMaxStepIndex];
		subArrFistHalfMaxSteps = subArrSecondHalfMaxSteps;
	}

	return -1;
    
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
    cout<<min_steps(arr,n);
    return 0; 
}