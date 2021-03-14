#include <iostream>
using namespace std;

//Top down approach is recursion + memoisation

int fib(int n, int dp[])		// O(n) time and space
{
	if(n==0 or n==1)
		return dp[n]=n;

	if(dp[n]>0)
		return dp[n];

	return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}


int fibTD(int n)
{
	const int k = n+1;
	int dp[k]={0};
	return fib(n,dp);
}

int main()
{
	int n;
//	cin>>n;
	n=6;

	cout<<fibTD(n)<<endl;
	return 0;
}