int Solution::solve(int A, int B, int C) {

   int pos = C + A%B -1;
   if(pos> B)
   {
       return pos%B;
    }
    
    if(pos==0)
    {
        return B;
    }
    return pos;
}
