int Solution::isPower(int A) {
    if(A <= 1)
        return 1;
    float p;
    for(int i =2; i<=sqrt(A); i++)
    {
        p = log2(A)/log2(i);
        if(ceil(p) == floor(p) && p>1)
        {
            return 1;
        }
    }
    return 0;
}
