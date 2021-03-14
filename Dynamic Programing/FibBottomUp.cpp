#include <iostream>
using namespace std;

//Bottom up approach is iterative in nature

int fib(int n, int dp[])		// O(n) time and space
{
	dp[1]++;

	for(int i=2; i<=n; i++)
		dp[i] = dp[i-1] + dp[i-2];

	return dp[n];
}


int fibBU(int n)
{
	const int k = n+1;
	int dp[k]={0};
	return fib(n,dp);
}

int main()
{
	int n;
//	cin>>n;
	n=12;

	cout<<fibBU(n)<<endl;
	return 0;
}