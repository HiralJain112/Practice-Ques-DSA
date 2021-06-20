//max sum with no adjacent elements

int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int exclude = 0;
        int include = arr[0];
        for(int i = 1; i < n; i++)
        {
            int temp = include;
            include = max(max(exclude +arr[i] , arr[i]), include);
            exclude = temp;
        }
        return include;
    }
