bool checkPrime(int n)
{
    if(n<=1) return false;

    for(int i = 2; i<=(int)sqrt(n);i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}
vector<int> Solution::primesum(int A) {
    vector<int> v;
    if(A<=3)
    {
        return v;
    }
    for(int i=2; i<A;i++)
    {
        if(checkPrime(i) && checkPrime(A-i))
        {
            v.push_back(i);
            v.push_back(A-i);
            break;
        }
    }
    return v;
}
