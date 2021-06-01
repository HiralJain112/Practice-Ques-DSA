#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}
int countWays(int n)
{
	return fib(n + 1);
}

int main()
{
	int n;
    cin>>n;
	cout << countWays(n);
	return 0;
}


