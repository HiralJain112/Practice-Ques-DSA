vector<int> Solution::sieve(int A) {
    vector<int> v;
    vector<bool>Prime(A+1,true);
    Prime[0] = false;
    Prime[1] = false;
    
    for(int i = 2; i<=(int)sqrt(A); i++)
    {
        if(Prime[i] == true)
        {
            for(int j = i*i; j<= A; i++)
            {
                Prime[i*j] = false;
            }
        }
    }
    for(int i =2;i<=A;i++)
    {
        if(Prime[i])
        {
            v.push_back(i);
        }
    }
    return v;
}
