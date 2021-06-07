string Solution::findDigitsInBinary(int A) {
    if(A==0) return "0";
    string str = "";
    while(A>0)
    {
        int rem = A%2;
        str.append(to_string(rem));
        A/=2;
    }
    reverse(str.begin(),str.end());
    return str;
}
