int Solution::isPalindrome(int A) {
    if(A<0) return 0;
    int n = A;
    int digit,rev=0;
    do{
        digit = n%10;
        rev = (rev*10) + digit;
        n /=10;
    }while(n!=0);
    if(rev == A)
    {
        return 1;
    }
    return 0;
}
