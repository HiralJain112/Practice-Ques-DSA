int Solution::solve(vector<int> &A, int B) {
    int i = 0;
    int j = 1;
    int n = A.size();
    sort(A.begin(), A.end());
    while (i < n && j < n)
    {
        if (i != j && A[j] - A[i] == B)
        {
            return 1;
        }
        else if (A[j]-A[i] < B)
            j++;
        else
            i++;
    }

    return 0;
}
